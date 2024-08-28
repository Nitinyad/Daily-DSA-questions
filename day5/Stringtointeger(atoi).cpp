

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n ==0) return 0;
        int i = 0;
        while( i < n && s[i] == ' '){ // removing the all whitespace 
            i++;
        }
        s = s.substr(i); // let say "__3245ana" ---> now after the substr "3245ana"
    
        long ans = 0;
        int sign = +1;
        if(s[0] == '-') sign = -1;
        int mini = INT_MIN , maxi = INT_MAX;
        i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        while(i < s.size()){
            if(s[i] == ' ' || !isdigit(s[i])) break;

            ans = ans * 10 + s[i] - '0';
            if(sign == -1 && -1*ans < mini) return mini;
            if(sign == 1 && ans > maxi) return maxi;
            i++;
        }
        return (int)(sign*ans);
    }
};
