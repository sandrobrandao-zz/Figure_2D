#ifndef __Shape2D_h
#define __Shape2D_h

struct Shape2D
{
  enum Type
  {
    LINE,
    RECTANGLE,
    CIRCLE
  };

  Type type;
  int id;
  Shape2D* next;
  Shape2D* previous;
  Shape2D* link;

}; // Shape2D

struct ShapeList
{
  Shape2D* head;
  Shape2D* tail;
  int count;

}; // ShapeList

inline ShapeList
createShapeList()
{
  ShapeList list;

  list.head = list.tail = nullptr;
  list.count = 0;
  return list;
}

inline void
destroyShapeList(ShapeList* list)
{
  while (list->head != nullptr)
  {
    Shape2D* temp = list->head;

    list->head = temp->next;
    delete temp;
  }
  list->tail = nullptr;
  list->count = 0;
}

void addShape(ShapeList*, Shape2D*);
void removeShape(ShapeList*, Shape2D*);

#endif // __Shape2D_h
