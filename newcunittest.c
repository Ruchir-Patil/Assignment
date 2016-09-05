/*
 * File:   newcunittest.c
 * Author: Ruchir
 *
 * Created on Sep 5, 2016, 5:36:12 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

list* newNode();

void testNewNode() {
    list* result = newNode();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void displayList(list* head, int n);

void testDisplayList() {
    list* head;
    int n;
    displayList(head, n);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

list* copyLinkedlist(list* head, int n);

void testCopyLinkedlist() {
    list* head;
    int n;
    list* result = copyLinkedlist(head, n);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

list* sortedList(int n);

void testSortedList() {
    int n;
    list* result = sortedList(n);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testNewNode", testNewNode)) ||
            (NULL == CU_add_test(pSuite, "testDisplayList", testDisplayList)) ||
            (NULL == CU_add_test(pSuite, "testCopyLinkedlist", testCopyLinkedlist)) ||
            (NULL == CU_add_test(pSuite, "testSortedList", testSortedList))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}




   -> newcunittest [IN PROGESS]
      --> Running testNewNode...
      --> Running testDisplayList...
      --> Running testCopyLinkedlist...
      --> Running testCopySortedlist...
  t1.c:17 (T1::test4) :: 1 is not false
   -> newcunittest [DONE]


  ==================================================
  |               |  failed  |  succeed  |  total  |
  |------------------------------------------------|
  | assertations: |       1  |        4  |      5  |
  | tests:        |       2  |        2  |      4  |
  | tests suites: |       1  |        0  |      1  |
  ==================================================