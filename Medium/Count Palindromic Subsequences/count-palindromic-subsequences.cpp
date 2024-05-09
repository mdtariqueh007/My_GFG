//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long int dp[1001][1001];
    const int mod = 1e9+7;
    long long int f(int i,int j,string&str){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(str[i]==str[j]){
            return dp[i][j] = (1 + f(i+1,j,str)+f(i,j-1,str))%mod;
        }else{
            return dp[i][j] = (f(i+1,j,str)+f(i,j-1,str)-f(i+1,j-1,str)+mod)%mod;
        }
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.length();
       
       memset(dp,-1,sizeof(dp));
       
       return f(0,n-1,str);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends