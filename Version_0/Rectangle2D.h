#ifndef __Rectangle2D_h
#define __Rectangle2D_h

#include "Color.h"
#include "Point2D.h"
#include "Shape2D.h"

struct Rectangle2D
{
  Shape2D shape;
  Point2D p1;
  Point2D p2;
  Color color;

}; // Rectangle2D

inline Rectangle2D*
createRectangle2D(Point2D p1, Point2D p2)
{
  Rectangle2D* rect = new Rectangle2D();

  rect->shape.type = Shape2D::RECTANGLE;
  rect->shape.next = rect->shape.previous = nullptr;
  // TODO: set corners
  rect->p1 = p1;
  rect->p2 = p2;
  // TODO: set color
  return rect;
}

inline Rectangle2D*
createRectangle2D(int x1, int y1, int x2, int y2)
{
  return createRectangle2D(createPoint2D(x1, y1), createPoint2D(x2, y2));
}

#endif // __Rectangle2D_h
