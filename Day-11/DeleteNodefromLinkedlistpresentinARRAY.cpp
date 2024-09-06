
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode* newHead = temp;
        set<int> st;
        for(int i = 0; i < nums.size() ; i++){
            st.insert(nums[i]);
        }
        while(temp->next != NULL){
            if(st.find(temp->next->val)!=st.end()){
                ListNode* nx = temp -> next;
                temp -> next = nx -> next;
                delete(nx);
                
            }else{
                temp = temp->next;
            }
        }
        return newHead -> next;
    }
};
