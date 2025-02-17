#include <bits/stdc++.h>
using namespace std;

typedef vector<long long int> vll;

class UnionFind {                                // OOP style
public:
  vll p, setSize, setSums;                           // vi p is the key part
  map<int,int>setAlias;
  int nextIdx;
  
  UnionFind(int N) {
    p.resize(N); for (int i = 0; i < N; i++) p[i] = i;
    setSize.assign(N, 1);                        // optional feature

    nextIdx = N;
    setSums.assign(N, 0); for (int i = 0; i < N; ++i) setSums[i] = i+1;
    for (int i = 0; i < N; ++i) setAlias[i] = i;
  }

  int findSet(int i, bool first) { 
    if (first) {
      i = setAlias[i];
    }
    return (p[i] == i) ? i : (p[i] = findSet(p[i], false)); }

  bool isSameSet(int i, int j) {
    return findSet(i, true) == findSet(j, true); 
  }

  int sizeOfSet(int i) {return setSize[findSet(i, true)]; } // optional
  long long int sumOfSet(int i) {return setSums[findSet(i, true)]; }
  /*
  1,2,3
  par
  1->1
  2->2
  3->3

  union(1,2)
  par
  1->1
  2->1
  3->3

  move(1,3)
  par
  1->1 (dead)
  2->1
  3->3
  4->3
  */
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    // cout<<"unionSet from i "<<i<<" to j "<<j<<endl;
    // i = setAlias[i];
    // j = setAlias[j];
    // cout<<"turned into i "<<i<<" to j "<<j<<endl;
    int x = findSet(i, true), y = findSet(j, true);          // find both rep items
    
    if(setSize[x]>setSize[y]) swap(x,y);
    p[x] = y;                                    // set x under y
    setSize[y] += setSize[x];                    // combine set sizes at y
    setSums[y] += setSums[x];
  }
  
  void unionMove(int i, int j) {
    // cout<<"unionMove from i "<<i<<" to j "<<j<<endl;
    /*
      setAlias[1] = 5
      setAlias[2] = 2 
    */
    

    /*
    1-->5
    2-->2
    */
    // cout<<"turned into i "<<i<<" to j "<<j<<endl;

    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i, true), y = findSet(j, true);          // find both rep items
    // p[i] = y;                                    // set x under y
    setSize[x]--;                                // combine set sizes at y
    setSums[x] -= i+1;

    p.push_back(nextIdx);
    setSize.push_back(1);
    setSums.push_back(i+1); //value of element through idx
    /*
    setAlias[5] = 6;
    */
    setAlias[i] = nextIdx; // update new idx for ghost
    setAlias[nextIdx] = nextIdx; 
    nextIdx++;
  

    unionSet(nextIdx-1, j);
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
                uf.unionMove(aux2-1, aux3-1);
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
            // cout<<endl<<"-- Find set per Idx--"<<endl;
            // for(int i = 0 ; i<X ; i++){
            //     cout<<i+1<<" "<<uf.findSet(i, true)+1<<endl;
            // }
            // cout<<endl<<"---"<<endl;
            // cout<<endl<<"-- Upd Idx--"<<endl;
            // for(auto&e : uf.setAlias){
            //     cout<<e.first+1<<" "<<e.second+1<<endl;
            // }
            // cout<<endl<<"---"<<endl;
        }
    }
    return 0;
}
