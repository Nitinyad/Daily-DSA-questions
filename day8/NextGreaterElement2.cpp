class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 2*n - 1 ; i >= 0;i--){
            //pop out all the elements smaller than curr ele
            while(!st.empty() && st.top() <= arr[i%n]){
                st.pop();
            }
            //if stack is empty means no greater ele is there 
            // if not then we make ans to that index equal to top ele
            if(!st.empty() && i < n){
                ans[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return ans;
    }
};
