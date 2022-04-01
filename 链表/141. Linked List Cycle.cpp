//
// Created by Jolen on 2021/10/14.
//

#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


//bool hasCycle(ListNode *head) {
//    unordered_set<ListNode *> listSet;
//    while (head) {
//        if (listSet.count(head))
//            return true;
//        else
//            listSet.insert(head);
//            head = head->next
//    }
//    return false;
//}


bool hasCycle(ListNode *head) {
    if(!head||!head->next)
        return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
