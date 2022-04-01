//
// Created by Jolen on 2022/4/1.
//

vector<ListNode*> ans;
void getSplitList(ListNode* head, int k,int size,int num){
    for(int i =0;i<k;i++){
        ans.push_back(head);
        int len = size + (num-->0?1:0);
        for(int j =0;j<len-1;j++)
            head = head->next;
        ListNode *next = head;
        if(head){
            next = head->next;
            head->next = nullptr;
        }
        head = next;
    }
}
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ListNode *cur = head;
    int listSize = 0;
    while(cur){
        listSize++;
        cur = cur->next;
    }
    int splitSize = listSize/k;
    int num = listSize%k;
    getSplitList(head,k,splitSize,num);
    return ans;
}
