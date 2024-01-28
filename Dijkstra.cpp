 vector<int> dijkstra(int u, int b, int n, vector<pair<int,int>> adj[]) {
        vector<int> dis;
        dis.assign(n+1, 1000000001);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dis[u] = 0;
        pq.push({0, u});
     
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
    
            for(auto p: adj[u]) {
                  int v = p.first;
                  int w = p.second;
                  if(dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        pq.push({dis[v], v});
                  }
            }
        }
        return dis;
    }