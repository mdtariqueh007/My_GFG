//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long int MaxDotProduct(int A[], int B[], int m, int n)
{
    long long int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
 
    // Traverse through all elements of B[]
    for (int i=1; i<=n; i++)
 
        // Consider all values of A[] with indexes greater
        // than or equal to i and compute dp[i][j]
        for (int j=i; j<=m; j++)
 
            // Two cases arise
            // 1) Include A[j]
            // 2) Exclude A[j] (insert 0 in B[]) 
            dp[i][j] = max((dp[i-1][j-1] + (A[j-1]*B[i-1])) ,
                            dp[i][j-1]);
 
    // return Maximum Dot Product
    return dp[n][m] ;
}
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		return MaxDotProduct(a,b,n,m);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends