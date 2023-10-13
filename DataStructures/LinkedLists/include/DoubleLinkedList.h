#ifndef DOUBLYLINKEDLISTS_H
#define DOUBLYLINKEDLISTS_H
/*****************
  INCLUDE
******************/
#include <stdint.h>

// nodes for linked lists (SinglyLinkedList_t)
typedef struct SinglyNode_t {
  int value;
  struct SinglyNode_t* prev;
  struct SinglyNode_t* next;
} SinglyNode_t;

// linked list type holds two SinglyNode_t (head and tail) and the total size of list
typedef struct {
  SinglyNode_t* head;
  SinglyNode_t* tail;
  uint16_t size;
} SinglyLinkedList_t;

// Node Functions

SinglyNode_t* generateNode(int value);
int getValue(SinglyNode_t* node);
void setValue(SinglyNode_t* node, int value);
SinglyNode_t* getNext(SinglyNode_t* node);
void setNext(SinglyNode_t* current, SinglyNode_t* next);
SinglyNode_t* getPrev(SinglyNode_t* node);
void setPrev(SinglyNode_t* current, SinglyNode_t* prev);

// Linked List Functions

SinglyNode_t* getHead(SinglyLinkedList_t* list);
SinglyNode_t* getTail(SinglyLinkedList_t* list);
void setHead(SinglyLinkedList_t* list, SinglyNode_t* head);
void setTail(SinglyLinkedList_t* list, SinglyNode_t* tail);

void removeLast(SinglyLinkedList_t* list);
void removeFist(SinglyLinkedList_t* list);
void addLast(SinglyLinkedList_t* list, SinglyNode_t* node);
void addFirst(SinglyLinkedList_t* list, SinglyNode_t* node);
uint16_t getListLen(SinglyLinkedList_t* list);
void printList(SinglyLinkedList_t* list);

#endif
