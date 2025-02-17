#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int globMax = 0;

struct CustomStruct{
    int w, h, x, y;
    int height, width;
    CustomStruct(int w, int h, int x, int y): 
        w(w), h(h), x(x), y(y), width(x+w), height(y-h)
    {}
};

bool canDo(int idxs, vector<CustomStruct>&v, int idx){
    int n = v.size();
    for(int i = 0 ; i<n ; i++){
        if (i == idx) continue;
        bool visitedIdx = idxs & (1<<(i+1));
        if(visitedIdx){
            int x1 = v[idx].x;
            int x2 = v[idx].width;
            int y1 = v[idx].y;
            int y2 = v[idx].height;
            int x1i = v[i].x;
            int x2i = v[i].width;
            int y1i = v[i].y;
            int y2i = v[i].height;

            // look for var inside
            if(x1 > x1i    &&     x1 < x2i    &&     y1 < y1i      &&     y1  > y2i) return false;
            if(x2 > x1i    &&     x2 < x2i    &&     y1 < y1i      &&     y1  > y2i) return false;
            if(x1 > x1i    &&     x1 < x2i    &&     y2 < y1i      &&     y2  > y2i) return false;
            if(x2 > x1i    &&     x2 < x2i    &&     y2 < y1i      &&     y2  > y2i) return false;
            // cout<<"could do "<<idx<<"case 1"<<endl;

            // then outisde
            swap(x1, x1i);
            swap(x2, x2i);
            swap(y1, y1i);
            swap(y2, y2i);
            if(x1 > x1i    &&     x1 < x2i    &&     y1 < y1i      &&     y1  > y2i) return false;
            if(x2 > x1i    &&     x2 < x2i    &&     y1 < y1i      &&     y1  > y2i) return false;
            if(x1 > x1i    &&     x1 < x2i    &&     y2 < y1i      &&     y2  > y2i) return false;
            if(x2 > x1i    &&     x2 < x2i    &&     y2 < y1i      &&     y2  > y2i) return false;
            // cout<<"could do "<<idx<<"case 2"<<endl;

            // then 2 points matching
            if(x1 == x1i && x2 == x2i){
                if(y1 < y1i && y1 > y2i) return false;
                if(y2 < y1i && y2 > y2i) return false;
            }
            // cout<<"could do "<<idx<<"case 3"<<endl;
            if(y1 == y1i && y2 == y2i){
                if(x1 > x1i && x1 < x2i) return false;
                if(x2 > x1i && x2 < x2i) return false;
            }
            // cout<<"could do "<<idx<<"case 4"<<endl;
            if(x1==x1i && x2==x2i && y1==y1i && y2==y2i) return false;
            // cout<<"could do "<<idx<<"case 5"<<endl;
        }
    }
    return true;
}

void backtrack(int idxs, vector<CustomStruct>&v, int sum){
    int n = v.size();
    for(int i = 1 ; i<=n ; i++){
        bool visitedIdx = idxs & (1<<i);
        if(!visitedIdx && canDo(idxs, v, i-1)){
            // cout<<"can do "<<i-1<<endl;
            idxs |= (1<<i);
            backtrack(idxs, v, sum + v[i-1].w*v[i-1].h);
            idxs &= ~(1<<i);
        }
    }
    globMax = max(globMax, sum);
    // cout<<"==="<<endl;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    
    while(cin>>n){
        int w, h, x, y;
        vector<CustomStruct>v(n, CustomStruct(0,0,0,0));
        for(int i = 0; i<n ; i++){
            cin >> w >> h >> x >> y;
            v[i] = CustomStruct(w, h, x, y);
        }
        int idxs = 0;
        backtrack(idxs, v, 0);
        if(!n)return 0;
        cout<<globMax<<endl;
        // cout<<">>>>>>><<<<<<<<<<"<<endl;
        globMax = 0;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------