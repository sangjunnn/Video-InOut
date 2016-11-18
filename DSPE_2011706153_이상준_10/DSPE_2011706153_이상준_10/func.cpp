//DSPE_2011706153_이상준_10

#include "func.h"

uchar** MemAlloc_2D(int width, int height){
	uchar** pic;

	pic = (uchar**)malloc(sizeof(uchar*)*height);
	for (int i = 0; i < height; i++) {
		pic[i] = (uchar*)malloc(sizeof(uchar)*width);
	}

	if (pic == NULL) {
		printf("wrong allocation");
		return 0;
	}
	return pic;
}// unsigned char형 동적 할당

void MemFree_2D(uchar** pic, int height) {
	for (int i = 0; i < height; i++) {
		free(pic[i]);
	}
	free(pic);
}

int Read_Frame(FILE* fp_in, uchar** img_in, int width, int height) {
	int size = 0;

	for (int i = 0; i < height; i++) {
		size += fread(img_in[i], sizeof(uchar), width, fp_in);
	}
	return size;
}

void Write_Frame(FILE* fp_out, uchar** img_in, int width, int height) {
	for (int i = 0; i < height; i++) {
		fwrite(img_in[i], sizeof(uchar), width, fp_out);
	}
}

void Average_RGB(uchar** img_in, uchar** img_ave, int width, int height) {

}

void Cpy_Frame(uchar** img_src, uchar** img_dst, int width, int height) {
	for (int i = 0; i < height; i++) {
		memcpy(img_dst[i], img_src[i], sizeof(uchar)*width);
	}
}
void Sub_Frame(uchar** img_in, uchar** img_prev, uchar** img_out, int width, int height) {

}