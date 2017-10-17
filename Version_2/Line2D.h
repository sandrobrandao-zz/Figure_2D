#ifndef __Line2D_h
#define __Line2D_h

#include "Color.h"
#include "Shape2D.h"

struct Line2D
{
  Shape2D shape;
  Point2D p1;
  Point2D p2;
  Color color;

}; // Line2D

Line2D* createLine2D(const Point2D&, const Point2D&);

inline Line2D*
createLine2D(int x1, int y1, int x2, int y2)
{
  return createLine2D(createPoint2D(x1, y1), createPoint2D(x2, y2));
}

#endif // __Line2D_h
