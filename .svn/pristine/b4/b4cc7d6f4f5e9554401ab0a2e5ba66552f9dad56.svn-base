#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "bmp.h"

int main(int argc, char *argv[]) {
	if (argc != 8)
		return -1;
	if (strcmp(argv[1], "crop-rotate"))
		return -1;
	BMP image;
	uint32_t **source_pixels, **cropped_pixels, **rotated_pixels;

	uint32_t x = atol(argv[4]);
	uint32_t y = atol(argv[5]);
	uint32_t w = atol(argv[6]);
	uint32_t h = atol(argv[7]);

	source_pixels = load_bmp(argv[2], &image);
	if (source_pixels == NULL)
		return -1;
	if (!(x + w <= image.W) || !(y + h <= image.H)) {
		for (uint32_t i = 0; i < image.H; i++)
			free(source_pixels[i]);
		free(source_pixels);
		return -1;
	} 
	cropped_pixels = crop(source_pixels, x, y, w, h);
	
	for (uint32_t i = 0; i < image.H; i++)
		free(source_pixels[i]);
	free(source_pixels);

	if (cropped_pixels == NULL)
		return -1;

	rotated_pixels = rotate(cropped_pixels, w, h);

	for (uint32_t i = 0; i < h; i++)
		free(cropped_pixels[i]);
	free(cropped_pixels);

	if (rotated_pixels == NULL)
		return -1;

	if(save_bmp(&image, rotated_pixels, h, w, argv[3])) {
		for (uint32_t i = 0; i < w; i++)
			free(rotated_pixels[i]);
		free(rotated_pixels);
		return -1;
	}

	for (uint32_t i = 0; i < w; i++)
		free(rotated_pixels[i]);
	free(rotated_pixels);

	return 0;
}
