class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long solve(int i, vector<long long>& dp,
                    vector<int>& prev) {

        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long ans = (2 * solve(i - 1, dp, prev)) % MOD;

        int j = prev[i];

        if (j != -1) {
            ans = (ans - solve(j - 1, dp, prev) + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n, -1);
        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';

            prev[i] = last[x];
            last[x] = i;
        }

        return (solve(n - 1, dp, prev) - 1 + MOD) % MOD;
    }
};