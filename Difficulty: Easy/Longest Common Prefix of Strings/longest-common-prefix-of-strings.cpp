//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        
        int ans = arr[0].length();
        
        int n = arr.size();
        
        for(int i = 1;i<n;i++){
            int j = 0;
            
            while(j<arr[i].length() && arr[0][j]==arr[i][j]){
                j++;
            }
            
            ans = min(ans,j);
        }
        
        if(ans==0) return "-1";
        
        return arr[0].substr(0,ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends