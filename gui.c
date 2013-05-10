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
int GLFWCALL process_click() {
	int x, y;
	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        glfwGetMousePos(&x, &y);
        if(y < 133) {
            if(x < 133) {
                return 1;
            }
            else if (x > 266) {
                return 3;
            }
            else {
                return 2;
            }
        }
        else if(y > 266) {
            if(x < 133) {
                return 7;
            }
            else if (x > 266) {
                return 9;
            }
            else {
                return 8;
            }   
        }
        else {
            if(x < 133) {
                return 4;
            }
            else if (x > 266) {
                return 6;
            }
            else {
                return 5;
            }   
        }
    }
}
void GLFWCALL window_thread(){
	int grid_id;
	glfwInit();
	printf("Running\n");
	glfwOpenWindow(400,400,8,8,8,0,24,0,GLFW_WINDOW);
	glfwSetWindowSizeCallback(reshape);
	while(glfwGetWindowParam(GLFW_OPENED)){
		display();
		grid_id = 0;
		grid_id = process_click();
		if(grid_id != 0) {
			printf("%d\n", grid_id);
		}
	}
	return;
}

int main(){
	GLFWthread thread;
	printf("Testing\n");
	window_thread();
	printf("%d\n",thread);

	glfwTerminate();
}	
