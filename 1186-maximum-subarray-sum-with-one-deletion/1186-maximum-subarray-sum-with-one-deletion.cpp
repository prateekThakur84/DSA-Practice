class Solution {
public:
    int maximumSum(vector<int>& a) {
            int n = a.size();
            int noDel = a[0];
            int oneDel = INT_MIN;
            int res = a[0];

    for (int i = 1; i < n; i++) {

        int prevNoDel = noDel;
        int prevOneDelete = oneDel;
        int v2;
        if(prevOneDelete == INT_MIN){
            v2 = a[i];
        }else{
            v2 = prevOneDelete + a[i];
        }

        

        noDel = max(a[i], noDel + a[i]);

        oneDel = max(v2,prevNoDel);

        res = max(res, max(noDel, oneDel));
    }

    return res;


    }
};