//DSPE_2011706153_¿ÃªÛ¡ÿ_10

#include "func.h"

void main() {
	FILE* fp_in = fopen("Suzie_CIF_150_30.rgb", "rb");
	FILE* fp_cpy_out = fopen("[Copy]Suzie_CIF.rgb", "wb");
	FILE* fp_sub_out = fopen("[Sub]Suzie_CIF.rgb", "wb");
	FILE* fp_avr_out = fopen("[Avg]Suzie_CIF.rgb", "wb");

	uchar** img_in;
	uchar** img_out;
	uchar** img_prev;

	int read_size = 1;
	int first_frame = 1;

	img_in = MemAlloc_2D(WIDTH, HEIGHT * 3);
	img_out = MemAlloc_2D(WIDTH, HEIGHT * 3);
	img_prev = MemAlloc_2D(WIDTH, HEIGHT * 3);

	while (read_size = Read_Frame(fp_in, img_in, WIDTH, HEIGHT * 3)) {
		Cpy_Frame(img_in, img_out, WIDTH, HEIGHT * 3);
		Write_Frame(fp_cpy_out, img_out, WIDTH, HEIGHT * 3);

		Average_RGB(img_in, img_out, WIDTH, HEIGHT);
		Write_Frame(fp_avr_out, img_out, WIDTH, HEIGHT * 3);
		
		
		if (first_frame != 1) {
			Sub_Frame(img_in, img_prev, img_out, WIDTH, HEIGHT * 3);
		}

		Cpy_Frame(img_in, img_prev, WIDTH, HEIGHT * 3);

		if (first_frame != 1) { 
			Write_Frame(fp_sub_out, img_out, WIDTH, HEIGHT * 3); 
		}
		first_frame++;
	}

	MemFree_2D(img_in, HEIGHT * 3);
	MemFree_2D(img_out, HEIGHT * 3);
	MemFree_2D(img_prev, HEIGHT * 3);

	fclose(fp_in);
	fclose(fp_cpy_out);
	fclose(fp_sub_out);
	fclose(fp_avr_out);
}