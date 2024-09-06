class Solution {
public:
    vector<int> temp;

    int merge(vector<int>& nums, int start, int mid, int end){
        int i = start, j = mid+1, cn = 0;
        int n = nums.size();
        
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
                cn += mid - i + 1;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= end){
            temp.push_back(nums[j++]);
        }

        for(int x = start; x <= end; x++){
            nums[x] = temp[x-start];
        }
        temp.clear();
        return cn;
    }

    int mergesort(vector<int>& nums, int start, int end){
        //base case
        if(start >= end){
            return 0;
        }

        int mid = start + (end-start)/2;
        long long cn = 0;
        cn += mergesort(nums, start, mid);
        cn += mergesort(nums, mid+1, end);
        cn += merge(nums, start, mid, end);
        return cn;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int local = 0; 

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                local++;
            }
        }

        int global = mergesort(nums, 0, n-1);

        return global == local;
    }
};
