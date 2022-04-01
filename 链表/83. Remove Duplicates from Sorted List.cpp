//
// Created by Jolen on 2022/3/31.
//

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = head;
    while(head&&head->next){
        if(head->val==head->next->val)
            head->next = head->next->next;
        else
            head = head->next;
    }
    return p;
}