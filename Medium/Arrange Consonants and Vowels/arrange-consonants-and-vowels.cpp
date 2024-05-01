//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        unordered_set<char> st({'a','e','i','o','u'});
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* vowel = new Node('$');
        Node* cons = new Node('$');
        
        Node* temp1 = vowel;
        Node* temp2 = cons;
        
        for(Node* curr = head;curr!=NULL;curr = curr->next){
            if(st.find(curr->data)!=st.end()){
                temp1->next = new Node(curr->data);
                temp1 = temp1->next;
            }else{
                temp2->next = new Node(curr->data);
                temp2 = temp2->next;
            }
        }
        
        temp1->next = cons->next;
        
        return vowel->next;
        
        
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends