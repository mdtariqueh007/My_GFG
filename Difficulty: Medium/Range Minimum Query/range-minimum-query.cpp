//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */

void buildSegTree(int i,int l,int r,int arr[],int segTree[]){
    if(l==r){
        segTree[i] = arr[l];
        return;
    }
    
    
    int mid = l + (r-l)/2;
    
    buildSegTree(2*i+1,l,mid,arr,segTree);
    buildSegTree(2*i+2,mid+1,r,arr,segTree);
    
    segTree[i] = min(segTree[2*i+1],segTree[2*i+2]);
}


int *constructST(int arr[],int n)
{
  //Your code here
  int *segTree = new int[4*n];
  
  buildSegTree(0,0,n-1,arr,segTree);
  
  return segTree;
}


/* The functions returns the
 min element in the range
 from a and b */
 
int query(int start,int end,int i,int l,int r,int segTree[]){
    if(l>end || r<start){
        return INT_MAX;
    }
    
    if(l>=start && r<=end){
        return segTree[i];
    }
    
    int mid = l + (r-l)/2;
    
    return min(query(start,end,2*i+1,l,mid,segTree),query(start,end,2*i+2,mid+1,r,segTree));
}
 
int RMQ(int st[] , int n, int a, int b)
{
//Your code here

return query(a,b,0,0,n-1,st);
}