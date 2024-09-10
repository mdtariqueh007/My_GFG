//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int node,vector<int> adj[],vector<bool>&visited){
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    bool isConnected(int src, vector<bool>&mark,vector<int> adj[]){
        vector<bool> visited(26,false);
        
        dfs(src,adj,visited);
        
        for(int i = 0;i<26;i++){
            if(visited[i]==false && mark[i]==true){
                return false;
            }
        }
        
        return true;
    }
  public:
    int isCircle(vector<string> &arr) {
        // code here
        vector<int> adj[26];
        vector<int> indegree(26,0), outdegree(26,0);
        vector<bool> mark(26,false);
        
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            string s = arr[i];
            
            int u = s[0] - 'a';
            int v = s.back() - 'a';
            
            mark[u] = true;
            mark[v] = true;
            
            indegree[u]++;
            outdegree[v]++;
            
            adj[u].push_back(v);
        }
        
        for(int i = 0;i<26;i++){
            if(indegree[i]!=outdegree[i]){
                return false;
            }
        }
        
        return isConnected(arr[0][0] - 'a',mark,adj);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends