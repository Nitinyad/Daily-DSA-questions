class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            sort(arr , arr + n );
            //first solution
            // int ind = 0;
            // for(int i = 0 ; i< n;i++){
            //     if(arr[i] >= 0){
            //         return arr[i-1] + arr[i];
            //     }
            //     else{
            //         ind = i ;
            //     }
            // }
            // return arr[ind-1] + arr[ind];
            
            //second solution using two pointer
            int left =0;
            int right = n -1;
            if(arr[right] < 0){
                return arr[right] + arr[right-1];
            }
            if(arr[left]>0){
                return arr[left]+arr[left+1];
            }
            int minsum = INT_MAX;
            while(left < right){
                int sum = arr[left] + arr[right];
                if(abs(sum) < abs(minsum)){
                    minsum = sum;
                }
                else if(abs(sum) == abs(minsum)){
                    minsum = max(minsum , sum);
                }
                if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
            return minsum;
        }
};
