#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm> // for std::binary_search // for std::sort // for lower_bound and upper_bound

using namespace std;

int main() {
    // 1. Vector - dynamic array with additional methods
    vector<int> v = {5, 1, 3, 8, 6};

    sort(v.begin(), v.end()); // Sorting vector in ascending order
    cout << "Sorted vector: ";
    for (int x : v) cout << x << " "; // Output: 1 3 5 6 8
    cout << endl;

    v.push_back(10); // Adding an element at the end
    v.pop_back();    // Removing the last element (10)
    v.erase(v.begin()); // Erasing the first element (1)
    v.size();
    v.front(); //return first element
    v.back(); //return last element
    cout << "Vector after pop_back and erase: ";
    for (int x : v) cout << x << " "; // Output: 3 5 6 8
    cout << endl;

    const int value_to_find = 4;
    bool found = binary_search(v.begin(), v.end(), value_to_find);
    if (found) {
        cout << value_to_find << " is present in the sorted vector." << endl;
    } else {
        cout << value_to_find << " is not present in the sorted vector." << endl;
    }

    int value = 30;
    // Find the first element >= value
    vector<int>::iterator lower = lower_bound(v.begin(), v.end(), value);
    if (lower != v.end())
        cout << "Lower bound of " << value << " is at position: " << (lower - v.begin()) << endl;
    
    // Find the first element > value
    vector<int>::iterator upper = upper_bound(v.begin(), v.end(), value);
    if (upper != v.end())
        cout << "Upper bound of " << value << " is at position: " << (upper - v.begin()) << endl;

    // =========================================================================== 

    // 2. Deque - double-ended queue with more operations
    deque<int> d = {10, 20, 30};
    d.push_front(5);  // Adding element at the front
    d.push_back(40);  // Adding element at the back

    d.pop_front(); // Removing element from the front
    d.pop_back();  // Removing element from the back
    d.size();

    cout << "Deque after pop_front and pop_back: ";
    for (int x : d) cout << x << " "; // Output: 20 30
    cout << endl;

    // =========================================================================== 

    // 3. Map - ordered key-value pairs
    map<string, int> mp;
    mp["apple"] = 3;
    mp["banana"] = 5;
    mp["orange"] = 2;

    map<string, int>::iterator it = mp.find("banana"); // Finding a key in the map
    if (it != mp.end()) {
        cout << "Found banana, value = " << it->second << endl; // Output: 5
        mp.erase(it); // Erase key-value pair for "banana"
    }
    
    cout << "Map after erasing 'banana':" << endl;
    for (pair<string, int> p : mp) {
        cout << p.first << ": " << p.second << endl; // Output: apple: 3, orange: 2
    }

    // sort by val
    // Vector to store pairs of the map
    vector<pair<string, int>> vec(mp.begin(), mp.end());

    // Sorting the vector based on the values of the map
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; // Compare based on the value (second element of pair)
    });

    // =========================================================================== 

    // 4. Set - unique sorted elements with additional operations
    set<int> s = {4, 1, 9, 1, 3}; // Duplicates are ignored

    s.insert(2); // Insert element
    s.erase(4);  // Erase element 4
    s.size();

    if (s.find(2) != s.end()) { // Finding an element
        cout << "2 is in the set" << endl; // Output: 2 is in the set
    }
    
    cout << "Set elements after insert and erase: ";
    for (int x : s) cout << x << " "; // Output: 1 2 3 9
    cout << endl;

    multiset<int> ms = {4, 1, 9, 1, 3}; // Duplicates are present

    ms.insert(2); // Insert element
    ms.erase(4);  // Erase element 4
    ms.count(4); // times in multiset
    ms.size();

    if (ms.find(2) != ms.end()) { // Finding an element
        cout << "2 is in the set" << endl; // Output: 2 is in the set
    }

    int multiset_value = 30;
    // lower_bound: finds the first element >= value
    multiset<int>::iterator ms_lower = s.lower_bound(multiset_value);
    if (ms_lower != s.end())
        cout << "Lower bound of " << multiset_value << " is: " << *ms_lower << endl;
    
    // upper_bound: finds the first element > value
    multiset<int>::iterator ms_upper = s.upper_bound(multiset_value);
    if (ms_upper != s.end())
        cout << "Upper bound of " << multiset_value << " is: " << *ms_upper << endl;

    // =========================================================================== 

    // 5. Unordered_map - hash table based key-value pairs
    unordered_map<string, int> um;
    um["cat"] = 1;
    um["dog"] = 2;
    um["bird"] = 3;

    um.erase("dog"); // Erasing key-value pair for "dog"

    cout << "Unordered map after erasing 'dog':" << endl;
    for (unordered_map<string, int>::iterator p = um.begin(); p != um.end(); ++p) {
        cout << p->first << ": " << p->second << endl; // Output: cat: 1, bird: 3
    }

    // =========================================================================== 

    // 6. Stack - LIFO structure with additional methods
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: " << st.top() << endl; // Output: 30
    st.pop(); // Removing the top element
    cout << "Stack top after pop: " << st.top() << endl; // Output: 20

    // =========================================================================== 

    // 7. Queue - FIFO structure with more operations
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue front: " << q.front() << endl; // Output: 1
    q.pop(); // Remove front element
    cout << "Queue front after pop: " << q.front() << endl; // Output: 2

    // =========================================================================== 

    // 8. Priority Queue - max heap (largest element first) by default with more operations
    priority_queue<int> pq;
    pq.push(50);
    pq.push(10);
    pq.push(30);

    cout << "Priority queue top (max heap): " << pq.top() << endl; // Output: 50
    pq.pop();
    cout << "Priority queue top after pop: " << pq.top() << endl; // Output: 30

    // Min heap priority queue (smallest element first)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(50);
    minHeap.push(10);
    minHeap.push(30);

    cout << "Priority queue top (min heap): " << minHeap.top() << endl; // Output: 10
    minHeap.pop();
    cout << "Priority queue top after pop: " << minHeap.top() << endl; // Output: 30

    return 0;
}
