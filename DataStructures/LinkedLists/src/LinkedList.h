#ifndef __LINKEDLISTS
#define __LINKEDLISTS
/*
  INCLUDE
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
  END INCLUDE
*/

// nodes for linked lists (LinkedList_t)
typedef struct Node Node_t;
struct Node {
  void* value;
  Node_t* next;
};

// linked list type holds two Node_t (head and tail) and the total size of list
typedef struct LinkedList LinkedList_t;
struct LinkedList {
  Node_t* head;
  Node_t* tail;
  uint16_t size;
};

/*
  MACROS
*/

/*
  END MACROS
*/

Node_t* getNext(Node_t* node);
Node_t getHead(LinkedList_t* list);
Node_t getTail(LinkedList_t* list);
void setHead(LinkedList_t* list, Node_t* head);
void setTail(LinkedList_t* list, Node_t* tail);
void removeLast(LinkedList_t* list);
void removeFist(LinkedList_t* list);
void addLast(LinkedList_t* list, Node_t* node);
void addFirst(LinkedList_t* list, Node_t* node);
void printList(LinkedList_t* list);

#endif
