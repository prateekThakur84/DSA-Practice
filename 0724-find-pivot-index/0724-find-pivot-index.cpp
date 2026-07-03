class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n =nums.size();
        vector<int> pre(n,0);
        vector<int> suf(n,0);

        pre[0]=0;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }

        //0,1,8,11,17,22
        //28,27,20,17 ,11,6,



        suf[n-1]=0;
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1]+nums[i+1];
        }

        
        for(int k=0;k<n;k++){
            if(pre[k]==suf[k]){return k;}
        }
        return -1;

        
    }
};