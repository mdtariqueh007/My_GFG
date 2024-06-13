//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        
        int revA = 0;
        
        int d = floor(log10(n) + 1);
        
        int temp = n;
        
        while(temp>0){
            int dig = temp%10;
            
            temp = temp/10;
            
            revA += pow(dig,d);
        }
        
        return (revA==n)?"Yes":"No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends