//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node] = find(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int pu = find(u);
        int pv = find(v);
        
        
        if(pu==pv){
            return;
        }
        
        
        if(pu<pv){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
        }
    }
};

class Solution 
{
    public:
    bool static comp(Job val1, Job val2){
        return val1.profit>val2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        
        int totProfit = 0, cnt = 0;
        
        int maxDeadline = 0;
        
        for(int i = 0;i<n;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        
        DSU ds(maxDeadline);
        
        for(int i = 0;i<n;i++){
            int node = ds.find(arr[i].dead);
            
            // cout<<"Node : "<<node<<"\n";
            
            if(node>0){
                cnt++;
                totProfit += arr[i].profit;
                
                ds.unionBySize(node-1,node);
            }
        }
        
        // for(auto it : ds.parent){
        //     cout<<it<<"\n";
        // }
        
        return {cnt,totProfit};
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends