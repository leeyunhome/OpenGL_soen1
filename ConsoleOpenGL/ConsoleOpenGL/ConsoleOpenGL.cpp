#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <iostream>
#include "math.h"

const int width_window = 640;
const int height_window = 480;

int main(void)
{
	GLFWwindow* window = nullptr;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width_window, height_window, "Hello World1", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// callbacks here


	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(90.0 / 255.0, 74.0/255.0, 236.0 / 255.0, 1); // while background
	// default color for display buffer

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	// your frame buffer is two dimensional array
	//glOrtho(0, 1, 0, 1, -1.0, 1.0);
	// You are going to study later in Viewing class.

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//TODO: draw here
		//glBegin(GL_LINE_LOOP);
		glBegin(GL_TRIANGLES);

		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		glVertex3f(0.5, 0.0, 0.0);	
		glVertex3f(0.25, 0.5, 0.0);	

		glEnd();

		// Note: this is an old style OpenGL.

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	return 0;
}

