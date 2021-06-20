//
// Created by Jolen on 2021/6/20.
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
ListNode *addNode(ListNode *head,int a)
{
    ListNode *last = new ListNode(a, nullptr);
    head->next = last;
    head = head->next;
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    bool carry = false;
    ListNode *pre = new ListNode(0);
    ListNode *cur = pre;
    int a,b,num;
    while(l1!= nullptr||l2!= nullptr)
    {
        a = l1== nullptr? 0:l1->val;
        b = l2== nullptr?0:l2->val;

        num = a+b+carry;
        carry = false;
        if(num>=10)
        {
            carry = true;
            num-=10;
        }

        cur = addNode(cur,num);

        if(l1!= nullptr) l1 = l1->next;
        if(l2!= nullptr)l2 = l2->next;
    }

    if(carry)
    {
        cur = addNode(cur,carry);
    }
    return pre->next;
}


int main()
{
    ListNode *a, *b, *c, *d;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    a->val = 5, b->val = 4, c->val = 3, d->val = 2;
    a->next = b, b->next = c, c->next = d;

    ListNode *A, *B, *C, *D;
    A = new ListNode;
    B = new ListNode;
    C = new ListNode;
    D = new ListNode;
    A->val = 5, B->val = 5, C->val = 7, D->val = 7;
    A->next = B, B->next = C, C->next = D;





    ListNode *abc = addTwoNumbers(a,A);
    while(abc!= nullptr)
    {
        cout<<abc->val<<endl;
        abc = abc->next;
    }
}