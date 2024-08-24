
//MOORE'S VOTING ALGORITHM --- EXTENDED 

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        //first solution
        int n = arr.size();
        // unordered_map<int,int > mpp;
        // for(auto it : nums){
        //     mpp[it]++;
        // }
        // vector<int> ans;
        // for(auto it : mpp){
        //     if(it.second > n/3){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        //second solution
        // int n = nums.size();
        // unordered_map<int,int > mpp;
        // int mini = n / 3 + 1;
        // vector<int> ans;
        // for(auto it : nums){
        //     mpp[it]++;
        //     if(mpp[it] == mini){
        //         ans.push_back(it);
        //     }
        // }
        // return ans;

        //third solution
        //using the Moore's voting alogrithm

        int ele1 , ele2 ;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i< n ;i ++){
            if(cnt1 == 0 && arr[i] != ele2){
                cnt1 = 1;
                ele1 = arr[i];
            }
            else if(cnt2 == 0 && arr[i] != ele1){
                cnt2 = 1;
                ele2 = arr[i];
            }
            else if(arr[i] == ele1) cnt1++;
            else if(arr[i] == ele2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        vector<int> ls;
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < n ; i++){
            if(ele1 == arr[i]) cnt1++;
            else if(ele2 == arr[i]) cnt2++;
        }

        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini) ls.push_back(ele1);
        if(cnt2 >= mini) ls.push_back(ele2);

        return ls;
    }
};
