// mlibs.h
// My C++ library for leetcode.com
// Author: Min Ma
// Date: 2016/05/31
//

#ifndef _MLIBS_H
#define _MLIBS_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head);
#endif
