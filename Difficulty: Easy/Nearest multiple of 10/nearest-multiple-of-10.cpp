//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        
        int last = str.back() - '0';
        
        if(last>5){
            str[str.size() - 1] = '0';
            int i = str.size() - 2;
            
            while(i>=0 && str[i]=='9'){
                str[i] = '0';
                i--;
            }
            
            if(i<0){
                str = '1' + str;
            }
            else{
                str[i]++;
            }
            
            return str;
        }
        else{
            str[str.size() - 1] = '0';
            
            return str;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends