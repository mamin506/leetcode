// mlibs.cpp
// My C++ library for leetcode.com
// Author: Min Ma
// Date: 2016/01/17  
//

#include "mlibs.h"

/*
 *  name: printList
 *  input: head -> pointer to the head of list
 *  output: none
 *  date: 2016/01/17  
 */
void printList(ListNode* head) {
  ListNode* p;

  p = head;
  if (p == NULL) {
    return
  } else {
    cout << p->val << " ";
    p = p->next;
  }

  while (p != NULL) {
    cout << " -> " << p->val;
  }

  cout << endl;
}

