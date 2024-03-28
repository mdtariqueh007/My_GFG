//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    bool isConnected(int v, vector<int>adj[]){
        int nonZeroDegree = -1;
        
        for(int i = 0;i<v;i++){
            if(adj[i].size()>0){
                nonZeroDegree = i;
                break;
            }
        }
        
        if(nonZeroDegree==-1){
            return true;
        }
        
        vector<int> vis(v,0);
        
        dfs(nonZeroDegree,adj,vis);
        
        for(int i = 0;i<v;i++){
            if(adj[i].size()>0 && !vis[i]){
                return false;
            }
        }
        
        return true;
    }
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	   
	    
	    if(isConnected(v,adj)==false){
	        return 0;
	    }
	    
	    int oddDegreeCount = 0;
	    
	    for(int i = 0;i<v;i++){
	        if(adj[i].size()%2!=0){
	            oddDegreeCount++;
	        }
	    }
	    
	    if(oddDegreeCount==0){
	        return 1;
	    }
	    
	    return 0;
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends