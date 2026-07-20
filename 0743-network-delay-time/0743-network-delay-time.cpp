class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<times.size(); i++){
            int s = times[i][0]-1;
            int d = times[i][1]-1;
            int w = times[i][2];
            adj[s].push_back({d, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        int src = k-1;
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d > dist[node]) continue;

            for(int j=0; j<adj[node].size(); j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                if(d + wt < dist[neigh]){
                    dist[neigh] = d + wt;
                    pq.push({d+wt, neigh});
                }
            }
        }
        int ans=0;
        for(int i=0; i<dist.size(); i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};