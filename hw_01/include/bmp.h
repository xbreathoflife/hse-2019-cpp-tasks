#ifndef BMP_H_
#define BMP_H_
typedef struct BITMAPINFOHEADER {
    uint16_t Type;
    uint32_t Size; 
    uint16_t Reserved1; 
    uint16_t Reserved2; 
    uint32_t OffBits; 
} BITMAPINFOHEADER;

typedef struct BMP {
    BITMAPINFOHEADER Header;
    uint32_t Size; 
    uint32_t W, H; 
    uint16_t Planes;
    uint16_t BitCount;
    uint32_t Compression;
    uint32_t SizeImage;
    uint32_t XPelsPerMeter;
    uint32_t YPelsPerMeter;
    uint32_t CrlUsed;
    uint32_t CrlImportant;
} BMP;


uint32_t **load_bmp(char *fname, BMP *image);
uint32_t **crop(uint32_t **source_pixels, uint32_t x, uint32_t y, uint32_t w, uint32_t h);
uint32_t **rotate(uint32_t **cropped_pixels, uint32_t w, uint32_t h);
int save_bmp(BMP *image, uint32_t **pixels, uint32_t w, uint32_t h, char *fname);
#endif
