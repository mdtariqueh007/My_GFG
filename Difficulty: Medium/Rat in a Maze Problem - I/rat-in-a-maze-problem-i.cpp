//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void helper(int i,int j,vector<vector<int>>&mat,vector<string>&ans,string curr,vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==0 || vis[i][j]==1){
            return;
        }
        
        if(i==mat.size()-1 && j==mat[0].size()-1){
            ans.push_back(curr);
            return;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        char dir[] = {'U','D','L','R'};
        
        for(int k = 0;k<4;k++){
            vis[i][j] = 1;
            helper(i+dx[k],j+dy[k],mat,ans,curr + dir[k],vis);
            vis[i][j] = 0;
        }
        
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        
        vector<string> ans;
        
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        
        helper(0,0,mat,ans,"",vis);
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends