class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        vector<int> inDegree(n,0);

       vector<bool> susp(n, false);
        for(auto &edge : invocations){
            int u= edge[0];
            int v= edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        // BFS

        queue<int> q;
        q.push(k);
        susp[k]=true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int &ngbr : adj[cur]){
                inDegree[ngbr]--;
                if(!susp[ngbr]){
                    q.push(ngbr);
                    susp[ngbr]=true;
                }
            }
        }

        vector<int> result;

        bool flag= true;

        for(int i=0;i<n;i++){
            if(susp[i] && inDegree[i]>0){
                flag = false;
                break;
            }
            if(!susp[i]) result.push_back(i);
        }

        if(!flag){
            vector<int> ans(n);
            for(int i=0;i<n;i++){
                ans[i]=i;
            }
            return ans;
        }
        return result;

    }
};