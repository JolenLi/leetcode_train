//
// Created by Jolen on 2021/10/15.
//

#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//
//ListNode *detectCycle(ListNode *head) {
//    if(!head||!head->next)
//        return nullptr;
//
//    ListNode *fast = head->next->next,*slow=head->next;
//    while(fast!=slow){
//        if(fast== nullptr||fast->next== nullptr)
//            return nullptr;
//        fast=fast->next->next;
//        slow=slow->next;
//    }
//    ListNode *ptr = head;
//    while(ptr!=slow){
//        ptr=ptr->next;
//        slow=slow->next;
//    }
//    return ptr;
//}

ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> vis;
    while (head){
        if(vis.count(head))
            break;
        vis.insert(head);
        head = head->next;
    }
    return head;
}
int main() {
    ListNode *a, *b, *c, *d, *e;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    e = new ListNode;
    a->val = 1, b->val = 2, c->val = 3, d->val = 4, e->val = 5;
    a->next = b, b->next = c, c->next = d, d->next = e, e->next = nullptr;
    removeNthFromEnd(a, 2);
    while (a != nullptr) {
        cout << a->val;
        a = a->next;
    }
}