//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n = mat.size();
         
         vector<int> adj[2*n-1];
         
         for(int i = 0;i<n;i++){
             for(int j = 0;j<n;j++){
                 adj[i+j].push_back(mat[i][j]);
             }
         }
         
         vector<int> ans;
         
         bool flag = false;
         
         for(int i = 0;i<=2*n-2;i++){
             if(!flag){
                 reverse(adj[i].begin(),adj[i].end());
             }
             
             for(auto it : adj[i]){
                 ans.push_back(it);
             }
             
             flag = !flag;
         }
         
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends