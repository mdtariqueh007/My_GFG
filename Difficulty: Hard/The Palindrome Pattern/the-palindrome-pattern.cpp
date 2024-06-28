//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  

    string pattern(vector<vector<int>> &a) {
        // Code Here
        int m =a.size();
      
      // ROW PALINDROME 
     
        for(int i =0;i<m;i++)
        {
            
            
            int l =0;
            int r =m-1;
            
            while(l<=r&&a[i][l]==a[i][r])
            {
                l++;r--;
            }
            
            // 0 1 2 2 1 0 
            if(l>r)
            {
                return to_string(i)+" R";
            }
        }
        
         for(int i =0;i<m;i++)
        {
           
            int l =0;
            int r =m-1;
            
            while(l<=r&&a[l][i]==a[r][i])
            {
                l++;r--;
            }
            
            if(l>r)
            {
                return to_string(i)+" C";
            }
        }
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends