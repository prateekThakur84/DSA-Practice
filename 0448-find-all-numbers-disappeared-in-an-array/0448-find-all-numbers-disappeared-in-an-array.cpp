class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        vector<int> tmp(n,0);
        for(int i=0;i<n;i++){
            tmp[nums[i]-1] = 1;
        }
        for(int i=0;i<n;i++){
            if(tmp[i]==0){
                ans.push_back(i+1);
            }
        }
        return ans;

        
    
        
        return ans;
    }
};