// LEETCODE QUESTION LINK : https://leetcode.com/problems/rotate-array/


class Solution {
public:
    void reverse(vector<int>& nums , int s ,int e){
        while(s <= e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return ;
        }
        k = k % n;
        reverse(nums , 0 , n - k - 1);
        reverse(nums , n - k , n -1);
        reverse(nums , 0 , n - 1);
    }
};
