//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node{
    public:
    map<char, Node*> children;
    bool isEnd = false;
    int freq = 0;
};

class AutoCompleteSystem {
    Node* root;
    string curr;
public:
 
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        // write code for constructor
        root = new Node();
        
        curr = "";
        
        for(int i = 0;i<sentences.size();i++){
            insert(sentences[i],times[i]);
        }
    }
    
    
    void insert(string s, int t){
        Node* node = root;
        
        for(char c : s){
            if(node->children[c]==NULL){
                node->children[c] = new Node();
            }
            node = node->children[c];
        }
        
        node->isEnd = true;
        node->freq += t;
    }
    
    void search(Node* node, string s, vector<pair<int,string>>&sentences){
        if(node->isEnd){
            sentences.push_back({node->freq,s});
        }
        
        for(auto &child:  node->children){
            search(child.second, s + child.first, sentences);
        }
    }
    
    vector<string> input(char c) {
        // write code to return the top 3 suggestions when the current character in the stream is c
        // c == '#' means , the current query is complete and you may save the entire query into
        // historical data
        
        if(c=='#'){
            insert(curr,1);
            curr = "";
            
            return {};
            
        }
        
        curr += c;
        Node* node = root;
        vector<pair<int,string>> sentences;
        
        for(char ch : curr){
            if(node->children[ch]==NULL){
                return {};
            }
            
            node = node->children[ch];
        }
        
        search(node,curr,sentences);
        
        sort(sentences.begin(),sentences.end(),[](pair<int,string>&a , pair<int,string>&b){
            return a.first>b.first || (a.first==b.first && a.second<b.second);
        });
        
        vector<string> res;
        
        for(int i = 0;i<min(3,(int)sentences.size());i++){
            res.push_back(sentences[i].second);
        }
        
        return res;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


//{ Driver Code Starts.

int main() {

    int t;
	cin >> t;
    cin.ignore();
    while(t--) {
		int n;
		cin>>n;
        cin.ignore();
        vector<string> sentences(n);
		vector<int> times(n);
		for (int i = 0; i < n; ++i){
            
			getline(cin,sentences[i]);
			cin>>times[i];
            cin.ignore();
		}
		AutoCompleteSystem *obj = new AutoCompleteSystem(sentences,times);
		int q;
		cin>>q;
        cin.ignore();

		for (int i = 0; i < q; ++i){
			string query;
			getline(cin,query);
            string qq = "";
            for(auto &x:query){
			    qq+=x;
                vector<string> suggestions = obj->input(x);
                if(x=='#')
                    continue;
                cout<<"Typed : \""<<qq<<"\" , Suggestions: \n";
				for(auto &y:suggestions){
					cout<<y<<"\n";
				}
			}
		}
	}
	return 0;
}




// } Driver Code Ends