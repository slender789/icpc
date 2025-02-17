#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<int> vvi;

class UnionFind {
private:
    vector<int> p, rank, setSize, setSum;       // Added setSum to track sum of set values
    int numSets;

public:
    UnionFind(int N) {
        p.assign(N, 0); 
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                      
        setSize.assign(N, 1);                   
        setSum.assign(N, 0);                    // Each setSum[i] starts as the unique value at index i
        for (int i = 0; i < N; ++i) setSum[i] = i+1; 
        numSets = N;                           
    }

    int findSet(int i) { 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    int numDisjointSets() { 
        return numSets; 
    }

    int sizeOfSet(int i) { 
        return setSize[findSet(i)]; 
    }

    int sumOfSet(int i) { 
        return setSum[findSet(i)]; 
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;             
        int x = findSet(i), y = findSet(j);      
        if (rank[x] > rank[y]) swap(x, y);       
        p[x] = y;                                
        if (rank[x] == rank[y]) ++rank[y];       
        setSize[y] += setSize[x];                
        setSum[y] += setSum[x];                  // Update the sum of the set
        --numSets;                               
    }

    // New method to move an element from its current set to another set
    void moveElementToSet(int element, int target) {
        int rootElement = findSet(element);
        int rootTarget = findSet(target);

        if (rootElement == rootTarget) return;  // Already in the same set

        // Remove element from current set
        p[element] = element;                   // Detach element as its own root temporarily
        setSize[rootElement]--;                 // Decrease size of old set
        setSum[rootElement] -= element;         // Decrease sum of old set

        // Add element to the new set
        unionSet(element, target);              // Merge element into target set
    }
};

int main() {
    int X, tC;
    int aux1, aux2, aux3;
    while(cin>>X>>tC){
        UnionFind uf = UnionFind(X);
        for(int i = 0 ; i<tC ; i++){
            cin>>aux1>>aux2;
            if (aux1==1){
                cin>>aux3;
                uf.unionSet(aux2-1, aux3-1);
            }
            else if (aux1==2){
                cin>>aux3;
                uf.moveElementToSet(aux2-1, aux3-1);
            }
            else {
                // cout<<"for "<<aux1<<" "<<aux2<<endl;
                cout<<uf.sizeOfSet(aux2-1)<<" "<<uf.sumOfSet(aux2-1)<<endl;
            }
            // cout<<endl<<"---"<<endl;
            // for(auto&e:uf.setSize){
            //     cout<<e<<" ";
            // }
            // cout<<endl<<"---"<<endl;
            // for(auto&e:uf.setSums){
            //     cout<<e<<" ";
            // }
            // cout<<endl<<"---"<<endl;
            // for(int i = 0 ; i<X ; i++){
            //     cout<<i+1<<" "<<uf.findSet(i)+1<<endl;
            // }
            // cout<<endl<<"---"<<endl;
        }
    }
    return 0;
}