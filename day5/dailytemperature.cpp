//NEXT GREATER TO RIGHT (STACK)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n , 0);
        vector<pair<int,int>> v;
        stack<pair<int,int> > st;
        for(int i = n -1 ; i >= 0;i--){
            if(st.size() == 0){
                v.push_back({-1 , i});
            }
            else if(st.size() > 0 && st.top().first > temperatures[i]){
                v.push_back(st.top());
            }
            else if(st.size() > 0 && st.top().first <= temperatures[i]){
                while(st.size() > 0 && st.top().first <= temperatures[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v.push_back({-1 , i});
                }
                else{
                    v.push_back(st.top());
                }
            }
            st.push({temperatures[i] , i});
        }
        reverse(v.begin() , v.end());
        for(int i= 0 ; i < n;i++){
            if(v[i].first == -1){
                continue;
            }
            else{
                ans[i] = v[i].second - i;
            }
        }
        return ans;
    }
};
