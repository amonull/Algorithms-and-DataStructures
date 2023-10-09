#include "SinglyLinkedList.h"

// TMP FOR TESTING (REMOVE MAIN AFTER COMPLETE)
int main(void) {
  SinglyLinkedList_t list = {NULL, NULL, 0}; // declare and init linked list
  
  int nodeValHead = 56;
  int nodeValTail = 400;
  int nodeValThird = 18;
  SinglyNode_t headNode = {"int", &nodeValHead, NULL};
  SinglyNode_t tailNode = {"int", &nodeValTail, NULL};
  SinglyNode_t thirdNode = {"int", &nodeValThird, NULL};

  addFirst(&list, &headNode);
  addLast(&list, &tailNode);
  addFirst(&list, &thirdNode);

  printf("head value: %d\n", pgetValue(int, list.head)); // first cast void* to int* then dereference
  printf("tail value: %d\n", pgetValue(int, list.tail));
  printf("list size: %d\n", list.size);
  printf("is head == tail: %b\n", list.head == list.tail);
  printf("head pointer: %p\ntail pointer: %p\n", list.head, list.tail); // head and tail are pointers (pointer comparison)
  printf("next of head: %d\n", pgetValue(int, getNext(list.head)));
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

// SinglyNode_t* vgenerateNode(void* value, SinglyNode_t* next) {
//   // extracting data inside value

//   // XXX: create using malloc so you can free it later instead of just letting it live in mem with static
//   static SinglyNode_t node = {value, next};

//   return &node;
// }

void addFirst(SinglyLinkedList_t *list, SinglyNode_t* node) {
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

void addLast(SinglyLinkedList_t *list, SinglyNode_t* node) {
  if (list->size == 0) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void removeFist(SinglyLinkedList_t *list) {
  if (list->size == 0) {
    return;
  }

  list->head = getNext(list->head);
  list->size--;

  if (list->size == 1) {
    list->tail = list->head;
  }
}

void removeLast(SinglyLinkedList_t *list) {
  if (list->size == 0) {
    return;
  }

  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    SinglyNode_t* currentNode = list->head;

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

void setHead(SinglyLinkedList_t* list, SinglyNode_t* head) {
  list->head = head;
}

void setTail(SinglyLinkedList_t *list, SinglyNode_t* tail) {
  list->tail = tail;
}

SinglyNode_t* getNext(SinglyNode_t* node) {
  return node->next;
}

SinglyNode_t getHead(SinglyLinkedList_t* list) {
  return *list->head;
}

SinglyNode_t getTail(SinglyLinkedList_t* list) {
  return *list->tail;
}

void printList(SinglyLinkedList_t* list) {
  if (list->size == 0) {
    return;
  }

  int count;
  SinglyNode_t* currentItem = list->head;

  // while (NULL != getNext(currentItem)->next) {
  for (count=0; count < list->size; count++) {
    printf("Element: %d\n", count);
    printf("Value: %d\n", *(int*)currentItem->value);
    printf("Pointer: %p\n\n", currentItem);
    currentItem = getNext(currentItem);
  }
}
