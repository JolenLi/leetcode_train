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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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