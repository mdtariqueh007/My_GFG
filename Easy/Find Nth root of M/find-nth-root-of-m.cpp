//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int func(long long mid,long long n,long long m){
        long long ans = 1;
        
        for(int i = 1;i<=n;i++){
            ans = ans * mid;
            if(ans>m){
                return 2;
            }
        }
        
        if(ans==m){
            return 1;
        }
        
        return 0;
    }
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    long long low = 1, high = m, ans = -1;
	    
	    while(low<=high){
	        long long mid = low + (high-low)/2;
	        
	        int val = func(mid,n,m);
	        
	        if(val==1){
	            return mid;
	        }
	        else if(val==2){
	            high = mid - 1;
	        }
	        else{
	           // ans = mid;
	            low = mid + 1;
	        }
	    }
	    
	    return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends