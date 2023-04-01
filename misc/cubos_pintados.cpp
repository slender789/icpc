#include <bits/stdc++.h>
using namespace std;
int r=101;
int c=101;
int mapa[101][101];
int ady[101][101];

int main(){
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

    int rows, cols;
    cin>>rows>>cols;
    string inp;
    for(int i=0 ; i<rows ; i++){
        cin>>inp;
        for(int j=0 ; j<cols ; j++){
            mapa[i][j]=inp[j]-'0';
        }
    }

    int pintura;

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if (mapa[i][j] == 0) continue; else pintura += 2;
            
            if((j-1)<0) {pintura +=mapa[i][j];} 
            else{
                if (ady[i][j-1] == 0){
                    pintura += abs(mapa[i][j]-mapa[i][j-1]);
                }
            }
            if((j+1)>=cols) {pintura +=mapa[i][j];} 
            else{
                if (ady[i][j+1] == 0){
                    pintura += abs(mapa[i][j]-mapa[i][j+1]);
                }
            }
            if((i-1)<0) {pintura +=mapa[i][j];} 
            else{
                if (ady[i-1][j] == 0){
                    pintura += abs(mapa[i][j]-mapa[i-1][j]);
                }
            }
            if((i+1)>=rows) {pintura +=mapa[i][j];} 
            else{
                if (ady[i+1][j] == 0){
                    pintura += abs(mapa[i][j]-mapa[i+1][j]);
                }
            }
            ady[i][j]=1;
        }
    }

    cout<<pintura;
    return 0;        
}