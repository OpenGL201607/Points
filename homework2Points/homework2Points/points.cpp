#include "points.h"
#define PI 3.1415927
Points::Points(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
}

Points::~Points()
{

}

void Points::initializeGL()
{
	setGeometry(200,100,680,480);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void Points::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot,1.0,0.0,0.0);
	glRotatef(yRot,0.0,1.0,0.0);
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_POINTS);
	z = -0.5f;
	for(angle =0.0;angle <(2.0 * PI)* 3.0;angle += 0.1)
	{
		glVertex3f(0.5*sinf(angle),0.5*cosf(angle),z);
		z += 0.005f;
	}
	glEnd();
	glPopMatrix();
}

void Points::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void Points::keyPressEvent(QKeyEvent *e)
{
	switch (e->key())
	{
	case Qt::Key_Up:
		xRot += 0.5f;
		break;
	case Qt::Key_Down:
		xRot -= 0.5f;
		break;
	case Qt::Key_Left:
		yRot += 0.5f;
		break;
	case Qt::Key_Right:
		yRot -= 0.5f;
		break;
	default:
		break;
	}
	updateGL();
}
