class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int &min_score){
        visited[node] = true;
        for(const auto& edge : adj[node]){
            int neighbor = edge.first;
            int weight = edge.second;
            min_score = min(min_score, weight);
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited, min_score);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> visited(n+1, false);
        int min_score = INT_MAX;
        dfs(1, adj, visited, min_score);
        return min_score;
    }
};