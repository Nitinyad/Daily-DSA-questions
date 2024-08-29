

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* prev = dummy;
            ListNode* nextnode = curr-> next;
            while(prev -> next != NULL && prev-> next ->val < curr -> val){
                prev = prev -> next;
            }
            curr -> next = prev -> next;
            prev -> next = curr;
            curr = nextnode;
        }
        return dummy-> next;
    }
};
