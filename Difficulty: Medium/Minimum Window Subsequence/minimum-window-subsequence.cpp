//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        
        // Write your Code here
        
        
        if(str2.length()>str1.length()){
            return "";
        }
        
        int mini = str1.length();
        
        int end;
        
        string window = "";
        
        int j = 0;
        for(int i = 0;i<str1.length();i++){
            if(str1[i]==str2[j]){
                j++;
            }
            
            if(j==str2.length()){
                
                end = i;
                j--;
                
                while(j>=0){
                    if(str1[i]==str2[j]){
                        j--;
                    }
                    i--;
                }
                
                i++;
                j++;
                
                if(end - i + 1<mini){
                    mini = end - i + 1;
                    window = str1.substr(i,end - i + 1);
                }
                
            }
        }
        
        return window;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends