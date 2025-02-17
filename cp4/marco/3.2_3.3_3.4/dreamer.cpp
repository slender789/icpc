#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tC;

	cin >> tC;
    while(tC--){
        string d,m,y;
        cin>>d>>m>>y;
        string fullDate = d+m+y;
        vector<int>v(8);
        set<tuple<int,int,int>>cases;
        unordered_map<int,int>monthToDays{{1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30},
        {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}};
        for(int i = 0 ; i<8 ; i++){
            v[i] = fullDate[i] - '0';
        }
        sort(v.begin(), v.end());
        int inv = 0;
        do {
            int year = v[7]+v[6]*10+v[5]*100+v[4]*1000;
            int day = v[0]*10+v[1]; 
            if (day>31 || day<1) continue;
            int month = v[2]*10+v[3];
            if (month>12 || month<1) continue;
            int limit = monthToDays[month];
            if (month == 2){
                ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? limit = 29 : limit = 28;
            }
            if (day > limit) continue;
            if (year<2000) {inv++;continue;}
            // cout<<day<<" "<<month<<" "<<year<<endl;
            cases.insert({year,month,day});
        } while (next_permutation(v.begin(), v.end()));
        if (cases.empty()) {
            cout << "0\n";
            continue;
        }
        // sort(cases.begin(), cases.end());
        int dayF = get<2>(*cases.begin());
        int monthF = get<1>(*cases.begin());
        int yearF = get<0>(*cases.begin());
        string daystr;
        string monthstr;
        if (dayF < 10) {daystr = "0"+to_string(dayF);} else {daystr = to_string(dayF);};
        if (monthF < 10) {monthstr = "0"+to_string(monthF);} else {monthstr = to_string(monthF);};
        cout<<cases.size()<<" "<<daystr <<" "<<monthstr<<" "<<yearF<<endl;
        // cout<<"---\n";
    }

    return 0;

}
//--------------------EOSOLUTION---------------------------------