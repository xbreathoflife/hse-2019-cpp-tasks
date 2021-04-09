#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bmp.h"

static uint32_t read_4_bytes(FILE *fin) {
    unsigned char buffer[4];
    fread(buffer, 1, 4, fin);
    return (((((buffer[3] << 8) | buffer[2]) << 8) | buffer[1]) << 8) | buffer[0];
}   


static uint32_t read_3_bytes(FILE *fin) {
    unsigned char buffer[3];
    fread(buffer, 1, 3, fin);
    return (((buffer[2] << 8) | buffer[1]) << 8) | buffer[0];
} 

static uint16_t read_2_bytes(FILE *fin) {
    unsigned char buffer[2];
    fread(buffer, 1, 2, fin);
    return (buffer[1] << 8) | buffer[0];
}


static uint8_t read_1_byte(FILE *fin) {
    unsigned char buffer[1];
    fread(buffer, 1, 1, fin);
    return buffer[0];
}

static void write_4_bytes(FILE *fout, uint32_t x) {
    unsigned char buffer[4];
    buffer[0] = x & 255;
    buffer[1] = (x >> 8) & 255;
    buffer[2] = (x >> 16) & 255;
    buffer[3] = (x >> 24) & 255;
    fwrite(buffer, 1, 4, fout);
}


static void write_3_bytes(FILE *fout, uint32_t x) {
    unsigned char buffer[3];
    buffer[0] = x & 255;
    buffer[1] = (x >> 8) & 255;
    buffer[2] = (x >> 16) & 255;
    fwrite(buffer, 1, 3, fout);
}

static void write_2_bytes(FILE *fout, uint16_t x) {
    unsigned char buffer[2];
    buffer[0] = x & 255;
    buffer[1] = (x >> 8) & 255;
    fwrite(buffer, 1, 2, fout);
}

uint32_t **load_bmp(char *fname, BMP *image) {
    FILE *fin = fopen(fname, "rb");
    if (fin == NULL)
        return NULL;

    image->Header.Type = read_2_bytes(fin);
    image->Header.Size = read_4_bytes(fin);
    image->Header.Reserved1 = read_2_bytes(fin);
    image->Header.Reserved2 = read_2_bytes(fin);
    image->Header.OffBits = read_4_bytes(fin);
    image->Size = read_4_bytes(fin);
    image->W = read_4_bytes(fin);
    image->H = read_4_bytes(fin);
    image->Planes = read_2_bytes(fin);
    image->BitCount = read_2_bytes(fin);
    image->Compression = read_4_bytes(fin);
    image->SizeImage = read_4_bytes(fin);
    image->XPelsPerMeter = read_4_bytes(fin);
    image->YPelsPerMeter = read_4_bytes(fin);
    image->CrlUsed = read_4_bytes(fin);
    image->CrlImportant = read_4_bytes(fin);

    uint32_t W = image->W * 3;
    int offset = 0, tmp;
    while ((W + offset) % 4 != 0)
        offset++;
    uint32_t **source_pixels = (uint32_t **)malloc(image->H * sizeof(uint32_t *));
    if (source_pixels == NULL)
        return NULL;
    for (uint32_t i = 0; i < image->H; i++) {
        source_pixels[i] = (uint32_t *)malloc(W * sizeof(uint32_t) + offset);
        if (source_pixels[i] == NULL)
            return NULL;
    }
    for (uint32_t y = image->H; y-- > 0; ) {
        for (uint32_t x = 0; x < image->W; x++) {
            source_pixels[y][x] = read_3_bytes(fin);
        }
        if (offset == 3)
            tmp = read_3_bytes(fin);
        else if (offset == 2)
            tmp = read_2_bytes(fin);
        else if (offset == 1)
            tmp = read_1_byte(fin);
        (void)tmp;
    }

    fclose(fin);
    return source_pixels;
}

uint32_t **crop(uint32_t **source_pixels, uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
    uint32_t **cropped_pixels = (uint32_t **)malloc(h * sizeof(uint32_t *));
    if (cropped_pixels == NULL)
        return NULL;
    for (uint32_t i = 0; i < h; i++) {
        cropped_pixels[i] = (uint32_t *)malloc(w * sizeof(uint32_t));
        if (cropped_pixels[i] == NULL)
            return NULL;
    }
    for (uint32_t i = 0; i < h; i++)
        for (uint32_t j = 0; j < w; j++)
            cropped_pixels[i][j] = source_pixels[i + y][j + x];
    
    return cropped_pixels;
}

uint32_t **rotate(uint32_t **cropped_pixels, uint32_t w, uint32_t h) {
    uint32_t **rotated_pixels = (uint32_t **)malloc(w * sizeof(uint32_t *));
    if (rotated_pixels == NULL)
        return NULL;
    for (uint32_t i = 0; i < w; i++) {
        rotated_pixels[i] = (uint32_t *)malloc(h * sizeof(uint32_t));
        if (rotated_pixels[i] == NULL)
            return NULL;
    }
    for (uint32_t i = 0; i < w; i++)
        for (uint32_t j = h; j-- > 0; )
            rotated_pixels[i][j] = cropped_pixels[h - 1 - j][i];

    return rotated_pixels;
}

int save_bmp(BMP *image, uint32_t **pixels, uint32_t w, uint32_t h, char *fname) {
    FILE *fout = fopen(fname, "wb");
    if (fout == NULL)
        return 1;

    int offset = 0;
    while ((w * 3 + offset) % 4 != 0)
        offset++;
    
    image->Header.Size = 54 + (3 * w + offset) * h; 
    image->W = w;
    image->H = h;
    image->SizeImage = (3 * image->W + offset) * image->H;

    write_2_bytes(fout, image->Header.Type);
    write_4_bytes(fout, image->Header.Size);
    write_2_bytes(fout, image->Header.Reserved1);
    write_2_bytes(fout, image->Header.Reserved2);
    write_4_bytes(fout, image->Header.OffBits);

    write_4_bytes(fout, image->Size);
    write_4_bytes(fout, image->W);
    write_4_bytes(fout, image->H);
    write_2_bytes(fout, image->Planes);
    write_2_bytes(fout, image->BitCount);
    write_4_bytes(fout, image->Compression);
    write_4_bytes(fout, image->SizeImage);
    write_4_bytes(fout, image->XPelsPerMeter);
    write_4_bytes(fout, image->YPelsPerMeter);
    write_4_bytes(fout, image->CrlUsed);
    write_4_bytes(fout, image->CrlImportant);

    unsigned char buffer[1] = {0};

    for (uint32_t y = h; y-- > 0; ) {
        for (uint32_t x = 0; x < w; x++)
            write_3_bytes(fout, pixels[y][x]);
        for (int i = 0; i < offset; i++)
            fwrite(buffer, 1, 1, fout);
    }
    fclose(fout);
    return 0;
}