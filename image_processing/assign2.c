#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define WIDTH 256
#define HEIGHT 256

void findsadblock(unsigned char *buffer1, unsigned char *buffer2, int width, int height, int *ptrSad);
int findSadFrame(int *ptrSad, unsigned char *buffer1, unsigned char *buffer2, int width, int height);
int main()
{
	unsigned char buffer1[256][256], buffer2[256][256];
	int ptrSad[16];
	FILE *infp1, *infp2; 
	int k;
	


	infp1 = fopen("D:\\code\\assignment2\\image1.raw", "rb"); // open the input file in read mode
	infp2 = fopen("D:\\code\\assignment2\\image2.raw", "rb");

	if (infp1 == NULL || infp2 == NULL)
	{
		printf("\n Error in Opening File \n");
	}
	else
	{
		fread(buffer1, 1, 256 * 256, infp1); // read the content of the file into buffer
		fread(buffer2, 1, 256 * 256, infp2);
	}


	//findsadblock((unsigned char*)buffer1, (unsigned char*)buffer2, 256, 256, ptrSad);
	k=findSadFrame(ptrSad, (unsigned char*)buffer1, (unsigned char*)buffer1, 256, 256);
	printf("%d", k);


	fclose(infp1);
	fclose(infp2);

	return 0;
}
void findsadblock(unsigned char *buffer1, unsigned char *buffer2, int width, int height, int *ptrSad)
{
	//short sum = 0;
	int i, j, x, y;
	for (x = 0; x < 256; x = x + 64)
	{
		for (y = 0; y < 256; y = y + 64)
		{
			short sum = 0;
			for (i = 0; i < 64; i++)
			{
				for (j = 0; j < 64; j++)
				{
					sum = sum + abs(*(buffer1 + (i + x) * 256 + (j + y)) - *(buffer2 + (i + x) * 256 + (j + y)));
				}

			}
			*(ptrSad++) = sum;
		printf("%d \t", sum);
		}
	}

}
int findSadFrame(int *ptrSad, unsigned char *buffer1, unsigned char *buffer2, int width, int height)
{
	short  i = 0;
    short p, q, r, Xcoordinate, Ycoordinate;
	findsadblock((unsigned char*)buffer1, (unsigned char*)buffer2, 256, 256, ptrSad);
	short min_sad = ptrSad[0];
	for (p = 0; p < 16; p++)
	{ printf("sad values are %d", ptrSad[p]);
	
	if (ptrSad[p] < min_sad)
		{
			min_sad = ptrSad[p];
			i = p;
		}
	}
	printf("i is %d", i);
	q = i / 4;
	r = i % 4;
	Xcoordinate = q * 64;
	Ycoordinate = r * 64;
	printf("%d %d", Xcoordinate, Ycoordinate);
	return min_sad;
	
	//printf("%d %d", Xcoordinate, Ycoordinate);

}


