#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int airports, days, flights;
    int start, day, end, cap;
    int airport, customers;
    cin >> airports >> days >> flights;
    unordered_set<int,int>us;
    //+1 por si las moscas
    vector<vector<int>>incoming(days+1, vector<int>(airports));
    vector<vector<vector<pair<int,int>>>>fs(days, vector<vector<pair<int,int>>>(airports, vector<pair<int,int>>()));
    
    for(int i = 0 ; i<flights ; i++){
        cin >> start >> end >> day >> cap;
        fs[day-1][start-1].push_back({end-1, cap});
    }
    for(int i = 0 ; i<airports*days ; i++){
        cin >> airport >> day >> customers;
        incoming[day-1][airport-1] = customers;
    }
    // for(int i = 0 ; i<fs.size() ; i++){
    //     for(int j = 0 ; j<fs[i].size() ; j++){
    //         for(int k = 0 ; k<fs[i][j].size() ; k++){
    //             cout<<i<<" "<<j<<" "<<fs[i][j][k].first<<" "<<fs[i][j][k].second<<endl;
    //         }
    //     }
    // }
    // cout<<endl;
    // for(int i = 0 ; i<incoming.size() ; i++){
    //     for(int k = 0 ; k<incoming[i].size() ; k++){
    //         cout<<i<<" "<<k<<" "<<incoming[i][k]<<endl;
    //     }
    // }
    // for each of the days
    for(int i = 0 ; i<days ; i++){
        // for each of the airports
        for(int j = 0 ; j<airports ; j++){
        //update respect to the latest day
        if(i != 0) incoming[i][j] += incoming[i-1][j]; 
            //per flight
            for(int k = 0 ; k<fs[i][j].size() ; k++){
                // per flight, check if we can fill it up depending on start
                    // if we can't, suboptimal
                    // if we can, fill it up and update the current day's custoers, since we will later add the ones still in the airport
                if(fs[i][j][k].second <= incoming[i][j]){
                    //delete from curr
                    incoming[i][j] -= fs[i][j][k].second;
                    //update for next airport
                    incoming[i+1][fs[i][j][k].first] += fs[i][j][k].second;
                } else {
                    cout<<"suboptimal";return 0;
                }
            }
        }
    }
    cout<<"optimal";
    return 0;
}