//
// Created by Jolen on 2021/3/12.
//


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
};

void printList(ListNode *head)
{
    while(head!= nullptr)
    {
        cout<<head->val<<endl;
        head = head->next;
    }


}

ListNode *reverse(ListNode *head)
{
    ListNode *pre = nullptr, *cur = head,*nxt;
    while(cur!= nullptr)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

bool fast_slow_pointer(ListNode *head)
{
    ListNode *slow=head,*fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next== nullptr)
        slow = slow->next;
    ListNode *ptr = reverse(slow);
    while(ptr){
        if(ptr->val!=head->val)
            return 0;
        ptr = ptr->next;
        head = head->next;
    }
    return 1;
}


//ListNode *last;
//
//// duplicate a linked list, predefine the last link note.(recursion) O(N)
//ListNode *reverse_recursion(ListNode *head) {
//    if (head == nullptr)return nullptr;
//    ListNode *tail = new ListNode();
//    tail->val = head->val;
//    tail->next = nullptr;
//    if (head->next == nullptr) {
//        last = tail;
//        return tail;
//    } else {
//        ListNode *newhead = reverse_recursion(head->next);
//        newhead->next = tail;
//        return tail;
//    }
//}



//
//// duplicate a linked list using iterate O(N)
//ListNode *reverse_iterate(ListNode *head) {
//    ListNode *tail = new ListNode();
//    ListNode *pre = nullptr;
//    while (head != nullptr) {
//        ListNode *cur = new ListNode();
//        cur->val = head->val;
//        cur->next = pre;
//        pre = cur;
//        head = head->next;
//    }
//    return pre;
//}
//
//bool fast_slow_pointer(ListNode *head) {
//    ListNode *fast, *slow;
//    slow = fast = head;
//    while (fast != nullptr && fast->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    if (fast != nullptr)
//        slow = slow->next;
//
//    ListNode *cur,*pre,*nxt;
//    cur=nxt=slow,pre= nullptr;
//    while(cur!= nullptr)
//    {
//        nxt=cur->next;
//        cur->next=pre;
//        pre=cur;
//        cur=nxt;
//    }
//    ListNode *tail = pre;
//    while (tail!= nullptr){
//        if(tail->val!=head->val)
//            return false;
//        tail=tail->next;
//        head=head->next;
//    }
//    return true;
//}
//
//bool isPalindrome(ListNode *head) {
//    ListNode *tail = reverse_iterate(head);
//    while (head != nullptr && tail != nullptr) {
//        if (head->val != tail->val)
//            return false;
//        head = head->next;
//        tail = tail->next;
//    }
//    return true;
//}

int main() {
    ListNode *a, *b, *c, *d,*e;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    e = new ListNode;
    a->val = 5, b->val = 3, c->val = 2, d->val = 2, e->val = 5;
    a->next = b, b->next = c, c->next = d,d->next = e;
    cout << "original list";
    for (ListNode *test = a; test != nullptr; test = test->next) {
        cout << test->val;
    }
    cout << endl << "reverse list:";
    cout<<fast_slow_pointer(a);
//    ListNode *abc = reverse_iterate(a);
//    for (ListNode *test = abc; test != nullptr; test = test->next) {
//        cout << test->val;
//    }
//    cout << endl << isPalindrome(a) << endl;
    return 0;
}