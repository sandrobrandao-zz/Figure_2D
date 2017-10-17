#include "Shape2D.h"

void
addShape(ShapeList* list, Shape2D* s)
{
  s->link = nullptr;
  if (list->head == nullptr)
    list->head = s;
  else
  {
    list->tail->next = s;
    s->previous = list->tail;
  }
  list->tail = s;
  list->count++;
}

void
removeShape(ShapeList* list, Shape2D* s)
{
  if (s->previous != nullptr)
    s->previous->next = s->next;
  if (s->next != nullptr)
    s->next->previous = s->previous;
  if (s == list->head)
    list->head = s->next;
  if (s == list->tail)
    list->tail = s->previous;
  list->count--;
  delete s;
}
