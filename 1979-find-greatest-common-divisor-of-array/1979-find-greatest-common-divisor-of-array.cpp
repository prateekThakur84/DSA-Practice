class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int r = a%b;
            a=b;
            b=r;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            mini = min(nums[i],mini);
        }

        return gcd(maxi,mini);
        
    }
};