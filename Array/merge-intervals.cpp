

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , [&](const vector<int>&a , const vector<int>&b){
            return a[0] < b[0];
        });
        vector<vector<int>> merge;
        vector<int> prev = intervals[0];
        for(int i = 1; i < intervals.size() ;i++){
            vector<int> interval = intervals[i];
            if(prev[1] >= interval[0]){
                prev[1] = max(interval[1] , prev[1]);
            }
            else{
                merge.push_back(prev);
                prev = interval;
            }
        }
        merge.push_back(prev);
        return merge;
    }
};
