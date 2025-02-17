#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define limite 1000001

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v): val(v){}
    void insert(Node* n){
        if(n->val < val){
            if (left == nullptr) {
                left = n;
            } else {
                left->insert(n);
            }
        } else {
            if (right == nullptr) {
                right = n;
            } else {
                right->insert(n);
            }
        }
    }
};

struct Tree{
    Node* root = nullptr;

    Tree() : root(nullptr) {}

    void insert(Node* n){
        if(root == nullptr){
            root = n;
        } else {
            root->insert(n);
        }
    }

    string inorder(Node* curr){
        string str = "";
        if (curr == nullptr) return str;
        str += 'l'+inorder(curr->left);
        str += 'r'+inorder(curr->right);
        return str;
    }

    string print(){
        return inorder(root);
    }
};


//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unordered_set<string>us;
    int n, m, aux;
    cin >> n >> m;
    while(n--){
        Tree t = Tree();
        vector<Node>v(m, Node(0));
        for(int i = 0 ; i<m ; i++){
            cin >> aux;
            v[i] = Node(aux);
            t.insert(&v[i]);
            // us.insert(t.print());
        }
    }
    cout<<us.size();
    return 0;
}
//--------------------EOSOLUTION---------------------------------