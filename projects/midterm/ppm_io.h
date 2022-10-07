#ifndef PPM_IO_H
#define PPM_IO_H

#include <stdio.h>
#include <stdlib.h>

/* struct to store a point */
typedef struct _point {
  int x;
  int y;
} Point;

/* struct to store an RGB pixel, one byte per channel */
typedef struct _pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

/* struct to store an entire image */
typedef struct _image {
  Pixel *data;
  int rows;
  int cols;
} Image;


/* read PPM formatted image from a file (assumes fp != NULL) */
Image * read_ppm(FILE *fp);


/* Write given image to disk as a PPM.
 * Return -1 if any failure occurs, otherwise return the number of pixels written.
 */
int write_ppm(FILE* fp, const Image* img);


/* utility function to free inner and outer pointers,
 * and set to null
 */
void free_image(Image **im);


/* allocate a new image of the specified size;
 * doesn't initialize pixel values */
Image * make_image(int rows, int cols);


/* allocate and fill a new image to be a copy
 * of the image given as a parameter */
Image * make_copy(Image *orig);


/* output dimensions of the image to stdout */
void output_dims(Image *orig);

/* resize an image */
int resize_image(Image **im, int rows, int cols);


#endif
