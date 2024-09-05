

// first solution without using binary search
class Solution {
public:

    bool isPossible(vector<int>& stalls , int dist , int k ){
        int cntcows = 1;
        int last = stalls[0];
        for(int i = 1;i < stalls.size() ;i++){
            if(stalls[i] - last >= dist){
                last = stalls[i];
                cntcows++;
            }
        }
        if(cntcows >= k){
            return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        
        sort(stalls.begin() , stalls.end());
        int mini = stalls[0];
        int maxi = stalls[n-1];
        for(int i = 1; i < maxi - mini ;i++){
            if(isPossible(stalls, i , k)){
                continue;
            }
            else{
                return i -1;
            }
        }
        return -1;
    }
};




// USING BINARY SEARCH 
class Solution {
public:

    bool isPossible(vector<int>& stalls , int dist , int k ){
        int cntcows = 1;
        int last = stalls[0];
        for(int i = 1;i < stalls.size() ;i++){
            if(stalls[i] - last >= dist){
                last = stalls[i];
                cntcows++;
            }
            if(cntcows >= k){
            return true;
        }
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        
        sort(stalls.begin() , stalls.end());
        int low = 0;
        int high = stalls[n-1]-stalls[0];
        int result = 0;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isPossible(stalls , mid , k)){
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return result;
    }
};






