class Solution {
public:
    
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            int cur = nums[i];
           
           while(cur>0){
            sum+= (cur%10);
            cur/=10;
           }
           if(sum==i) return i;
        }
        return -1;

    }
};