// n = 1 ---> "1"
// n = 2 ---> "11" (count , num) ek baar ek aaya hai string me
// n = 3 ---> "21" (count ,num) tho baar ek aaya hai string me
// n = 4 ---> "1211" ek baar tho , ek baar ek aaya hai
//............
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string str = countAndSay(n -1);
        string ans ="";
        for(int i = 0 ; i < str.size();i++){
            char ch = str[i];
            int count = 1;
            while(i < str.size() && str[i] == str[i+1]){
                count++;
                i++;
            }
            ans += to_string(count) + string(1, ch);
        }
        return ans;
    }
};
