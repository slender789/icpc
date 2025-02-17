#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
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
    long long int size, q, aux;
    int a1, a2 , a3;
    string auxStr;
    unordered_map<int, int>gemToVal;
    
    cin>>size>>q;
    vector<vll>allGems(6, vll(size+1));
    vll gems(size+1);
    for(int i = 1 ; i <= 6 ; i++){
        cin>>aux;
        gemToVal[i] = aux;
    }
    cin>>auxStr;
    for(int i = 0 ; i < auxStr.size() ; i++){
        int incGem = auxStr[i] - '0';
        for(int j = 0 ; j < 6 ; j++){
            if (incGem == j+1) allGems[j][i+1] = 1;
        }
    }

    vector<FenwickTree>allFT;
    for(int j = 0 ; j < 6 ; j++){
        allFT.push_back(FenwickTree(allGems[j]));
    };

    for(int i = 0 ; i < q ; i++){
        cin>>a1>>a2 >>a3;
        if(a1 == 1){
            //idx a2 to type a3
            for(int j = 0 ; j < 6 ; j++){
                if (allFT[j].rsq(a2, a2) == 1) {
                    allFT[j].update(a2, -1);
                }
            };            
            allFT[a3-1].update(a2, 1);
        }
        if(a1 == 2){
            //type a2 to val a3
            gemToVal[a2] = a3;
        }
        if(a1 == 3){
            long long int sum = 0;
            for(int j = 0 ; j < 6 ; j++){
                sum += allFT[j].rsq(a2, a3) * gemToVal[j+1];
            };
            cout<<sum<<endl;
        }
    }

  return 0;
}
