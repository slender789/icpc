#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

bool found(int drawer, unordered_map<int,int>&drawerToItem, unordered_map<int,pair<int,int>>&itemToPlaces){
    set<int>visitedDrawers;
    bool foundFlag = false;
    while(visitedDrawers.find(drawer) == visitedDrawers.end()){
        visitedDrawers.insert(drawer);
        int currElement = drawerToItem[drawer];
        if(itemToPlaces[currElement].second == drawer) return false;
        int nextDrawer = itemToPlaces[currElement].second;
        if(drawerToItem.find(nextDrawer) == drawerToItem.end()){
            foundFlag = true; break;
        }
        drawer = nextDrawer;
    }
    return foundFlag;
}

void doForFound(int incoming, int drawer, unordered_map<int,int>&drawerToItem, unordered_map<int,pair<int,int>>&itemToPlaces, unordered_map<int,int>&itemToDrawer){
    while(true){   
        int currElement = drawerToItem[drawer];
        int nextDrawer = itemToPlaces[currElement].second;
        
        drawerToItem[drawer] = incoming;
        itemToDrawer[incoming] = drawer;
        
        if(drawerToItem.find(nextDrawer) == drawerToItem.end()){
            drawerToItem[nextDrawer] = currElement;
            itemToDrawer[currElement] = nextDrawer;
            return;
        } else {
            incoming = currElement;
            drawer = nextDrawer;
        }
    }
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, L, i , j;
    unordered_map<int,int>itemToDrawer;
    unordered_map<int,int>drawerToItem;
    unordered_map<int,pair<int,int>>itemToPlaces;

	cin >> N >> L;
	for (int x = 0 ; x<N ; x++) {
        cin>>i>>j;
        if (i>j) swap(i,j);
        itemToPlaces[x] = {i, j};
        if (drawerToItem.find(i) == drawerToItem.end()){
            itemToDrawer[x] = i;
            drawerToItem[i] = x;
            // cout<<"YES for i"<<endl;
            cout<<"LADICA"<<endl;
            continue;
        }
        if (drawerToItem.find(j) == drawerToItem.end()){
            itemToDrawer[x] = j;
            drawerToItem[j] = x;
            // cout<<"YES for j"<<endl;
            cout<<"LADICA"<<endl;
            continue;
        }
        if(found(i, drawerToItem, itemToPlaces)){
            doForFound(x, i, drawerToItem, itemToPlaces, itemToDrawer);
            // cout<<"found in i"<<endl;
            cout<<"LADICA"<<endl;
            continue;
        }
        if(found(j, drawerToItem, itemToPlaces)){
            doForFound(x, j, drawerToItem, itemToPlaces, itemToDrawer);
            // cout<<"found in j"<<endl;
            cout<<"LADICA"<<endl;
            continue;
        }
        cout<<"SMECE"<<endl;
        // cout<<"didnt find for any"<<endl;
	}
}
//--------------------EOSOLUTION---------------------------------