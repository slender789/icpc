#include <iostream>
using namespace std;

void fib(int lookup[],int n){
    for(int i=2;i<=n;i++){  
        lookup[i]=lookup[i-1]+lookup[i-2];
    }
}

int main(){

    int n;
    cout<<"Enter n to find the nth number in the Fibonacci Sequence : ";
    cin>>n;
    int lookup[n+1];
    
    lookup[0]=0;
    lookup[1]=1;
    fib(lookup,n);
    cout<<"The nth integer in the Fibonacci Sequence = ";
    cout<<lookup[n]<<endl;
}	
