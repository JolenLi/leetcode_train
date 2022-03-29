//
// Created by Jolen on 2021/10/14.
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

// 迭代iteration
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//    ListNode *node = new ListNode();
//    ListNode *head = node;
//    while(l1 && l2){
//        if(l1->val>l2->val){
//            head->next = l2;
//            l2 = l2->next;
//        }else{
//            head->next = l1;
//            l1 = l1->next;
//        }
//        head = head->next;
//    }
//    head->next = l1?l1:l2;
//    return node->next;
//}

// recursive
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1&&l2){
        if(l1->val<l2->val){
            ListNode *head = l1;
            head->next = mergeTwoLists(l1->next,l2);
            return head;
        }else{
            ListNode *head = l2;
            head->next = mergeTwoLists(l1,l2->next);
            return head;
        }
    }else{
        return l1?l1:l2;
    }
}
