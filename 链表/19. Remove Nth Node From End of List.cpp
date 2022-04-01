//
// Created by Jolen on 2021/6/20.
//

#include<iostream>
#include <stack>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0,head);
    stack<ListNode*> stk;
    ListNode *cur = dummy;
    while(cur){
        stk.push(cur);
        cur=cur->next;
    }
    for(int i =0;i<n;i++){
        stk.pop();
    }
    cur = stk.top();
    cur->next = cur->next->next
    return dummy->next;
}



ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0,head);
    ListNode *pre = dummy,*tail=dummy;
    for(int i=0;i<=n;i++)
        tail = tail->next;

    while(tail!= nullptr){
        pre  = pre->next;
        tail = tail->next;
    }

    pre->next = pre->next->next;
    return dummy->next;
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
    removeNthFromEnd(a,2);
    while(a!= nullptr)
    {
        cout<<a->val;
        a = a->next;
    }
}
