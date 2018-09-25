#include <GL/glut.h>

class Star{
public:
	GLfloat radius;

	GLfloat speed,selfSpeed;

	GLfloat distance;

	GLfloat rgbColor[4];

	Star *parentStar;

	Star(GLfloat radius,GLfloat distance,
			GLfloat speed,GLfloat selfSpeed,
			Star *parentStar);

	void drawStar();

	virtual void draw(){drawStar();}
	virtual void update(long timeSpan);

protected:
	GLfloat alphaSelf,alpha;
};

class Planet:public Star{
public:
	Planet(GLfloat radius,GLfloat distance,
			GLfloat speed,GLfloat selSpeed,
			Star *parentStar,GLfloat rgbColor[3]);
	void drawPlanet();
	virtual void draw() {drawPlanet(); drawStar();}
};
class LigthPlanet:public Planet{
public:
	LightPlanet(GLfloat Radius,GLfloat Distance,
			GLfloat Speed,GLfloat SelSpeed,
			Star *ParenteStar,GLfloat rgbColor[]);

	void drawLight();
	virtual void draw() {drawLight();drawPlanet();drawStar();}
};
