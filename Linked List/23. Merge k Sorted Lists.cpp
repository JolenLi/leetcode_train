//
// Created by Jolen on 2021/10/15.
//

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// iteration
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//    if(lists.empty())
//        return nullptr;
//
//    ListNode* head = lists[0];
//    ListNode* sum = new ListNode(-1);
//    sum->next = head;
//    ListNode* ans = sum;
//    for(int i = 1;i<=lists.size();i++){
//        ListNode* head = sum->next;
//        ListNode* node = lists[i];
//        while(head&&node){
//            if(head->val<node->val)
//            {
//                sum->next = head;
//                head = head->next;
//            }else{
//                sum->next = node;
//                node =node->next;
//            }
//            sum  = sum->next;
//        }
//        sum->next = head?head:node;
//        sum  = ans;
//    }
//    return ans->next;
//}





ListNode *merge2List(ListNode *a, ListNode *b) {
    ListNode *head = new ListNode();
    ListNode *tail = head;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return head->next;
}

ListNode *merge(vector<ListNode *> &lists, int l, int r) {
    if (l == r)
        return lists[l];
    else if (l > r)
        return nullptr;
    int mid = l+((r-l)>>1);
    return merge2List(merge(lists, l, mid), merge(lists, mid + 1, r))
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    return merge(lists, 0, lists.size() - 1);
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