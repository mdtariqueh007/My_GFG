//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    private:
    void dfs(int node,vector<int> adj[],vector<int>&vis,int&n,int&m){
        vis[node] = 1;
        
        n++;
        m += adj[node].size();
        
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,n,m);
            }
        }
    }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        int n = v;
        vector<int> adj[n+1];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n+1,0);
        
        int res = 0;
        
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                int n = 0,m = 0;
                
                dfs(i,adj,vis,n,m);
                
                int edges = n*(n-1);
                
                if(edges==m){
                    res++;
                }
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends