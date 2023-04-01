#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    set<char>nums{'0', '1','2','3','4','5','6','7','8','9'};
    int m;
    cin>>m;
    while(m){

        string aux, res;
        int lim;

        cin>>aux>>lim;
        
        char* char_array = new char[aux.length() + 1];
    
        strcpy(char_array, aux.c_str());
    
        int i=0; 
        int cont=0;
        while (i < aux.length()){
            int num=0;
            if(nums.find(char_array[i])==nums.end()){
                // cout<<"letra "<<char_array[i]<<endl;
                res.push_back(char_array[i]);
                cont++;i++;
            }
            else{
                num=int(char_array[i] - '0');
                while(nums.find(char_array[i+1])!=nums.end()){
                    num=num*10+int(char_array[i+1] - '0');
                    i++;
                }
                cont += num;
                if(cont>lim)break;
                // cout<<"num"<<char_array[i]<<endl;
                while(num){
                    res.push_back(char_array[i+1]);
                    num--;
                }
                i+=2;
            }
        }

        if(cont>lim){
            cout<<"unfeasible"<<endl;
        }
        else{
            cout<<res<<endl;
        }

        delete[] char_array;
        m--;
    }

	return 0;
}	
