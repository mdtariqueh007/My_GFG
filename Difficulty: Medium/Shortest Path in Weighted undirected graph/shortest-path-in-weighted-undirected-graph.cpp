//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n];
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            u--;
            v--;
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(n,1e9);
        vector<int> parent(n);
        
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        
        dist[0] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            
            pq.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(d + w<dist[v]){
                    dist[v] = d + w;
                    
                    pq.push({dist[v],v});
                    
                    parent[v] = node;
                }
            }
        }
        
        if(dist[n-1]==1e9){
            return {-1};
        }
        
        vector<int> ans;
        
        int node = n - 1;
        
        while(parent[node]!=node){
            ans.push_back(node+1);
            node = parent[node];
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        ans.insert(ans.begin(),dist[n-1]);
        
        // for(int it  : ans){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends