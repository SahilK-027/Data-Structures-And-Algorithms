#include <bits/stdc++.h>
using namespace std ;
int numOfDivisors(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(n / i == i){
                cnt += 1;
            }
            else{
                cnt += 2;
            }
        }
    }
    return cnt;
}
int getAns(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += numOfDivisors(i);
    }
    return cnt;
}
int main()
{
    cout<<getAns(1);
    return 0;
}