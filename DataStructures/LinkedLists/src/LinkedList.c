#include "LinkedList.h"

// TMP FOR TESTING (REMOVE MAIN AFTER COMPLETE)
int main(void) {
  LinkedList_t list = {NULL, NULL, 0}; // declare and init linked list
  
  int nodeValHead = 56;
  int nodeValTail = 400;
  int nodeValThird = 18;
  Node_t headNode = {&nodeValHead, NULL};
  Node_t tailNode = {&nodeValTail, NULL};
  Node_t thirdNode = {&nodeValThird, NULL};

  addFirst(&list, &headNode);
  addLast(&list, &tailNode);
  addFirst(&list, &thirdNode);

  printf("head value: %d\n", *(int*)list.head->value); // first cast void* to int* then dereference
  printf("tail value: %d\n", *(int*)list.tail->value);
  printf("list size: %d\n", list.size);
  printf("is head == tail: %b\n", list.head == list.tail);
  printf("head pointer: %p\ntail pointer: %p\n", list.head, list.tail); // head and tail are pointers (pointer comparison)
  printf("next of head: %d\n", *(int*)getNext(list.head)->value);
  printf("is next head null: %b\n", getNext(list.head) == NULL);
  printf("is next tail null: %b\n", getNext(list.tail) == NULL);
  printf("\n\n");
  printf("***Printing List***\n\n");
  printList(&list);

  removeLast(&list);
  printf("***Printing List***\n\n");
  printList(&list);

  removeFist(&list);
  printf("***Printing List***\n\n");
  printList(&list);


  printf("is head == tail: %b\n", list.head == list.tail);

  removeLast(&list);
  printf("***Printing List***\n\n");
  printList(&list);

  return 0;
}

void addFirst(LinkedList_t *list, Node_t* node) {
  if (list->size == 0) {
    list->head = node;
    list->tail = node;
    list->head->next = list->tail;
  } else {
    node->next = list->head;
    list->head = node;
  }
  list->size++;
}

void addLast(LinkedList_t *list, Node_t* node) {
  if (list->size == 0) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void removeFist(LinkedList_t *list) {
  if (list->size == 0) {
    return;
  }

  list->head = getNext(list->head);
  list->size--;

  if (list->size == 1) {
    list->tail = list->head;
  }
}

void removeLast(LinkedList_t *list) {
  if (list->size == 0) {
    return;
  }

  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    Node_t* currentNode = list->head;

    while (getNext(getNext(currentNode)) != NULL) {
      currentNode = getNext(currentNode);
    }

    currentNode->next = NULL;
  }
  list->size--;

  if (list->size == 1) {
    list->head = list->tail;
  }
}

void setHead(LinkedList_t* list, Node_t* head) {
  list->head = head;
}

void setTail(LinkedList_t *list, Node_t* tail) {
  list->tail = tail;
}

Node_t* getNext(Node_t* node) {
  return node->next;
}

Node_t getHead(LinkedList_t* list) {
  return *list->head;
}

Node_t getTail(LinkedList_t* list) {
  return *list->tail;
}

void printList(LinkedList_t* list) {
  if (list->size == 0){
    return;
  }

  int count;
  Node_t* currentItem = list->head;

  for (count=0; count < list->size; count++) {
    printf("Element: %d\n", count);
    printf("Value: %d\n", *(int*)currentItem->value);
    printf("Pointer: %p\n\n", currentItem);
    currentItem = getNext(currentItem);
  }
}
