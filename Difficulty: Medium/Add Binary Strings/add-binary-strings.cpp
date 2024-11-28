//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& a, string& b) {
        // your code here
        
        if(a.length()>b.length()){
            return addBinary(b,a);
        }

        int diff = b.length()-a.length();

        string padding;
        for(int i = 0;i<diff;i++){
            padding.push_back('0');
        }
        a=padding+a;
        string res;
        char carry = '0';

        for(int i = a.length()-1;i>=0;i--){
            if(a[i]=='1'&&b[i]=='1'){
                if(carry=='1'){
                    res.push_back('1'); 
                    carry='1';
                }
                else{
                    res.push_back('0');
                    carry='1';
                }
            }
            else if(a[i]=='0' && b[i]=='0'){
                if(carry=='1'){
                    res.push_back('1');
                    carry = '0';
                }
                else{
                    res.push_back('0');
                    carry='0';
                }
            }
            else if(a[i]!=b[i]){
                if(carry=='1'){
                    res.push_back('0');
                    carry='1';
                }
                else{
                    res.push_back('1');
                    carry='0';
                }
            }
        }
        if(carry=='1'){
            res.push_back('1');
        }
        
        reverse(res.begin(),res.end());

        int index = 0;
        while((index+1<res.length()) && res[index]=='0'){
            index++;
        }

        return (res.substr(index));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends