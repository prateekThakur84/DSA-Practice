class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Find the longest continuous sub array that has exactly 2 distinct elements.

        int low=0;
        int maxi = 1;
        unordered_map<int,int> mpp;

        for(int high = 0;high<fruits.size();high++){
            mpp[fruits[high]]++;
            if(mpp.size()>2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]]==0) mpp.erase(fruits[low]);
                low++;

            }

            if(mpp.size()<=2){
                maxi = max(high-low+1,maxi);
            }
        }
        return maxi;
    }
};