// ConsoleOpenGL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gl/freeglut.h>
#include <iostream>

GLubyte* LoadBmp(const char* Path, int* Width, int* Height)
{
	HANDLE hFile;
	DWORD FileSize, dwRead;
	BITMAPFILEHEADER* fh = NULL;
	BITMAPINFOHEADER* ih;
	BYTE* pRaster;

	hFile = CreateFileA(Path, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	FileSize = GetFileSize(hFile, NULL);
	fh = (BITMAPFILEHEADER*)malloc(FileSize);
	ReadFile(hFile, fh, FileSize, &dwRead, NULL);
	CloseHandle(hFile);

	int len = FileSize - fh->bfOffBits;
	pRaster = (GLubyte*)malloc(len);
	memcpy(pRaster, (BYTE*)fh + fh->bfOffBits, len);

	// RGB로 순서를 바꾼다.
	for (BYTE* p = pRaster; p < pRaster + len - 3; p += 3)
	{
		BYTE b = *p;
		*p = *(p + 2);
		*(p + 2) = b;
	}

	ih = (BITMAPINFOHEADER*)((PBYTE)fh + sizeof(BITMAPFILEHEADER));
	*Width = ih->biWidth;
	*Height = ih->biHeight;

	free(fh);
	return pRaster;
}
void DoDisplay()
{
	//{
	//	glClearColor(0.0, 0.0, 1.0, 1.0);
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	glColor3f(1.0, 0.0, 0.0);
	//	glBegin(GL_QUADS);
	//	glVertex2f(0.0, 0.5);
	//	glVertex2f(-0.5, -0.5);
	//	glVertex2f(-0.5, 0.5);
	//	glVertex2f(0.5, -0.5);
	//	glEnd();
	//	glFlush();
	//}

	//{
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	glBegin(GL_POLYGON);
	//	//glColor3f(1.0, 1.0, 1.0);
	//	glVertex2f(0.0, 0.6);
	//	glColor3f(1.0, 0.0, 0.0);
	//	glVertex2f(-0.6, 0.0);
	//	//glColor3f(1.0, 0.0, 0.0);
	//	glVertex2f(-0.4, -0.6);
	//	glColor3f(0.0, 1.0, 0.0);
	//	glVertex2f(0.4, -0.6);
	//	glColor3f(0.0, 0.0, 1.0);
	//	glVertex2f(0.6, 0.0);
	//	glEnd();
	//	glFlush();
	//}

	/*
	{
		static GLubyte bitmap[] = {
		  0x07, 0xe0, 0x18, 0x18, 0x20, 0x04, 0x43, 0xc2,
		  0x44, 0x22, 0x88, 0x11, 0x81, 0x81, 0x81, 0x81,
		  0x80, 0x01, 0x80, 0x01, 0x92, 0x49, 0x4c, 0x32,
		  0x40, 0x02, 0x20, 0x04, 0x18, 0x18, 0x07, 0xe0,
		};
		glClear(GL_COLOR_BUFFER_BIT);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
		glColor3f(1, 1, 0);
		glRasterPos2f(0.5, 0.5);
		glBitmap(16, 16, 0, 0, 20, 0, bitmap);
		glBitmap(16, 16, 0, 0, 20, 0, bitmap);
		glBitmap(16, 16, 0, 10, 20, 0, bitmap);

		glFlush();
	}*/

	/*{
		GLubyte data[32 * 32 * 3];

		for (int y = 0; y < 32; y++)
		{
			for (int x = 0; x < 32; x++)
			{
				data[y * 32 * 3 + x * 3 + 0] = 0xff;
				data[y * 32 * 3 + x * 3 + 1] = 0xff;
				data[y * 32 * 3 + x * 3 + 2] = 0x00;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);

		glRasterPos2f(0.0, 0.0);
		glDrawPixels(32, 32, GL_RGB, GL_UNSIGNED_BYTE, data);

		glFlush();
	}*/
	GLubyte* data;
	int Width, Height;

	glClear(GL_COLOR_BUFFER_BIT);

	data = LoadBmp("lena512.bmp", &Width, &Height);
	if (data != NULL)
	{
		glRasterPos2f(-0.5, -0.5);
		glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, data);
		free(data);
	}

	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutMainLoop();
}

