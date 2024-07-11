//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU{
  public:
  vector<int> size,parent;
  DSU(int n){
      size.resize(n);
      parent.resize(n);
      
      for(int i = 0;i<n;i++){
          parent[i] = i;
          size[i] = 1;
      }
  }
  
  int findPar(int u){
      if(parent[u]==u){
          return u;
      }
      
      return parent[u] = findPar(parent[u]);
  }
  
  void unionBySize(int u,int v){
      int pu = findPar(u);
      int pv = findPar(v);
      
      if(pu==pv){
          return;
      }
      
      if(size[pu]<size[pv]){
          size[pv] += size[pu];
          parent[pu] = pv;
      }
      else{
          size[pu] += size[pv];
          parent[pv] = pu;
      }
  }
};


class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        
        DSU ds(n*n);
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                
                
                for(int k = 0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                        int node = n * i + j;
                        int adjNode = n * ni + nj;
                        
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        
        int maxi = 0;
        
        for(int i = 0;i<n*n;i++){
            maxi = max(maxi,ds.size[i]);
        }
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                
                unordered_set<int> st;
                
                for(int k = 0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                        int node = n * ni + nj;
                        
                        st.insert(ds.findPar(node));
                    }
                }
                
                int curr = 1;
                
                for(auto it : st){
                    curr += ds.size[it];
                }
                
                maxi = max(maxi,curr);
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends