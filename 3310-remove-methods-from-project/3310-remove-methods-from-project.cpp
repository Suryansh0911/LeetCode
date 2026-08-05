class Solution {
public:
    void dfs(int k, vector<vector<int>> &adj, vector<int>& vis){
        vis[k] = 1;
        for(auto & i : adj[k]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &i : invocations){
            int s = i[0];
            int d = i[1];
            adj[s].push_back(d);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        vector<int> rem;
        for(auto &i : invocations){
            int s = i[0];
            int d = i[1];

            if(!vis[s] && vis[d]){
                for(int i=0; i<n; i++){
                    rem.push_back(i);
                }
                return rem;
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                rem.push_back(i);
            }
        }
        return rem;
    }
};