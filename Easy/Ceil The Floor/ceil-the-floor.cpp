//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int floorBS(int arr[],int n,int x){
    // int low = 0,high = n - 1, ans = -1;
    
    // while(low<=high){
    //     int mid = low + (high - low)/2;
        
    //     if(arr[mid]<=x){
    //         ans = arr[mid];
    //         low = mid + 1;
    //     }
    //     else{
    //         high = mid - 1;
    //     }
    // }
    
    // return ans;
    int ans = -1e9;
    
    
    for(int i = 0;i<n;i++){
        if(arr[i]<=x){
            ans = max(ans,arr[i]);
        }
    }
    
    return ans==-1e9?-1:ans;
}

int ceilBS(int arr[],int n,int x){
    // int low = 0, high = n - 1, ans = -1;
    
    // while(low<=high){
    //     int mid = low + (high - low)/2;
        
    //     if(arr[mid]>=x){
    //         ans = arr[mid];
    //         high = mid - 1;
    //     }
    //     else{
    //         low = mid + 1;
    //     }
    // }
    
    // return ans;
    int ans = 1e9;
    
    
    for(int i = 0;i<n;i++){
        if(arr[i]>=x){
            ans = min(ans,arr[i]);
        }
    }
    
    return ans==1e9?-1:ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    
    
    int fl = floorBS(arr,n,x);
    int cl = ceilBS(arr,n,x);
    
    return {fl,cl};
}