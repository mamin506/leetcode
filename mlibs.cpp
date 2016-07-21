// mlibs.cpp
// My C++ library for leetcode.com
// Author: Min Ma
// Date: 2016/01/17  
//

#include "mlibs.h"

/*
 *  name: printList
 *  arguments:
 *      head -> pointer to the head of list
 *  return: none
 *  describe: Print the link list
 */
void printList(ListNode* head) {
  ListNode* p;

  p = head;
  if (p == NULL) {
    return;
  } else {
    cout << p->val << " ";
    p = p->next;
  }

  while (p != NULL) {
    cout << " -> " << p->val;
  }

  cout << endl;
}


/*
 *  name: kmp_build_table
 *  arguments:
 *      table -> the table to be filld
 *      str -> the word to be analyzed
 *  return: none
 *  describe: Build partial Match Table for KMP algorithm
 */
void kmp_build_table(vector<int>& table, string& str) {
  int pos = 2;
  int cnd = 0;
  table.push_back(-1);
  table.push_back(0);

  while (pos < str.size()) {
    if (str[pos-1] == str[cnd]) {
      cnd++;
      table.push_back(cnd);
      pos++;
    } else if (cnd > 0) {
      cnd = table[cnd];
    } else {
      table.push_back(0);
      pos++;
    }
  }
}

/*
 *  name: kmp_search
 *  arguments:
 *      str -> the text to be searched
 *      word -> the word sought
 *  return: the zero-based position in str at which word is found
 *  describe: string search KMP algorithm
 */
int kmp_search(string& str, string& word) {
    int m = 0;
    int i = 0;
    vector<int> table;

    kmp_build_table(table, word);

    while (m + i < str.size()) {
        if (word[i] == str[m + i]) {
            if (i == word.size() - 1) {
                return m;
            }
            i++;
        } else {
            if (table[i] > -1) {
                m = m + i - table[i];
                i = table[i];
            } else {
                m++;
                i = 0;
            }
        }
    }
    return str.size();
}
