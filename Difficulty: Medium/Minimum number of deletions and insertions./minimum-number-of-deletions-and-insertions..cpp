//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    private:
    int LCS(string &str1, string &str2){
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
        
        
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int lcs = LCS(str1,str2);
	    
	    return (str1.length() - lcs) + (str2.length() - lcs);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends