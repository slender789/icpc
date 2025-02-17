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

    int w, h;
    cin>>w>>h;
    vector<int>bottom(w/2);
    vector<int>top(w/2);
    for(int i = 0 ; i<w ; i++){
        if(i%2 == 0){
            cin>>bottom[i/2];
        }else{
            cin>>top[i/2];
        }
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    unordered_map<int,int>mapita;
    int maxi = 0;
    int m = w*2;

    for(int i = 1 ; i<=h ; i++){
        // cout<<"for i "<<i<<endl;
        auto ub1 = upper_bound(bottom.begin(), bottom.end(), i-1)-1;
        auto ub2 = upper_bound(top.begin(), top.end(), h-i)-1;
        int val1 = ub1 < bottom.begin() ? 0 : ub1 - bottom.begin() + 1;
        int val2 = ub2 < top.begin() ? 0 : ub2 - top.begin() + 1;
        // cout<<"for val1 "<<val1<<endl;
        // cout<<"for val2 "<<val2<<endl;
        m = min(m, (w/2)-val1 + (w/2)-val2);
        // cout<<"m was "<<(w/2)-val1 + (w/2)-val2<<endl;
        mapita[(w/2)-val1 + (w/2)-val2]++;
        // maxi = max(maxi, m);
    }
    cout << m << " " << mapita[m];
    return 0;
}
//--------------------EOSOLUTION---------------------------------