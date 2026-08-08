class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[i] - position in word1 that can be used
        // for word2[i] while matching the suffix exactly

        vector<int> last(m,-1);

        int j = m-1;

        // match word2 from right to left

        for(int i=n-1;i>=0 && j>=0; i--){
            if(word1[i] == word2[j]){
                last[j]=i;
                j--;
            }
        }

        vector<int> ans;

        bool usedChange = false;
        j=0;

        // greedily select the smallest possible index

        for(int i=0;i<n && j<m; i++){
            char curr = word1[i];
            char req = word2[j];

            bool match = (curr==req);

            bool canChange = !usedChange && (
                j== m-1 || i<last[j+1]
            );

            if(match || canChange){
                ans.push_back(i);

                if(!match) usedChange = true;

                j++;
            }


        }

        if(j<m){
            return {};

        }

        return ans;
        
    }
};