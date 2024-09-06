class Solution {
public:
    void merge(vector<int>&arr , int low , int mid , int high){
        int left = low ;
        int right = mid + 1;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }

        for(int i = low ; i <= high ; i++){
            arr[i] = temp[i - low];
        }
    }
    int countpairs(vector<int>& arr , int low , int mid ,int high){
        int cnt = 0;
        int right = mid + 1;
        for(int i = low ; i <= mid ; i++){
            while(right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergesort(vector<int>& arr , int low , int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high)/2;
        cnt += mergesort(arr , low , mid);
        cnt += mergesort(arr , mid + 1 , high);
        cnt += countpairs(arr , low , mid , high);
        merge(arr , low , mid , high);
        return cnt;
    }
    int reversePairs(vector<int>&arr) {
        int n = arr.size();
        return mergesort(arr , 0 , n -1);
    }
};
