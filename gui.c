#include <stdio.h>
#include <GL/glfw.h>

void GLFWCALL reshape(int w, int h){
	printf("Resizing\n");
	glViewport(0,0, (GLsizei) w, (GLsizei) h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0.0,500.0, 0.0, 500.0);
}

void GLFWCALL display(){
	glLoadIdentity();
	glBegin(GL_LINES);
		glVertex2f(0.75,-0.25);
		glVertex2f(-0.75,-0.25);
		glVertex2f(0.25,0.75);
		glVertex2f(0.25,-0.75);
		glVertex2f(-0.25,0.75);
		glVertex2f(-0.25,-0.75);
		glVertex2f(0.75,0.25);
		glVertex2f(-0.75,0.25);
	glEnd();
	glfwSwapBuffers();
}


void GLFWCALL window_thread(void * arg){
	glfwInit();
	printf("Running\n");
	glfwOpenWindow(500,500,8,8,8,0,24,0,GLFW_WINDOW);
	glfwSetWindowSizeCallback(reshape);
	while(glfwGetWindowParam(GLFW_OPENED)){
		display();
	}
	return;
}

int main(){
	GLFWthread thread;
	printf("Testing\n");
	thread = glfwCreateThread(window_thread,NULL);
	getchar();
	printf("%d\n",thread);

	glfwTerminate();
}	
