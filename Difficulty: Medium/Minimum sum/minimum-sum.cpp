//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  string removeZero(string str) 
{ 
    // Count leading zeros 
    int i = 0; 
    while (str[i] == '0') 
        i++; 
  
    // The erase function removes i characters 
    // from given index (0 here) 
    str.erase(0, i); 
  
    return str; 
} 

string findSum(string str1, string str2) 
{ 
    // Remove leading zeros from both strings
    str1.erase(0, min(str1.find_first_not_of('0'), str1.size()-1));
    str2.erase(0, min(str2.find_first_not_of('0'), str2.size()-1));
 
    // If both strings become empty, return "0"
    if (str1.empty() && str2.empty()) 
        return "0";
 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
 
    // Take an empty string for storing result 
    string str = ""; 
 
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
 
    // Initially take carry zero 
    int carry = 0; 
 
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                (str2[i+diff]-'0') + 
                carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
 
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
 
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
 
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
 
    return str; 
} 
    string minSum(vector<int> &arr) {
        // code here
        
        string s, t;
        
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i<arr.size();i++){
            if(i%2==0){
                s.push_back(arr[i]+'0');
            }
            else{
                t.push_back(arr[i]+'0');
            }
        }
        
        s = removeZero(s);
        t = removeZero(t);
        
        // cout<<s<<" "<<t<<"\n";
        
        return findSum(s,t);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends