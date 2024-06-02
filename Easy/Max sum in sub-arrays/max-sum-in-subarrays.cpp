//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        
        long long maxScore = 0;
        
        
        
        // for(int i = 0;i<N;i++){
        //     long long smallest = arr[i];
        //     long long secondSmallest = 1e18;
            
        //     long long sum = 0;
            
        //     for(int j = i + 1;j<N;j++){
        //         if(arr[j]<smallest){
        //             secondSmallest = smallest;
        //             smallest = arr[j];
        //         }
        //         else if(arr[j]>smallest && arr[j]<secondSmallest){
        //             secondSmallest = arr[j];
        //         }
        //         else if(arr[j]==smallest){
        //             secondSmallest = arr[j];
        //         }
                
                
                
        //         sum = smallest + secondSmallest;
                
        //         maxScore = max(maxScore,sum);
        //     }
        // }
        
        // return maxScore;
        
        for(int i = 1;i<N;i++){
            long long sum = arr[i] + arr[i-1];
            
            maxScore = max(maxScore,sum);
        }
        
        return maxScore;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends