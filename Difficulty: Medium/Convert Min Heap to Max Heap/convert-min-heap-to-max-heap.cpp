//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void Heapify(int i,vector<int>&arr){
        int n = arr.size();
        
        int maxi = i;
        
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left<n && arr[left]>arr[maxi]){
            maxi = left;
        }
        if(right<n && arr[right]>arr[maxi]){
            maxi = right;
        }
        
        if(maxi!=i){
            swap(arr[maxi],arr[i]);
            Heapify(maxi,arr);
        }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int n){
        for(int i = (n-2)/2 + 1;i>=0;i--){
            Heapify(i,arr);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends