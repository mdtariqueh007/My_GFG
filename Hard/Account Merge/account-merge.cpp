//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU{
    public:
    vector<int> parent,size;
    
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        
        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        
        if(pu==pv){
            return;
        }
        
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        
        DSU ds(n);
        
        unordered_map<string,int> mapMail;
        
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                
                if(mapMail.find(mail)==mapMail.end()){
                    mapMail[mail] = i;
                }else{
                    ds.unionBySize(i,mapMail[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        
        for(auto it : mapMail){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0;i<n;i++){
            if(mergedMail[i].size()==0){
                continue;
            }
            
            sort(mergedMail[i].begin(),mergedMail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends