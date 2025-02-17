#include <bits/stdc++.h>
#include <bits/extc++.h> // For PBDS
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int, int>, null_type, 
    less<pair<int, int>>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> ost;

int main() {
    ost tree; // Create an ordered set (PBDS)
    string aux;
    int i = 0;
    while(cin>>aux){
        // cout<<"size "<<tree.size()<<endl;
        if (aux == "#") {
            if (tree.size() % 2 == 0){
                auto i = tree.find_by_order((tree.size())/2);
                cout<<i->first<<endl;
                tree.erase(*i);
            } else {
                auto i = tree.find_by_order((tree.size()/2));
                cout<<i->first<<endl;
                tree.erase(*i);
            }
        } else {
            tree.insert({stoi(aux), i});
            i++;
        }
    }
    return 0;
}
