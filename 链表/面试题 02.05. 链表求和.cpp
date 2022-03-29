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

    ListNode* addNode(ListNode* l1, ListNode* l2,int add){
        if(!l1&&!l2&&add)
            return new ListNode(add);
        if(!l1){
            if(!add)
                return l2;
            else{
                add += l2->val;
                l2->val = add%10;
                add = add/10;
                l2->next = addNode(l1,l2->next,add);
                return l2;
            }
        }else if(!l2){
            if(!add)
                return l1;
            else{
                add += l1->val;
                l1->val = add%10;
                add = add/10;
                l1->next = addNode(l1->next,l2,add);
                return l1;
            }
        }


        add = add+l1->val+l2->val;

        ListNode* head = new ListNode(add%10);
        add = add/10;
        head->next = addNode(l1->next,l2->next,add);
        return head;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addNode(l1,l2,0);
    }

};