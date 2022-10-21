#include <bits/stdc++.h>
using namespace std ;
void heapify(int *arr, int n, int i){
    // TIME COMPLEXITY : O(log n)

    // Take current find its right and left child
    int current = i;
    int left = 2*i;
    int right = 2*i+1;

    // If small found then swap
    if(left < n && arr[current] < arr[left]){
        swap(arr[current] , arr[left]);
    }

    if(right < n && arr[current] < arr[right]){
        swap(arr[current] , arr[right]);
    }

    // if current got updated then check again for bottom subtree
    if( current != i){
        heapify(arr,n,current);
    }
}
int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n / 2 ; i > 0 ;i-- ){
         heapify(arr, n, i);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
