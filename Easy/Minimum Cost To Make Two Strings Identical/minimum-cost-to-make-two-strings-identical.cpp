//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int LCS(string text1, string text2) {
        int n = text1.length(),m= text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][m]; 
        // return f(n,m,text1,text2,dp);
    }
  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n = x.length();
        int m = y.length();
        
       
        int l = LCS(x,y);
        
        int cost = (n-l)*costX + (m-l)*costY;
        
        return cost;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends