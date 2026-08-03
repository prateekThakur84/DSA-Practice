class Solution {
public:
    // int n;
    // int solve(vector<int> &sV,int i,vector<int> &dp){
    //     if(i>=n) return 0;

    //     if(dp[i]!=-1) return dp[i];

    //     int result =  sV[i] - solve(sV,i+1,dp);
    //    if(i+1 < n) result = max(result, sV[i] + sV[i+1] - solve(sV,i+2,dp));
    //     if(i+2 < n) result = max(result, sV[i] + sV[i+1] + sV[i+2] - solve(sV,i+3,dp));

    //     return dp[i] = result;


    // }
    string stoneGameIII(vector<int>& sV) {
        int n = sV.size();
        vector<int> dp(n+1);

        for(int i=n-1;i>=0;i--){
              dp[i] =  sV[i] - dp[i+1];
            if(i+2 <= n) dp[i] = max(dp[i], sV[i]+sV[i+1] - dp[i+2]);
            if(i+3 <= n) dp[i] = max(dp[i], sV[i] + sV[i+1] + sV[i+2] - dp[i+3]);


        }

        if(dp[0]<0) return "Bob";
        else if(dp[0]>0) return "Alice";
        
        return "Tie";


        // int diff = solve(sV,0,dp); // alice - bob

        // if(diff>0) return "Alice";
        // else if(diff<0) return "Bob";

        // return "Tie";
        
    }
};