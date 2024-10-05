#include <bits/stdc++.h>
using namespace std;
vector<long long int> elem;
class segmentTree{
  public: 
  vector<long long int>sT;
    segmentTree(long long int size);
    long long int create(long long int left, long long int right, long long int indice);
    long long int query(long long int left,long long int right,long long int q_left,long long int q_right,long long int ind);
    long long int update(long long int left,long long int right,long long int val,long long int up_index,long long int indice);
    
};

long long int segmentTree::query(long long int left,long long int right,long long int q_left,long long int q_right,long long int indice){
  long long int neutro = 1000000001;
  if ((q_left>right) || (q_right<left)){
    return neutro;
  }
  
  if (left>=q_left && right<=q_right){
    return sT[indice];
  }

  long long int mid=(right+left)/2;
  long long int leftSon=query(left, mid, q_left, q_right, (2*indice+1));
  long long int rightSon=query(mid+1, right, q_left, q_right, (2*indice+2));
  
  return min(leftSon, rightSon);
  // return(leftSon+rightSon);
}

long long int segmentTree::update(long long int left,long long int right,long long int val,long long int up_index, long long int indice){
  long long int mid=(right+left)/2;
  if(left==right){
    sT[indice]=val;
    return sT[indice];
  }

  if((left<=up_index) && (up_index<=mid)){
    sT[indice]=min(sT[(2*indice+2)] , update(left, mid, val, up_index, (2*indice+1)));
  }
  else{
    sT[indice]=min(sT[(2*indice+1)] , update(mid+1, right, val, up_index, (2*indice+2)));
  }
  //aqui era val, pero si lo dejabas asi siempre ibas a subir val, lo cual puede que te cause bugs
  return sT[indice];
}

long long int segmentTree::create(long long int left, long long int right, long long int indice ){
  long long int mid=(right+left)/2;
  if(left==right){
    sT[indice]=elem[left];
    return sT[indice];
  }

  long long int leftSon=create(left, mid, (2*indice+1));
  long long int rightSon=create(mid+1, right, (2*indice+2));

  sT[indice]=min(leftSon, rightSon);
  // sT[indice]=leftSon + rightSon;
  // return (leftSon + rightSon);
  return min(leftSon, rightSon);
} 

segmentTree::segmentTree(long long int size) {
  long long int neutro = 1000000001;

  long long int pot=2;
  while(pot<size){
    pot = pot * 2;
  }  
  while(elem.size()<pot){
    elem.push_back(neutro);
  }

  for(int i = 0; i<2*pot-1; i++) sT.push_back(neutro);

  create(0, pot-1, 0);

  // for(int x:sT){
  //   cout<<x<<endl;
  // }
 
  // int res = query(0,7,0,4,0);
  // cout<<"res: "<<res<<endl;
}


int main() {
  long long int n,aux,q; 

  cin>>n>>q;
  long long int auxn=n;

  while(n){
    cin>>aux;
    elem.push_back(aux);
    n--;
  }

  segmentTree st(auxn);


  long long int l,r,v;
  while(q--){
    cin>>v>>l>>r;

    if(v==1){
      // r--;
      st.update(0,elem.size()-1,r,l-1,0);
    }else{
      // r--;
      cout<<st.query(0,elem.size()-1,l-1,r-1,0)<<endl;
    }
  
  }

  return 0;
}