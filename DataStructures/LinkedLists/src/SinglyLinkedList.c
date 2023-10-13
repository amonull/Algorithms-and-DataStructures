#include "SinglyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

SinglyNode_t* generateNode(int value) {
  SinglyNode_t* pnode = (SinglyNode_t*) malloc(sizeof(SinglyNode_t));

  pnode->value = value;
  pnode->next = NULL;

  return pnode;
}

void addFirst(SinglyLinkedList_t *list, SinglyNode_t* node) {
  if (getListLen(list) == 0) {
    setHead(list, node);
    setTail(list, node);
    setNext(getHead(list), getTail(list));
  } else {
    setNext(node, getHead(list));
    setHead(list, node);
  }
  list->size++;
}

void addLast(SinglyLinkedList_t *list, SinglyNode_t* node) {
  if (list->size == 0) {
    setHead(list, node);
    setTail(list, node);
  } else {
    setNext(getTail(list), node);
    setTail(list, node);
  }
  list->size++;
}

void removeFist(SinglyLinkedList_t *list) {
  if (list->size == 0) {
    return;
  }

  SinglyNode_t* pfreeNode = list->head;
  list->head = getNext(list->head);
  free(pfreeNode);
  list->size--;

  if (list->size == 1) {
    list->tail = list->head;
  }
}

void removeLast(SinglyLinkedList_t *list) {
  if (getListLen(list) == 0)
    return;

  if (getListLen(list) == 1) {
    setHead(list, NULL);
    setTail(list, NULL);
  }

  SinglyNode_t* current = getHead(list);
  while (getNext(getNext(current)) != NULL) {
    current = getNext(current);
  }
  setTail(list, current);
  setNext(current, NULL);
}

void setHead(SinglyLinkedList_t* list, SinglyNode_t* head) {
  list->head = head;
}

void setTail(SinglyLinkedList_t *list, SinglyNode_t* tail) {
  list->tail = tail;
}

void setNext(SinglyNode_t* current, SinglyNode_t* next) {
  current->next = next;
}

SinglyNode_t* getNext(SinglyNode_t* node) {
  return node->next;
}

SinglyNode_t* getHead(SinglyLinkedList_t* list) {
  return list->head;
}

SinglyNode_t* getTail(SinglyLinkedList_t* list) {
  return list->tail;
}

uint16_t getListLen(SinglyLinkedList_t* list) {
  return list->size;
}

int getValue(SinglyNode_t *node) {
  return node->value;
}

void setValue(SinglyNode_t *node, int value) {
  node->value = value;
}

void printList(SinglyLinkedList_t *list) {
  SinglyNode_t* current = list->head;
  if (current == NULL) {
    return;
  }
  while (current != NULL) {
    printf("node pointer: %p\nnode value: %d\n\n", current, getValue(current));
    current = getNext(current);
  }
}
