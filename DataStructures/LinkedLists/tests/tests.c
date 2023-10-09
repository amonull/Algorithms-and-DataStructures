#include <CUnit/Basic.h> // unit testing framework (CUnit-devel needed)
#include <CUnit/CUnit.h>

#include "LinkedList.h"

static LinkedList_t list = {NULL, NULL, 0};

int init_suite1(void) {
  return 0;
}

int clean_suite1(void) {
  return 0;
}


void test_testingLocalNodes(void) {
  {
    int localNodeVal = 1000;
    Node_t localNode = {&localNodeVal, NULL};
    addFirst(&list, &localNode);
  }

  CU_ASSERT(1000 == *(int*)list.head->value);
  CU_ASSERT(1 == list.size);
}

void test_AddFirst(void) {
  int headNodeVal = 10;
  Node_t headNode = {&headNodeVal, NULL};

  addFirst(&list, &headNode);

}

void test_RemoveFirst(void) {

}

void test_AddThree(void) {

}

void test_RemoveThree(void) {

}

void test_AddThreeAndRemoveLast(void) {

}

void test_AddThreeAndRemoveFirst(void) {

}

void test_compareHeadAndTailPointers(void) {

}


int main()
{
   CU_pSuite pSuite = NULL;

   // initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   // add a suite to the registry
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // add the tests to the suite
   // NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf()
   // if ((NULL == CU_add_test(pSuite, "test of fprintf()", testFPRINTF)) ||
   //     (NULL == CU_add_test(pSuite, "test of fread()", testFREAD)))
   // {
   //    CU_cleanup_registry();
   //    return CU_get_error();
   // }

   // Run all tests using the CUnit Basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
