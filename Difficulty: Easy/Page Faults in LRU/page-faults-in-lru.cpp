//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int  n, int c, int pages[]){
        // code here
        
        list<int> cache;
        unordered_map<int,list<int>::iterator> mp;
        
        int cnt = 0;
        
        // for(int i = 0;i<c;i++){
        //     cache.push_back(pages[i]);
        //     mp[pages[i]] = prev(cache.end());
        //     cnt++;
        // }
        
        for(int i = 0;i<n;i++){
            if(cache.size()<c){
                if(mp.find(pages[i])==mp.end()){
                    cache.push_back(pages[i]);
                    mp[pages[i]] = prev(cache.end());
                    cnt++;
                }
                else{
                    
                    list<int>::iterator it = mp[pages[i]];
                cache.erase(it);
                
                cache.push_back(pages[i]);
                mp[pages[i]] = prev(cache.end());
                    
                }
                
                continue;
            }
            if(mp.find(pages[i])==mp.end()){
                cnt++;
                // if(cache.size()==c){
                mp.erase(*cache.begin());
                cache.pop_front();
                
                cache.push_back(pages[i]);
                mp[pages[i]] = prev(cache.end());
                
                // else{
                    
                // }
            }
            else{
                list<int>::iterator it = mp[pages[i]];
                cache.erase(it);
                
                cache.push_back(pages[i]);
                mp[pages[i]] = prev(cache.end());
            }
        }
        
        return cnt;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends