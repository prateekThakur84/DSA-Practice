class Solution {
public:
    int dp[23][23];
    int solve(int i, int j , vector<int> &nums){
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i = nums[i] + min(solve(i+2,j,nums), solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));

        return dp[i][j] = max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {

        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int sA = solve(0,n-1,nums);
        int tot = 0;
        for(int i=0;i<n;i++) tot += nums[i];
        int sB = tot-sA;

        return sA >= sB;

        
    }
};