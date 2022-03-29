//
// Created by Jolen on 2022/3/14.
//

//
// Created by Jolen on 2021/6/21.
//


#include<iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *random;

    ListNode() {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

unordered_map<ListNode*,ListNode*> linkMap;
ListNode *copyRandomList(ListNode *head) {
    if(!head)return nullptr;
    ListNode *cur = head;
    ListNode *root = new ListNode(head->val);
    ListNode *copyCur = root;
    linkMap[cur] = copyCur;
    while(cur->next){
        copyCur->next = new ListNode(cur->next->val);
        linkMap[cur->next] = copyCur->next;
        cur = cur->next;
        copyCur = copyCur->next;
    }
    cur = head;
    while(cur){
        linkMap[cur]->random = linkMap[cur->random];
        cur = cur->next;
    }
    return root;
}

int main() {
    ListNode *a, *b, *c, *d, *e;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    e = new ListNode;
    a->val = 5, b->val = 4, c->val = 3, d->val = 2, e->val = 1;
    a->next = b, b->next = c, c->next = d, d->next = e;
    cout << "original list";
    for (ListNode *test = a; test != nullptr; test = test->next) {
        cout << test->val;
    }
    cout << endl << "reverse list:";
    ListNode *abc = copyRandomList(a);
    for (ListNode *test = abc; test != nullptr; test = test->next) {
        cout << test->val;
    }
    cout << endl;
    return 0;
}