//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int timer = 0;
    void dfs(int node,int parent,vector<int> adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,set<int>&artPoint){
        vis[node] = 1;
        
        tin[node] = timer;
        low[node] = timer;
        
        timer++;
        
        int child = 0;
        
        for(int it : adj[node]){
            if(it==parent) continue;
            
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,artPoint);
                
                low[node] = min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent!=-1){
                    artPoint.insert(node);
                }
                
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        
        if(child>1 && parent==-1){
            artPoint.insert(node);
        }
    }
  public:
    int biGraph(int arr[], int n, int e) {
        // code here
        vector<int> adj[n];
        
        for(int i = 0;i<2*e;i= i + 2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        
        vector<int> tin(n,0),low(n,0),vis(n,0);
        
        set<int> artPoint;
        
        dfs(0,-1,adj,vis,tin,low,artPoint);
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        
        return artPoint.size()==0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}
// } Driver Code Ends