class Solution {
public:
    bool sumGame(string num) {
        int s1 = 0,s2 = 0;
        int n = num.size();
        int lQCnt = 0, rQCnt = 0;

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2) lQCnt++;
                else rQCnt++;
            }else{
                if(i<n/2){
                    s1 += num[i]-'0';
                }
                else{
                    s2 += num[i]-'0';
                }
            }
        }


        int tot = lQCnt+rQCnt;
        if(tot%2==1) return true;

        int left = 2* s1 + 9*lQCnt;
        int right = 2* s2 + 9*rQCnt;

        if(left == right) return false;
        else return true;
    }
};