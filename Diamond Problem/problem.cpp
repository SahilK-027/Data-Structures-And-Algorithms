#include <bits/stdc++.h>
using namespace std;
class A{
public:
    int a;
};
class B1: public A{
public:
    int b1;
};
class B2: public A{
public:
    int b2;
};
class C: public B1, public B2{
public:
    int c;
};
int main(){
    C obj;
    cout<<sizeof(obj)<<endl;
    cout<<obj.a<<endl;
}