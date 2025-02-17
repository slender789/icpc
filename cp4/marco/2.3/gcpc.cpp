#include <bits/stdc++.h>
#include <bits/extc++.h> // For PBDS
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int, pair<int,int>>, null_type, 
    less<pair<int, pair<int,int>>>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> ost;

#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ost tree;
    unordered_map<int, pair<int,int>>um;
    int teams, cases, team, penalty;
    cin>>teams>>cases;
    while(cases--){
        cin >> team >> penalty;
        if(um.find(-team) != um.end()){
            // cout<<"-team "<<-team<< " was present"<<endl;
            auto currP = um[-team];
            tree.erase({currP.first, {currP.second, -team}});
            tree.insert({currP.first + 1, {currP.second-penalty, -team}});
            um[-team] = {currP.first + 1, currP.second-penalty};
        } else {
            // cout<<"-team "<<-team<< " was not present"<<endl;
            tree.insert({1, {-penalty, -team}});
            um[-team] = {1, -penalty};
        }
        //look for 1
        if(um.find(-1) != um.end()){
            // cout<<"-team 1 was present"<<endl;
            auto currP = um[-1];
            int idx = tree.order_of_key({currP.first, {currP.second, -1}});
            // cout<<"looking for points "<<currP.first<<" penalty "<<currP.second<<" -team "<<1<<endl;
            cout<<tree.size()-idx<<endl;
        } else {
            // cout<<"-team 1 was not present"<<endl;
            cout<<tree.size()+1<<endl;
        }

        // for(int i = 0 ; i < tree.size() ; i++){
        //     cout<<"points "<<tree.find_by_order(i)->first<<" penalty "<<tree.find_by_order(i)->second.first<<" team "<<tree.find_by_order(i)->second.second<<endl;
        // }
        // cout<<"----------"<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------
