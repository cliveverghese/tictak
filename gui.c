#include <stdio.h>
#include <GL/glfw.h>
#include <math.h>

int cond;

void GLFWCALL reshape(int w, int h){
	printf("Resizing\n");
	glViewport(0,0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,500.0, 0.0, 500.0,-1,1);
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

void draw_x(int xoffset, int yoffset) {
	glBegin(GL_LINES);
		glVertex2f(0.1-0.5+0.5*xoffset,0.1+0.5-0.5*yoffset);
		glVertex2f(-0.1-0.5+0.5*xoffset,-0.1+0.5-0.5*yoffset);
		glVertex2f(-0.1-0.5+0.5*xoffset,0.1+0.5-0.5*yoffset);
		glVertex2f(0.1-0.5+0.5*xoffset,-0.1+0.5-0.5*yoffset);
	glEnd();
}
void draw_o(float xoffset, float yoffset) 
{
	int ii;
	int num_segments = 100;
	float theta = 2*3.1415926/num_segments;
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 0.1;//we start at angle = 0 
	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + 0.5*xoffset - 0.5, y - 0.5*yoffset + 0.5);//output vertex 
        
		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	} 
	glEnd(); 
}
void GLFWCALL process_click() {
	int x, y;
	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        glfwGetMousePos(&x, &y);
        if(y < 133) {
            if(x < 133) {
                printf("1\n");
            }
            else if (x > 266) {
                printf("3\n");
            }
            else {
                printf("2\n");
            }
        }
        else if(y > 266) {
            if(x < 133) {
                printf("7\n");
            }
            else if (x > 266) {
                printf("9\n");
            }
            else {
                printf("8\n");
            }   
        }
        else {
            if(x < 133) {
                printf("4\n");
            }
            else if (x > 266) {
                printf("6\n");
            }
            else {
                printf("5\n");
            }   
        }
    }
}
void GLFWCALL window_thread(void * arg){

	printf("Running\n");
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE,GL_TRUE);
	glfwOpenWindow(400,400,8,8,8,0,24,0,GLFW_WINDOW);
	//glOrtho(0.0,400.0, 0.0, 400.0,-1,1);
	glfwSetWindowSizeCallback(reshape);
	glfwSetMouseButtonCallback(process_click);
	while(glfwGetWindowParam(GLFW_OPENED)){
		display();
		draw_x(2, 2);
		draw_o(1, 1);
	}
	cond = 0;
	return;
}

int main(){
	GLFWthread thread;
	glfwInit();
	printf("Testing\n");
	cond = 1;
	thread = glfwCreateThread(window_thread,NULL);
	printf("%d\n",thread);
	while(cond);
	glfwTerminate();
}	
