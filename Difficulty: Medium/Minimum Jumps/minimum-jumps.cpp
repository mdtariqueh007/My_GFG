//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n = arr.size();
         if(n==1){
            return 0;
        }
        
        if(arr[0]==0){
            return -1;
        }
        if(arr[0]>=n-1){
            return 1;
        }
        
        int jumps = 0, l = 0, r = 0;
        
        int farthest = 0;
        
        while(r<n-1){
            farthest = 0;
            
            for(int i = l;i<=r;i++){
                farthest = max(i+arr[i],farthest);
            }
            
            l = r + 1;
            r = farthest;
            jumps++;
            if(farthest==0) break;
        }
        
        if(farthest<n-1){
            return -1;
        }
        else{
            return jumps;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends