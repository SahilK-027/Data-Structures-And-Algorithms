#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    //Push operation
    q.push(1);
    q.push(5);
    q.push(7);
    q.push(9);

    // Size
    cout<<"Before pop size "<<q.size()<<endl;
    cout<<"Before pop front "<<q.front()<<endl;
    // Pop
    q.pop();

    // Size
    cout<<"After pop size "<<q.size()<<endl;
    cout<<"Before pop front "<<q.front()<<endl;

    // Is empty
    if(!q.empty()){
        cout<<"Queue is not empty"<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
    return 0;
}