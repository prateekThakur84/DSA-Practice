class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        vector<pair<int,int>> a;

        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }

        sort(a.begin(),a.end());

        int s = 0;

        while(s<n){
            int e = s;

            while(e+1<n && a[e+1].first - a[e].first <= limit){
                e++;
            }

            vector<int> idx;
            for(int i=s;i<=e;i++){
                idx.push_back(a[i].second);
            }

            sort(idx.begin(),idx.end());

            for(int i=0;i<idx.size();i++){
                nums[idx[i]] = a[s+i].first;    
            }

            s = e+1;

            
        }
        return nums;
    }
};