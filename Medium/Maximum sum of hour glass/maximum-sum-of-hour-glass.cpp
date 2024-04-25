//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int m, int n, vector<vector<int>> grid) {
        // code here
        int ans = -1;

        for(int i = 0;i<m-2;i++){
            for(int j = 0;j<n-2;j++){
                int sum = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                sum += grid[i+1][j+1];
                sum += grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

                ans = max(ans,sum);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends