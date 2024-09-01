//GFG QUESTION -- https://www.geeksforgeeks.org/problems/search-pattern0205/1

class Solution
{
    public:
        void computelps(vector<int>&LPS , string &pat , int m){
            int len = 0;
            LPS[0] = 0;
            
            int i = 1;
            
            while(i < m){
                if(pat[i] == pat[len]){
                    len++;
                    LPS[i] = len;
                    i++;
                }
                else{
                    if(len != 0){
                        len = LPS[len-1];
                    }
                    else{
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> ans;
            int m = pat.size();
            int n = txt.size();
            
            vector<int> LPS(m , 0);
            computelps(LPS , pat , m);
            
            int i = 0;
            int j = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;j++;
                }
                if(j == m){
                    ans.push_back(i - j + 1);
                    j = LPS[j-1];
                }
                else if(pat[j]!= txt[i]){
                    if(j!= 0){
                        j = LPS[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return ans;
        }
};
