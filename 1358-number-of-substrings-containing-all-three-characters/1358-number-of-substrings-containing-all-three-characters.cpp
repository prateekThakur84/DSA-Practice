class Solution {
public:
    int numberOfSubstrings(string s) {
        // int a =-1,b=-1,c=-1;
        int p[3] = {-1,-1,-1};

        int total = 0;
        for(int i=0;i<s.size();i++){
            p[s[i]-'a']=i;

            total += min({p[0],p[1],p[2]})+1;
        }
        return total;
        
    }
};