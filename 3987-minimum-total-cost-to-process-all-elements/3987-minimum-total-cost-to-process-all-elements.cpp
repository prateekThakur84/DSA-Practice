class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;

        long long cnt = 0;
        long long cur = k;

        for(int x : nums){
            if(cur<x){
                long long need = (x-cur+k-1LL)/k;
                cnt+= need;
                cur += need*1LL*k;
            }
            cur-=x;
        }

        cnt %= MOD;
            return (int) ((cnt*(cnt+1)/2)%MOD);
    }
};