/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    while(l1!=l2){
        l1 = l1==NULL?headB:l1->next;
        l2 = l2==NULL?headA:l2->next;
    }
    return l1;
}