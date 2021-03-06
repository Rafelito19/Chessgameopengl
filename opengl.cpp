#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "GL/glut.h"

int lengh=720, width=1280; //720p  
bool set = false;
bool mouseleftdown = false;   // True if mouse LEFT button is down.
							  // Saved by mouse.
int mousex, mousey;


// mouse
// The GLUT mouse function
void mouse(int button, int state, int x, int y)
{
	// Save the left button state
	if (button == GLUT_LEFT_BUTTON)
	{
		mouseleftdown = (state == GLUT_DOWN);
		set = true;
		glutPostRedisplay();  // Left button has changed; redisplay!
	}

	// Save the mouse position
	mousex = x;
	mousey = lengh-y;

std::cout << mousex << "," << mousey<<std::endl;
}


// motion
// The GLUT motion function
void motion(int x, int y)
{
	// We only do anything if the left button is down
	if (mouseleftdown)
		glutPostRedisplay();

	// Save the mouse position
	mousex = x;
	mousey = y;
}


void draw_table() { /// draws chess board 
	bool iswhite = true;
	int oft = 75;
	int xi =50,yi = 50;
	
	for (int j = 0; j < 8; j++) {
	;
	
		xi = 200;


	
			iswhite = !(iswhite);

		
		for (int i = 0; i < 8; i++) {
			
			glColor3f(0.0, 0.0, 1.0); //white
			if (iswhite) {
				glColor3f(1.0, 1.0, 1.0);
				iswhite = false;;
			}
			else {
				iswhite = true;
			}
			 
			xi += 75;
			glBegin(GL_POLYGON);
			glVertex3i(xi, yi,0);
			glVertex3i(xi + oft, yi,0);
			glVertex3i(xi + oft, yi + oft,0);
			glVertex3i(xi, yi + oft,0);
			glEnd();
		
		}

		yi += 75;
	}

}


void display()
{
	int oft = 50;
	int xi= mousex, yi=mousey;
	glClear(GL_COLOR_BUFFER_BIT);

	draw_table();

	glColor3f(1.0,0,0.0);

	

		glBegin(GL_POLYGON);
		glVertex3i(xi, yi,1);
		glVertex3i(xi+oft, yi,1);
		glVertex3i(xi+oft, yi+oft,1);
		glVertex3i(xi, yi+oft,1);
		glEnd();

		glBegin(GL_POINTS);
		glVertex2i(mousex, mousey);
		glVertex2i(mousex+1, mousey);
		glEnd();

	
	

	glFlush();
}

void init()
{
	glClearColor(0.500, 0.500, 0.500, 0.0); // brackground color white

	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, lengh);
}

int main(int argc, char** argv)
{
	glEnable(GL_DEPTH_TEST);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width		,lengh );
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chess By djrafa");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	
	
}