#ifndef __Figure2D_h
#define __Figure2D_h

#include "Line2D.h"
#include "Rectangle2D.h"

/*
struct Figure2D;
struct Collection;
struct Shape2D;
struct Color;
struct Point2D;
struct Bounds2D;
struct Line2D;
struct Rectangle2D;
struct Circle2D;
*/

void drawLine(int, int, int, int);

struct Figure2D
{
  ShapeList shapes;

}; // Figure2D

Figure2D createFigure2D();
void destroyFigure2D(Figure2D*);

inline void
addShape(Figure2D* f, Shape2D* shape)
{
  addShape(&f->shapes, shape);
}

inline void
addLine(Figure2D* f, Line2D* line)
{
  addShape(f, (Shape2D*)line);
}

inline void
addLine(Figure2D* f, Point2D p1, Point2D p2)
{
  addLine(f, createLine2D(p1, p2));
}

inline void
addRectangle(Figure2D* f, Rectangle2D* rect)
{
  addShape(f, (Shape2D*)rect);
}

inline void
addRectangle(Figure2D* f, Point2D p1, Point2D p2)
{
  addRectangle(f, createRectangle2D(p1, p2));
}

void draw(const Figure2D*);

#endif // __Figure2D_h
