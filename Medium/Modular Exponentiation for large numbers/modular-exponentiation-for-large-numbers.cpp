//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code her
		    if(n==0){
		        return 1;
		    }
		    
		    long long res = 1;
		    
		    
		    while(n>0){
		        if(n&1){
		            res = (res%M * x%M)%M;
		        }
		        
		        x = (x%M*x%M);
		        n = n>>1;
		    }
		    
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends