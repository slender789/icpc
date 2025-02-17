#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
  vi ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vi &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vi &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vi f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  int rsq(int j) {                                // returns RSQ(1, j)
    int sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  int rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, int v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(int k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};


int main() {
    int tc;
    cin>>tc;
    while(tc--){
      int n, q, aux;
      cin>>n>>q;
      int nextIdx = n + 1;
      unordered_map<int,int>movieToIdx;
      for(int i = 1 ; i<=n ; i++){
        movieToIdx[i] = n-i+1;
      }
      vi bits((100000*2)+2);
      for(int i = 1 ; i<=n ; i++){
        bits[i] = 1;
      }
      // bits.assign(n+1, 1);
      // bits[0] = 0; //first element is always zero
      FenwickTree ft(bits);
      
      // cout<<"bits ";
      // for(int i = 0 ; i<bits.size() ; i++){
      //   cout<<bits[i]<<" ";
      // }
      // cout<<endl;
      
      for(int i = 0 ; i<q ; i++){
        cin>>aux;
        // cout<<"received aux "<<aux<<endl;
        int moviesIdx = movieToIdx[aux];
        // cout<<"linked to idx "<<moviesIdx<<endl;
        cout<<ft.rsq(moviesIdx, bits.size()-1)-1<<" ";
        ft.update(moviesIdx, -1);
        ft.update(nextIdx, 1);
        // cout<<"wiint link to "<<nextIdx<<endl;
        movieToIdx[aux] = nextIdx;
        nextIdx++;
      }
      // for(auto& e : movieToIdx){
      //   cout<<e.first<<" "<<e.second<<endl;
      // }
      cout<<endl;
    }
    return 0;
}
