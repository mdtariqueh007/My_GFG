//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> maxi(n+1,-1e9);
        vector<int> mini(n+1,1e9);
        
        maxi[n-1] = arr[n-1];
        mini[n-1] = arr[n-1];
        
        for(int i = n-2;i>=0;i--){
            maxi[i] = max(maxi[i+1],arr[i]);
            mini[i] = min(mini[i+1],arr[i]);
        }
        
        int maxPrefix = arr[0];
        int minPrefix = arr[0];
        
        int ans = maxi[k] - mini[k];
        
        for(int i = 1;i<n;i++){
            if(i+k<=n){
                
            
                int currMax = max(maxPrefix,maxi[i+k]);
                int currMin = min(minPrefix,mini[i+k]);
                
                ans = min(ans,currMax-currMin);
                
                maxPrefix = max(maxPrefix,arr[i]);
                minPrefix = min(minPrefix,arr[i]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends