class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i=0,j=n-1;
        sort(people.rbegin(),people.rend());
        int ans = 0;
        while(i<=j){
                if(i==j){ans++; break;}
            if((people[i]+people[j])<=limit){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                i++;
            }
        }
        return ans;
        
    }
};