#ifndef POINTS_H
#define POINTS_H

#include <QtWidgets/QWidget>
#include "ui_points.h"
#include <QtGui>
#include <QtCore>
#include <QtOpenGL>
class Points : public QGLWidget
{
	Q_OBJECT

public:
	Points(QGLWidget *parent = 0);
	~Points();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void keyPressEvent(QKeyEvent *e);

private:
	Ui::PointsClass ui;
	GLfloat xRot, yRot, z, angle;
};

#endif // POINTS_H
