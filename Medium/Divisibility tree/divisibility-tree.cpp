//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    private:
    int dfs(int node,vector<int> adj[],vector<int>&vis,int&ans){
        vis[node] = 1;
        int currCompNodes = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                int subTreeCount = dfs(it,adj,vis,ans);
                
                if(subTreeCount%2==0){
                    ans++;
                }else{
                    currCompNodes += subTreeCount;
                }
            }
        }
        
        return currCompNodes + 1;
    }
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> adj[n+1];
	    
	    for(auto it : edges){
	        adj[it[0]].push_back(it[1]);
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    vector<int> vis(n+1,0);
	    
	    int ans = 0;
	    
	    dfs(1,adj,vis,ans);
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends