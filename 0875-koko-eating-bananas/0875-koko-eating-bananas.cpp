class Solution {
public:
   
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1,r = INT_MIN;
        vector<int> tmp = piles;
        int hT = h;
        for(int i=0;i<n;i++){
            r= max(r,piles[i]);
        }
        int ans = r;

        while(l<=r){
            int k = l+(r-l)/2;

            long long sum = 0;
            for(int i=0;i<n;i++){
                int c = tmp[i]%k==0 ? tmp[i]/k : (tmp[i]/k)+1;
                sum += c;
            }
            if((hT - sum)< 0){
                l = k+1;
            }else{
                r= k-1;
            }

            if((sum-h)<=0) ans = min(ans,k);

           


        }
        return ans;

        
    }
};