
// WITHOUT USING MAP IF YOU WANT MAP WALA SOLUTION VISIT LEETCODE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele ;
        for(int i = 0; i < nums.size();i++){
            if(cnt == 0){
                cnt = 1 ;
                ele = nums[i];
            }
            else if(ele = nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1 = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == ele) cnt1++;
        }
        if(cnt1 > nums.size()/2){
            return ele;
        }
        return -1;
    }
};
