#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

struct unidad{
	int costo;
	int origen;
	int destino;
};

bool comp(const unidad a, const unidad b){
	if(a.costo == b.costo){
		if(a.origen == b.origen){
			return a.destino < b.destino;
		}
		return a.origen < b.origen;
	}
	return a.costo < b.costo;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	
	vector<unidad> arr;
	unidad aux;
	
	int n;
	cin>>n;
	
	while(n--){
		cin>>aux.origen>>aux.destino>>aux.costo;
		arr.push_back(aux);
	}
	
	sort(arr.begin(), arr.end(), comp);
	
	for(unidad p : arr){
		cout<<p.origen<<" "<<p.destino<<" "<<p.costo<<endl;
	}
	
	return 0;
}
