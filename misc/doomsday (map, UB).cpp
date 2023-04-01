#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m,k,t;
  vector<int> people;
  set<int> bunker;
  map<int,int> bunk;
  
  cin>>n>>m>>k>>t;
  
  while (n){
    int p;
    cin>>p;
    people.push_back(p);
    n--;
  }

  while (m){
    int b;
    cin>>b;
    bunker.insert(b);
    bunk[b]+=k;
    m--;
  }
  
  sort(people.begin(), people.end());  

  int alive=0;
  for (int x:people){
    set<int>::iterator itr;
    int lower=x-t;
    int upper=x+t;

    itr = bunker.upper_bound(lower-1);

    while (*itr<=upper and bunker.size()!=0){
      if (itr == bunker.end()) break;

      if (bunk[*itr]>0){
        bunk[*itr]-=1;
        alive++;
        break;
      }
      else{
        bunker.erase(itr);
        // ++itr;
        itr = bunker.upper_bound(*itr);     
      }
    }
  }
  cout<<alive;
}