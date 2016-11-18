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
}//2차원 동적 메모리 해제

int Read_Frame(FILE* fp_in, uchar** img_in, int width, int height) {
	int size = 0;

	for (int i = 0; i < height; i++) {
		size += fread(img_in[i], sizeof(uchar), width, fp_in);
	}//프레임을 하나 읽을때 마다 size가 커지게 됨 
	return size;
}//size값 반환

void Write_Frame(FILE* fp_out, uchar** img_in, int width, int height) {
	for (int i = 0; i < height; i++) {
		fwrite(img_in[i], sizeof(uchar), width, fp_out);
	}
}//프레임 쓰기

void Average_RGB(uchar** img_in, uchar** img_ave, int width, int height) {
	//height를 HEIGHT까지만 돌게하기
	int temp = 0;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = img_in[i][j] + img_in[i+HEIGHT][j] + img_in[i+2*HEIGHT][j];
			img_ave[i][j] = temp / 3;
			img_ave[i+HEIGHT][j] = temp / 3;
			img_ave[i+2*HEIGHT][j] = temp / 3;
		}
	}
}//평균값을 구해서 파일 출력

void Cpy_Frame(uchar** img_src, uchar** img_dst, int width, int height) {
	for (int i = 0; i < height; i++) {
		memcpy(img_dst[i], img_src[i], sizeof(uchar)*width);
	}
}//파일을 복사함

void Sub_Frame(uchar** img_in, uchar** img_prev, uchar** img_out, int width, int height) {
	//height를 3*HEIGHT까지 돌게 하기
	int temp;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = img_in[i][j] - img_prev[i][j];
			img_out[i][j] = temp + 128;
		}//이전 프레임과 현재 프레임의 차이를 구함
	}//offset으로 128을 더해줌
}