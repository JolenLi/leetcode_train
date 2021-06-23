//
// Created by Jolen on 2021/6/21.
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

ListNode* swapPairs(ListNode* head) {
    if(head==nullptr||head->next== nullptr)
        return head;

    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;

    return newHead;
}
int main()
{
    ListNode *a, *b, *c, *d,*e;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    e = new ListNode;
    a->val = 1, b->val = 2, c->val = 3, d->val = 4, e->val = 5;
    a->next = b, b->next = c, c->next = d,d->next=e,e->next= nullptr;
    ListNode *newhead = swapPairs(a);

    while(newhead!= nullptr)
    {
        cout<<newhead->val;
        newhead= newhead->next;
    }
    cout<<endl;
}