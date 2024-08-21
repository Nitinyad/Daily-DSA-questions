

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char , int > mpp;
        for(int i =0 ; i < n;i++){
            mpp[it]++;
        }

        priority_queue<pair<int,char > > pq;
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }

        string ans  = "";
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            for(int i = 0 ; i < it.first ; i ++){
                ans += it.second;
            }
        }
        return ans;
    }
};




// SECOND SOLUTION
class Solution {
public:
    string frequencySort(string s) {
        map<char ,int > mpp;
        for(auto it : s){
            mpp[it]++;
        }
        sort(s.begin() , s.end() , [&](const char & a , const char &b){
            return mpp[a] != mpp[b] ? mpp[a] > mpp[b] : a > b;
        });
        return s;
    }
};
