// line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<gl/glut.h>

int x1,y1,x2,y2;
void plotpixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void Bresenham_Line(int x1,int y1,int x2,int y2)
{
	int dy,dx,x,y,p,i;
	dy=(y2-y1);
	dx=(x2-x1);
	x=x1;
	y=y1;
	p=(2*dy)-dx;
	if(dx<0)
	{
		x=x2;
		y=y2;
		x2=x1;
	}
	plotpixel(x,y);
	for(i=0;i<dx;i++)
	{
		x++;
		if(p<0)
			p=p+(2*dy);
		else
		{
			y++;
			p=p+(2*dy)-(2*dx);
		}
		plotpixel(x,y);
	}
}
void init()
{
	glClearColor(0,0,0,1.0);
	gluOrtho2D(0,500,0,500);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Bresenham_Line(x1,y1,x2,y2);
	glFlush();
}
void main()
{
printf("Enter points(x1,y1)");
scanf("%d%d",&x1,&y1);
printf("Enter end points(x2,y2)");
scanf("%d%d",&x2,&y2);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham line drawing");
init();
glutDisplayFunc(display);
glutMainLoop();
}