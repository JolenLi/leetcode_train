//
// Created by Jolen on 2021/6/21.
//



#include<iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



stack<int> stk1,stk2;
ListNode* buildList(ListNode* tail,int add){
    int val=add;
    if(!stk1.empty()){
        val += stk1.top();
        stk1.pop();
    }
    if(!stk2.empty()){
        val += stk2.top();
        stk2.pop();
    }
    ListNode *head = new ListNode(val%10,tail);
    if(!stk1.empty()||!stk2.empty()||val/10!=0)
        head = buildList(head,val/10);
    return head;

}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    while(l1){
        stk1.push(l1->val);
        l1 = l1->next;
    }
    while(l2){
        stk2.push(l2->val);
        l2 = l2->next;
    }
    return buildList(nullptr,0);
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