#include<bits/stdc++.h>
#define MOD 100000000

using namespace std;

int N,M,T;

long long int finding(long long int a, long long int b){

    long long int c = b-a;
    long long int sum1 = 1;
    long long int sum2 = 1;
    long long int sto1 = 0;
    long long int sto2 = 0;
    while(c){
        sum1 = c;
        sum2= b;
        b--;
        c--;
        if(sum1 >= MOD){
            sto1 += sum1/MOD;
            sum1 %= MOD;
        }
        if(sum2 >= MOD){
            sto2 += sum2/MOD;
            sum2 %= MOD;
        }
    }

    if(sto1){
        long long int tmp = sto2/sto1;
        return tmp*sum2/sum1;
    }
    else{
        long long int tmp = 1;
        if(sto2){
            tmp = MOD*sto2;
        }
        return tmp*sum2/sum1;
    }
}

int main(){
    cin >> T;
    while(T--){
        long long int a,b;
        cin >> a >> b;
        cout << finding(a,b) << '\n';
    }
}