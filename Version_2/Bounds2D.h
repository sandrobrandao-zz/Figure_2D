#ifndef __Bounds2D_h
#define __Bounds2D_h

#include "Point2D.h"

struct Bounds2D
{
  Point2D p1;
  Point2D p2;

}; // Bounds2D

inline Bounds2D
createBounds2D(const Point2D& p1, const Point2D& p2)
{
  Bounds2D b;

  b.p1 = p1;
  b.p2 = p2;
  return b;
}

inline bool
contains(const Bounds2D* b, const Point2D& p)
{
  return p.x >= b->p1.x && p.x <= b->p2.x && p.y >= b->p1.y && p.y <= b->p2.y;
}

#endif // __Bounds2D_h
