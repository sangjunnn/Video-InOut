//DSPE_2011706153_이상준_10

#ifndef DSPE_2011706153_이상준_10
#define DSPE_2011706153_이상준_10

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH (352)
#define HEIGHT (288)

typedef unsigned char uchar;

uchar** MemAlloc_2D(int width, int height);
void MemFree_2D(uchar** pic, int height);

int Read_Frame(FILE* fp_in, uchar** img_in, int width, int height);
void Write_Frame(FILE* fp_out, uchar** img_in, int width, int height);

void Average_RGB(uchar** img_in, uchar** img_ave, int width, int height);

void Cpy_Frame(uchar** img_src, uchar** img_dst, int width, int height);
void Sub_Frame(uchar** img_in, uchar** img_prev, uchar** img_out, int width, int height);

#endif // !DSPE_2011706153_이상준_10

