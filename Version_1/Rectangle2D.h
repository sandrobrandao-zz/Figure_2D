#ifndef __Rectangle2D_h
#define __Rectangle2D_h

#include "Shape2D.h"
#include "Color.h"
#include "Shape2D.h"

void drawLine(int, int, int, int);

struct Rectangle2D
{
  Shape2D shape;
  Point2D p1;
  Point2D p2;
  Color color;

}; // Rectangle2D

inline Rectangle2D*
createRectangle2D(const Point2D& p1, const Point2D& p2)
{
  Rectangle2D* r = new Rectangle2D();

  r->shape.type = Shape2D::RECTANGLE;
  r->shape.next = r->shape.previous = nullptr;
  // TODO: set corners
  r->p1 = p1;
  r->p2 = p2;
  // TODO: set color
  return r;
}

inline Rectangle2D*
createRectangle2D(int x1, int y1, int x2, int y2)
{
  return createRectangle2D(createPoint2D(x1, y1), createPoint2D(x2, y2));
}

inline Bounds2D
bounds(const Rectangle2D* r)
{
  return createBounds2D(r->p1, r->p2);
}

inline void
draw(const Rectangle2D* r)
{
  printf("Rectangle2D %d\n", ((Shape2D*)r)->id);
  drawLine(r->p1.x, r->p1.y, r->p2.x, r->p1.y);
  drawLine(r->p2.x, r->p1.y, r->p2.x, r->p2.y);
  drawLine(r->p2.x, r->p2.y, r->p1.x, r->p2.y);
  drawLine(r->p1.x, r->p2.y, r->p1.x, r->p1.y);
}

#endif // __Rectangle2D_h
