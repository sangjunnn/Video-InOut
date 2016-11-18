//DSPE_2011706153_�̻���_10

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
}// unsigned char�� ���� �Ҵ�

void MemFree_2D(uchar** pic, int height) {
	for (int i = 0; i < height; i++) {
		free(pic[i]);
	}
	free(pic);
}//2���� ���� �޸� ����

int Read_Frame(FILE* fp_in, uchar** img_in, int width, int height) {
	int size = 0;

	for (int i = 0; i < height; i++) {
		size += fread(img_in[i], sizeof(uchar), width, fp_in);
	}//�������� �ϳ� ������ ���� size�� Ŀ���� �� 
	return size;
}//size�� ��ȯ

void Write_Frame(FILE* fp_out, uchar** img_in, int width, int height) {
	for (int i = 0; i < height; i++) {
		fwrite(img_in[i], sizeof(uchar), width, fp_out);
	}
}//������ ����

void Average_RGB(uchar** img_in, uchar** img_ave, int width, int height) {
	//height�� HEIGHT������ �����ϱ�
	int temp = 0;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = img_in[i][j] + img_in[i+HEIGHT][j] + img_in[i+2*HEIGHT][j];
			img_ave[i][j] = temp / 3;
			img_ave[i+HEIGHT][j] = temp / 3;
			img_ave[i+2*HEIGHT][j] = temp / 3;
		}
	}
}//��հ��� ���ؼ� ���� ���

void Cpy_Frame(uchar** img_src, uchar** img_dst, int width, int height) {
	for (int i = 0; i < height; i++) {
		memcpy(img_dst[i], img_src[i], sizeof(uchar)*width);
	}
}//������ ������

void Sub_Frame(uchar** img_in, uchar** img_prev, uchar** img_out, int width, int height) {
	//height�� 3*HEIGHT���� ���� �ϱ�
	int temp;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = img_in[i][j] - img_prev[i][j];
			img_out[i][j] = temp + 128;
		}//���� �����Ӱ� ���� �������� ���̸� ����
	}//offset���� 128�� ������
}