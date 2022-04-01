//
// Created by Jolen on 2022/4/1.
//

ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr)   return head;
    ListNode *odd = head,*even = head->next;
    ListNode *evenHead=even;
    while(odd->next&&odd->next->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}