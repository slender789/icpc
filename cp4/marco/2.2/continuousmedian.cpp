#include "bits/stdc++.h"
using namespace std;
// using namespace __gnu_pbds;

int main() {
    int tc, aux, n;
    cin >> tc;
    while(tc--){
        cin>>n;
        vector<int>s;
        int sum = 0;
        while(n--){
            cin>>aux;
            s.push_back(aux);
            sort(s.begin(), s.end());
            int size = s.size();
            if(size % 2 == 0){
                sum += (s[size/2] + s[(size-1)/2])/2;
                // cout << "p res " << (s[size/2] + s[(size-1)/2])/2 <<" for size "<<size<<endl;
            } else {
                sum += s[size/2];
                // cout << "i res " << s[size/2] <<" for size "<<size<<endl;
            }
        }
        cout<<sum<<endl;
        // cout<<endl;
    }

    return 0;
}
