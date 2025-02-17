#include <bits/stdc++.h>
#include <bits/extc++.h> // For PBDS
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<long long int, long long int>, null_type, 
    less<pair<long long int, long long int>>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> ost;

int main() {
    long long int tc, aux, n;
    cin >> tc;
    while(tc--){
        cin>>n;
        ost tree;
        long long int sum = 0;
        for(long long int i = 0;i<n;i++){
            cin>>aux;
            tree.insert({aux, i});
            long long int size = tree.size();
            if(size % 2 == 0){
                sum += (tree.find_by_order(size/2)->first + tree.find_by_order((size-1)/2)->first)/2;
                // cout << "p res " << (s[size/2] + s[(size-1)/2])/2 <<" for size "<<size<<endl;
            } else {
                sum += tree.find_by_order(size/2)->first;
                // cout << "i res " << s[size/2] <<" for size "<<size<<endl;
            }
        }
        cout<<sum<<endl;
        // cout<<endl;
    }

    return 0;
}
