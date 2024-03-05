//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        stack<pair<int,int>> st;
        
        for(int i = n-1;i>=0;i--){
            if(st.empty() || st.top().second<a[i]){
                st.push({i,a[i]});
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().second>=a[i]){
                ans = max(ans,st.top().first-i);
                st.pop();
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends