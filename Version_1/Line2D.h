#ifndef __Line2D_h
#define __Line2D_h

#include "Color.h"
#include "Point2D.h"
#include "Shape2D.h"

struct Line2D
{
  Shape2D shape;
  Point2D p1;
  Point2D p2;
  Color color;

}; // Line2D

inline Line2D*
createLine2D(Point2D p1, Point2D p2)
{
  Line2D* line = new Line2D();

  line->shape.type = Shape2D::LINE;
  line->shape.next = line->shape.previous = nullptr;
  line->p1 = p1;
  line->p2 = p2;
  // TODO: set color
  return line;
}

inline Line2D*
createLine2D(int x1, int y1, int x2, int y2)
{
  return createLine2D(createPoint2D(x1, y1), createPoint2D(x2, y2));
}

#endif // __Line2D_h
