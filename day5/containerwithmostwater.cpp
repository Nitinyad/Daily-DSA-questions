
//USING TWO POINTER
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area= 0;
        int i = 0; 
        int n = height.size();
        int j = n -1;
        while(i < j){
            int l = j - i;
            int b = min(height[i] , height[j]);
            area = max(area , l*b);
            if(height[i] < height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;j--;
            }
        }
        return area;
    }
};
