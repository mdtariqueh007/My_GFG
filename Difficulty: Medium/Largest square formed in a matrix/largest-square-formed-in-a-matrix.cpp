//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here\
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        int maxi = 0;
        
        for(int i = 0;i<n;i++){
            if(mat[i][0]==1){
                dp[i][0] = 1;
                maxi = 1;
            }
        }
        
        for(int j = 0;j<m;j++){
            if(mat[0][j]==1){
                dp[0][j] = 1;
                maxi = 1;
            }
        }
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(mat[i][j]==0){
                    continue;
                }
                
                dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                
                maxi = max(maxi,dp[i][j]);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends