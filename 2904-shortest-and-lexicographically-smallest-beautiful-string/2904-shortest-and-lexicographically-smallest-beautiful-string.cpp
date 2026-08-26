class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l=0,one=0;

        string ans = "";

        for(int r=0;r<n;r++){
            if(s[r]=='1') one++;

            if(one==k){
                while (s[l]=='0'){
                    l++;
                }

                string curr = s.substr(l,r-l+1);

                if(ans == "" || curr.length()<ans.length() || (curr.length()==ans.length() && curr<ans)){
                    ans = curr;
                }

                one--;
                l++;
            }
        }
        return ans;
    }
};