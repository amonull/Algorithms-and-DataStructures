#ifndef SINGLYLINKEDLISTS_H
#define SINGLYLINKEDLISTS_H
/*
  INCLUDE
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
  END INCLUDE
*/

// MACRO SOLUTION TO TYPE AGNOSTIC STRUCT
// #define DEFINE_SIGNLYNODE_T(type) typedef struct SinglyNode_t_##type { \
//                                     char* typeName;                    \
//                                     type value;                        \
//                                     struct SinglyNode_t_##type* next;  \
//                                   } SinglyNode_t_##type

// nodes for linked lists (SinglyLinkedList_t)
typedef struct SinglyNode_t {
  char* nodeTypeName;
  void* value;
  struct SinglyNode_t* next;
} SinglyNode_t;

// linked list type holds two SinglyNode_t (head and tail) and the total size of list
typedef struct {
  SinglyNode_t* head;
  SinglyNode_t* tail;
  uint16_t size;
} SinglyLinkedList_t;

// Node Functions

// Macro for generic typing (C11)
// #if __STDC_VERSION__ >= 201112L
// #define generateNode(value, next) _Generic((x), int: igenerateNode, float: fgenerateNode, double: dgenerateNode, char: cgenerateNode, default: vgenerateNode)(x, y)
// #else
// #define generateNode(type, value, next) {x, y, z};
// #endif

// creates node turning type into string for nodeTypeName, taking value as is and setting next to NULL
#define generateNode(type, value) {#type, value, NULL}
// get value from a non-pointer node
#define ngetValue(type, node) *(type*)node.value
// get value from a pointer node
#define pgetValue(type, node) *(type*)node->value

SinglyNode_t* getNext(SinglyNode_t* node);
void setNext(SinglyNode_t* node, SinglyNode_t* next);

// Linked List Functions

SinglyNode_t getHead(SinglyLinkedList_t* list);
SinglyNode_t getTail(SinglyLinkedList_t* list);
void setHead(SinglyLinkedList_t* list, SinglyNode_t* head);
void setTail(SinglyLinkedList_t* list, SinglyNode_t* tail);
void removeLast(SinglyLinkedList_t* list);
void removeFist(SinglyLinkedList_t* list);
void addLast(SinglyLinkedList_t* list, SinglyNode_t* node);
void addFirst(SinglyLinkedList_t* list, SinglyNode_t* node);
void printList(SinglyLinkedList_t* list);

#endif
