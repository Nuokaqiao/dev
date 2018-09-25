#include <GL/glut.h>
#include "solarsystem.hpp"

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

SolarSystem solarstytem;
void onDisplay()
{
	solarsystem.onDisplay();
}

void onUpdate()
{
	solarsystem.onUpdate();
}
void onKeyboard(unsigned char key,int x,int y)
{
	solarsystem.onKeyboard(key,x,y);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(WINDOW_X_POS,WINDOW_Y_POS);
	glutCreateWindow("SolarSysten at shiyanlou");
	glutDisplayFunc(onDisplay);
	glutIdleFunc(onUpdate);
	glutKeyboardFunc(onkeyboard);
	glutMainLoop();
	return 0;
}

