//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int N) {
        // code here
        
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N-i;j++){
                cout<<" ";
            }
            
            for(int j = 1;j<=2*i - 1;j++){
                cout<<"*";
            }
            
            for(int j = 1;j<=N-i;j++){
                cout<<" ";
            }
            
            cout<<"\n";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends