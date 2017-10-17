#ifndef __Line2D_h
#define __Line2D_h

#include "Bounds2D.h"
#include "Color.h"
#include "Shape2D.h"

void drawLine(int, int, int, int);

struct Line2D
{
  Shape2D shape;
  Point2D p1;
  Point2D p2;
  Color color;

}; // Line2D

inline Line2D*
createLine2D(const Point2D& p1, const Point2D& p2)
{
  Line2D* l = new Line2D();

  l->shape.type = Shape2D::LINE;
  l->shape.next = l->shape.previous = nullptr;
  l->p1 = p1;
  l->p2 = p2;
  // TODO: set color
  return l;
}

inline Line2D*
createLine2D(int x1, int y1, int x2, int y2)
{
  return createLine2D(createPoint2D(x1, y1), createPoint2D(x2, y2));
}

inline Bounds2D
bounds(const Line2D* l)
{
  return createBounds2D(l->p1, l->p2);
}

inline void
draw(const Line2D* l)
{
  printf("Line2D %d\n", ((Shape2D*)l)->id);
  drawLine(l->p1.x, l->p1.y, l->p2.x, l->p2.y);
}

#endif // __Line2D_h
