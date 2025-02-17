// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

int main() {
  UnionFind UF(500001);
  int N, aux, sol = 0;
  cin>>N;
  for(int i = 0 ; i<N ; i++){
    cin>>aux;
    vector<int>cs(aux);
    map<int,int>oc;
    for(int j = 0 ; j<aux ; j++){
      cin>>cs[j];
      oc[UF.findSet(cs[j])]++;
    }
    // for(auto& e : oc){
    //   cout<<e.first<<" "<<e.second<<endl;
    // }
    bool foundSol = true;
    for(int j = 0 ; j<aux ; j++){
      if (UF.sizeOfSet(cs[j]) != oc[UF.findSet(cs[j])]){
          foundSol = false;
          break;
      }
    }
    if(!foundSol)continue;

    // cout<<"foundSol!"<<endl;
    // cout<<"-----"<<endl;
    for(int j = 1 ; j<aux ; j++){
      UF.unionSet(cs[0], cs[j]);
    }
    sol++;
  }
  
  cout<<sol;
  return 0;
}


// store used sets
