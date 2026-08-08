class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
     int n = word1.size();
     int m = word2.size();

     vector<int> rightHandSideMatchLength(n,0);

     int rightMatched = 0;
     int i = n-1;
     int j=   m-1;

     while(i>=0 ){
        if(j>= 0 && word1[i]==word2[j]){
            // ans.push_back(i);
            rightMatched++;
            // i--;
            j--;

        }

        rightHandSideMatchLength[i]=rightMatched;
        i--;
     }
     vector<int> ans;


     bool changePower = true;

     i=0,j=0;

     while(i<n && j<m){
        if(word1[i]==word2[j]){
            ans.push_back(i);
            // i++;
            j++;
        }else if(changePower == true && i+1<n && rightHandSideMatchLength[i+1] >= m-j-1   ){
            ans.push_back(i);
            j++;
            changePower = false;
        } 
        i++;


     }

     return j==m ? ans : vector<int> ();
    }
};