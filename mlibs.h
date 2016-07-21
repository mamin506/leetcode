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
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printList(ListNode* head);
void kmp_build_table(vector<int>& table, string& str);
int  kmp_search(string& str, string& word);

#endif
