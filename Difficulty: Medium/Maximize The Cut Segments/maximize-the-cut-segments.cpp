//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    private:
    int dp[10001];
    int solve(int n,int x,int y,int z){
        if(n==0){
            return 0;
        }
        
        if(n<0){
            return -1e9;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int cutX = 1 + solve(n-x,x,y,z);
        int cutY = 1 + solve(n-y,x,y,z);
        int cutZ = 1 + solve(n-z,x,y,z);
        
        return dp[n] = max({cutX,cutY,cutZ});
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        memset(dp,-1,sizeof(dp));
        
        
        int ans =  solve(n,x,y,z);
        
        
        if(ans<0){
            return 0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends