//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    int timer = 0;
    
    void dfs(int node, int parent,vector<int>adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,set<int>&ans){
        vis[node] = 1;
        
        tin[node] = timer;
        low[node] = timer;
        
        timer++;
        
        int child = 0;
        
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,ans);
                
                low[node] = min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent!=-1){
                    ans.insert(node);
                }
                
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        
        if(child>1 && parent==-1){
            ans.insert(node);
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> tin(V,0), low(V,0), vis(V,0);
        
        set<int> artPoint;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
            
                dfs(i,-1,adj,vis,tin,low,artPoint);
            }
        }
        
        
        vector<int> ans;
        
        
        // artPoint.erase(0);
        
        // if(adj[0].size()>1){
        //     ans.push_back(0);
        // }
        
        
        for(auto it : artPoint){
            ans.push_back(it);
        }
        
        if(ans.size()==0){
            return {-1};
        }
        
     
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends