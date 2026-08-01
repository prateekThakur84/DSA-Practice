class Solution {
public:
    bool canMake(vector<int> &bloomDay, int m,int k, int day){
          int flow = 0, bouq = 0;
        for(int bloom : bloomDay){
            if(bloom<=day){

            flow++;

            if(flow == k){
                bouq++;
                flow = 0;
            }
            } else{
            flow = 0;
        }
        }
    return bouq >= m;
    }

    
    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long) m*k > bloomDay.size()) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        int ans= high;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(canMake(bloomDay,m,k,mid)){
                ans= mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;

    }
};