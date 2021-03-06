/**
 * @file    main.cpp
 * @brief   test the validity of solutions
 *
 * @author  Changrui
 * @date    2018/11/28
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#include "tree.hpp"
#include "util.hpp"
#include "array.hpp"
#include "linkedlist.hpp"
#include "string.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::endl;
using std::begin;
using std::end;

template <typename T, typename... Args>
void fruit_log(T s, Args... args) {
	cout << s << "\t";
	vector<std::string> var = {to_string(args)...};
	for (auto iter = begin(var); iter != end(var); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
};
template <typename T>
void printArray(vector<T>& nums) {
	for (auto iter = begin(nums); iter < end(nums); iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
}

void printList(ListNode* head)
{
	ListNode* index = head;
	while (index != nullptr) {
		cout << index->val << " ";
		index = index->next;
	}
	cout << endl;
}
#if 0
// test tree related solutions
int main(int argc, const char * argv[]) {

/**
 *          1
 *       /     \
 *      2       3
 *     / \     /
 *    4  5    6
 *        \  / \
 *         7 8  9
 * ----------------------
 *          1
 *       /     \
 *      0       1
 *     / \     /
 *    1  0    0
 *        \  / \
 *         0 1  0
 */
	TreeNode *root  = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node8 = new TreeNode(8);
	TreeNode *node9 = new TreeNode(9);

	root->left   = node2; root->right  = node3;
	node2->left  = node4; node2->right = node5;
	node3->left  = node6;
	node5->right = node7;
	node6->left  = node8; node6->right = node9;
	
	delete root;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
	delete node8;
	delete node9;
	
	return 0;
}

// test list related solutions
int main()
{
	ListNode* head  = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);
	head->next  = node1;  node1->next = node2;
	node2->next = node3;  node3->next = node4;
	printList(head);
	
	ListNode* result = reverseKGroup(head, 3);
	printList(result);
	
    delete head;
    delete node1; delete node2;
    delete node3; delete node4;

	return 0;
}

// test RandomListNode
int main()
{
    RandomListNode* head = new RandomListNode(0);
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    RandomListNode* node4 = new RandomListNode(4);
    head->next  = node1;  node1->next = node2;
    node2->next = node3;  node3->next = node4;
    head->random  = node3;  node1->random = nullptr;
    node2->random = node1;  node3->random = node1;
    node4->random = node3;

    RandomListNode* result = reorderList(head);
    while(result != nullptr) {
        cout << result->label << " ";
        result = result->next;
    }
    cout << endl;

    delete head;  delete node1;
    delete node2; delete node3;
    delete node4;


    return 0;
}
#endif
// test string solutions
int main(int argc, char *argv[])
{
    vector<string> strs = {"a", "bba", "aabbccd", "aaaaabbbbbccccd",
                           "geeksforgeeks", "abbcdessssss"};
    for(auto& str: strs) {
        cout << str << "\t" << rearrangeString(str, 4) << endl;
    }

    return 0;
}
