class Solution {
public:
    string compare(string str1 ,string str2){
        int i= 0;
        int j = 0;
        string res = "";
        while(i < str1.size() && j < str2.size()){
            if(str1[i] == str2[j]){
                res += str1[i];
            }
            else{
                return res;
            }
            i++;
            j++;
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        for(int i = 0; i< n -1;i++){
            string x = compare(ans , strs[i+1]);
            if(x == ""){
                return "";
            }
            ans = x;
        }
        return ans;
    }
};
