// ConsoleOpenGL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gl/freeglut.h>
#include <iostream>

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
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutMainLoop();
}

