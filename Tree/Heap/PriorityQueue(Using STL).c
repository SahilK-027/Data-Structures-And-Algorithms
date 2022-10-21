#include <bits/stdc++.h>
using namespace std ;
int main()
{
    // USING CPP STL
    // MAX HEAP BY DEFAULT
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"\nElement at top : "<<pq.top();
    pq.pop();
    cout<<"\nElement at top : "<<pq.top();

    // Implementing min heap
    priority_queue<int, vector<int>, greater<int> > pq2;
    pq2.push(4);
    pq2.push(2);
    pq2.push(5);
    pq2.push(3);

    cout<<"\nElement at top : "<<pq2.top();
    pq2.pop();
    cout<<"\nElement at top : "<<pq2.top();
    return 0;
}
