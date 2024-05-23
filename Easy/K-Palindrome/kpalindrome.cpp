//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int dp[1001][1001];
    int lcs(int i,int j, string&s, string&t){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return dp[i][j] = 1 + lcs(i-1,j-1,s,t);
        }
        else{
            return dp[i][j] = max(lcs(i-1,j,s,t),lcs(i,j-1,s,t));
        }
    }
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        string rev = str;
        reverse(rev.begin(),rev.end());
        int x = lcs(n-1,n-1,str,rev);
        
        return (n-x)<=k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends