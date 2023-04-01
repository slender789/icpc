#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,d,i;
  multiset<int>dolls;
  
  cin>>n;
  
  while (n){
    cin>>d;
    while(d){
      cin>>i;
      dolls.insert(i);
      d--;
    }

    // dolls.sort(dolls.begin(), dolls.end());

    int count=0; 
    multiset<int>::iterator itr;
    multiset<int>::iterator upper;

    while(dolls.size()!=0){
        itr=dolls.begin();
        
        while (itr!=dolls.end()){
            int aux=*itr;
            dolls.erase(itr);
            
            upper = dolls.upper_bound(aux);        
            if ((*upper-aux)!=1){
                break;
            }    
            itr=dolls.upper_bound(aux);
        }
        count++;
    }
    cout<<count<<endl;
    // end
    n--;
    dolls.clear();
  }
}
 