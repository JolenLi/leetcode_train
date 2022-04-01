//
// Created by Jolen on 2022/3/10.
//



#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 遍历
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while(cur!=nullptr){
        ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// 递归
ListNode* reverseList(ListNode* head) {
    if(!head||!head->next)
        return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}