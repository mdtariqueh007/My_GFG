//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int dp[1001][1001];
    int solve(int ind,int price[],int n,int rodLen){
        if(rodLen==0){
            return 0;
        }
        
        if(ind==n){
            return -1e9;
        }
        
        if(dp[ind][rodLen]!=-1){
            return dp[ind][rodLen];
        }
        
        int notCut = solve(ind+1,price,n,rodLen);
        int cut = -1e9;
        if(rodLen>=ind+1){
            cut = price[ind] + solve(ind,price,n,rodLen-(ind+1));
        }
        
        return dp[ind][rodLen] = max(cut,notCut);
        
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        return solve(0,price,n,n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends