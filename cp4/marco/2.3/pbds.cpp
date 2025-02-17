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
    int n = 10;
    int A[] = {2, 4, 7, 10, 15, 15, 23, 50, 65, 71};
    
    ost tree; // Create an ordered set (PBDS)
    
    // Insert elements into the tree
    for (int i = 0; i < n; ++i) {
        //using pairs to allow duplicates, for unique values through indexing
        tree.insert(pair(A[i], i));
    }
    
    // O(log n) select
    cout << tree.find_by_order(0)->first << "\n";     // 1-smallest = 2
    cout << tree.find_by_order(n - 1)->first << "\n"; // 9-smallest/largest = 71
    cout << tree.find_by_order(4)->first << "\n";     // 5-smallest = 15
    
    // O(log n) rank
    cout << tree.order_of_key(pair(2, 0)) << "\n";  // Index 0 (rank 1)
    cout << tree.order_of_key(pair(71, 0)) << "\n"; // Index 8 (rank 9)
    cout << tree.order_of_key(pair(15, 0)) << "\n"; // Index 4 (rank 5)
    
    cout << tree.order_of_key(pair(66, 0)) << "\n"; // not present, behaves as upper bound
    cout << tree.order_of_key(pair(88, 0)) << "\n"; //si se pasa, idx q rebasa
    cout << tree.order_of_key(pair(14, 0)) << "\n"; //si se pasa, idx q rebasa
    cout << tree.order_of_key(pair(0, 0)) << "\n"; //si se pasa, idx q rebasa
    
    return 0;
}
