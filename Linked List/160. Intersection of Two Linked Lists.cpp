/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> path;
        while(headA){
            path.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(path.count(headB))
                return headB;
            headB =headB->next;
        }
        return NULL;
    }
};