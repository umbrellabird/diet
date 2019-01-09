/**
 * @file	linkedlist.cpp
 * @brief	All function implementations related to linked list
 *
 * @author	Changrui
 * @date	2019/1/7
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#include "linkedlist.hpp"

#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;
using std::less;
using std::greater;
using std::move;
using std::queue;

/**
 * @brief   Leetcode 92: Reverse Linked List II
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution 55%
 */
ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(head == nullptr || m == n) {
        return head;
    }
	// This solution is saving the values between m and n, and then
	// assign them to the pointers in reverse order.
    vector<int> valBetween;
    ListNode* index = head;
    int len = 0;
    while(index != nullptr) {
        len += 1;
        if(len >= m && len <= n) {
            valBetween.push_back(index->val);
        }
        index = index->next;
    }

    index = head;
    len = 1;
    size_t scope = valBetween.size();
    while(index != nullptr) {
        if(len >= m && len <= n) {
            index->val = valBetween[scope-len+m-1];
        }
        len++;
        index = index->next;
    }

    return head;
}
/**
 * @brief   Leetcode 92: Reverse Linked List II
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution 55%
 */
ListNode* reverseBetween2(ListNode* head, int m, int n)
{
	// This solution is setting flags before and behind the target
	// scope, and then reversing the directions of those pointers.
	if(head == nullptr || m == n) {
		return nullptr;
	}
	// flags
	ListNode* front  = nullptr;
	ListNode* back   = nullptr;
	ListNode* nodeM  = nullptr;
	ListNode* nodeN  = nullptr;
	
	ListNode* prev   = nullptr;
	ListNode* behind = nullptr;
	ListNode* node  = head;
	int index = 1;
	while(node != nullptr) {
		// set flag
		if(index == m-1)
			front = node;
		if(index == m)
			nodeM = node;
		if(index == n) {
			nodeN = node;
			back = node->next;
		}
		
		if(index > m && index <= n) {
			// reverse node pointers
			behind = node->next;
			if(index == m+1)
				prev = nodeM;
			node->next = prev;
			prev = node;
			node = behind;
		} else {
			node = node->next;
		}
		index += 1;
	}
	// establish link
	nodeM->next = back;
	if(front != nullptr)
		front->next = nodeN;
	else
		head = nodeN;
	
	return head;
}


/**
 * Leetcode 23: Merge k Sorted Lists
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution 65%
 */
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if(lists.empty())
        return nullptr;

    ListNode* index = nullptr;
    ListNode* head = nullptr;
    auto cmp = [](ListNode* m, ListNode* n){return (m->val > n->val);};
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pQueue(cmp);
    ListNode* node = nullptr;
    for(int i = 0; i < lists.size(); i++) {
        node = lists[i];
        if(node != nullptr) {
            pQueue.push(node);
            node = node->next;
        }
    }

    while(!pQueue.empty()) {
        node = pQueue.top();
        pQueue.pop();
        if(index == nullptr) {
            index = node;
            head = index;
        } else {
            index->next = node;
            index = index->next;
        }
        node = node->next;
        if(node != nullptr) {
            pQueue.push(node);
        }
    }

    return head;
}





