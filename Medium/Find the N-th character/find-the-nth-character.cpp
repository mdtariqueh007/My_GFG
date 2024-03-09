//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        // string temp = "";
        
        // int R = r;
        
        // for(int i = 0;i<s.length()&&r>0;i++){
        //     if(s[i]=='1'){
        //         temp += "10";
        //     }else{
        //         temp += "01";
        //     }
        //     r--;
        // }
        
        // if(s.length()<R){
            
        // }
        
        // return temp[n-1];
        // string temp = "";
        
        // temp = s;
        
        // while(r--){
        
        //     string str = "";
        //     for(int i = 0;i<temp.length();i++){
        //         if(temp[i]=='1'){
        //             str += "10";
        //         }else{
        //             str += "01";
        //         }
        //     }
            
        //     temp = str;
            
        // }
        
        // return temp[n];
        
        // int N = s.length();
        
        // int times = (1<<r);
        
        // int ind = -1;
        
        
        // for(int i = 0;i<N;i++){
        //     if((i+1)<=times){
        //         ind = i;
        //         break;
        //     }
        // }
        
        // string str = "";
        // str += s[ind];
    
        // while(r--){
        //     string temp = "";
        //     for(int i = 0;i<str.length();i++){
        //     if(str[i]=='1'){
        //         temp += "10";
        //     }
        //     else{
        //         temp += "01";
        //     }
        //     }
            
        //     str = temp;
        // }
        
        // return str[n-ind];
        
        while(r--){
            string temp = "";
            
            for(int i = 0;i<s.length();i++){
                if(s[i]=='1'){
                    temp += "10";
                }else{
                    temp += "01";
                }
                 if(temp.length()>n){
                break;
                }
            }
            
            
           
            s = temp;
        }
        
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends