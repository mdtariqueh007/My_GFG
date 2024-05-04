//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    private:
    Node* helper(int in[],int post[],int n,int is, int ie,int& postIndex,unordered_map<int,int>&mp){
        if(is>ie){
            return NULL;
        }
        
        int inIndex = mp[post[postIndex]];
        Node* root = new Node(post[postIndex]);
        
        postIndex--;
        
        root->right = helper(in,post,n,inIndex+1,ie,postIndex,mp);
        root->left = helper(in,post,n,is,inIndex - 1,postIndex, mp);
        
        return root;
    }
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        unordered_map<int,int> mp;
        
        for(int i = 0;i<n;i++){
            mp[in[i]] = i;
        }
        
        int postIndex = n - 1;
        
        return helper(in,post,n,0,n-1,postIndex,mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends