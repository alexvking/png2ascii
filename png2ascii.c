//
//  png2ascii.c
//  png2ascii
//
//  Created by Alex King on 8/15/15.
//  Copyright © 2015 Alex King. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "lodepng.h"

#define NUM_ART_CHARS 10

/* Converts specified PNG file and returns a pointer to converted ASCII image */
unsigned char* png_to_ascii(const char* filename, unsigned* input_width,
                            unsigned* input_height)
{
    unsigned char *image, *output;
    unsigned width, height, error;
    float brightness;
    char *art_chars;
    int x, index;
    
    /* Sets image as buffer with pattern RGBARGBARGBA */
    error = lodepng_decode32_file(&image, &width, &height, filename);
    
    if (error) {
        printf("PNG decoder error %u: %s\n", error, lodepng_error_text(error));
        printf("Error opening specified file. Exiting...\n");
        exit(1);
    }
    output = malloc(width * height * sizeof(char));
    art_chars = "@%#*+=-:. ";
    *input_width = width;
    *input_height = height;
    
    for (x = 0; x < (width * height * 4); x+=4) {
        /* Compute relative luminance of RGB value */
        brightness = (0.2126*image[x] +
                       0.7152*image[x + 1] +
                       0.0722*image[x + 2]) / 255;
        /* Set pixel in output to be nearest ASCII character to brightness. 
           If alpha channel is transparent, set pixel as whitespace */
        index = (image[x + 3] ? brightness * (NUM_ART_CHARS - 1) : 9);
        output[x/4] = art_chars[index];
    }
    free(image);
    return output;
}

/* Outputs converted image as plain text to the terminal */
void print_ascii_image(unsigned char* output, int width, int height)
{
    char buffer[(2 * width) + 1];
    int x, y;
    for (y = 0; y < (height * width); y += width) {
        /* Only call printf once per row, cutting runtime by two thirds */
        for (x = 0; x < width; x++) {
            buffer[2 * x] = output[y + x];
            buffer[(2 * x) + 1] = ' ';
        }
        buffer[2 * width] = '\0';
        printf("%s\n", buffer);
    }
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: png2ascii filename.png\n");
        exit(1);
    }
    unsigned width, height;
    unsigned char *output = png_to_ascii(argv[1], &width, &height);
    print_ascii_image(output, width, height);
    free(output);
    return 0;
}