#include <bits/stdc++.h>
using namespace std;
int Binary_search(int *arr, int n, int key){
    int s = 0;
    int e = n - 1;
    int m = s + (e - s) / 2;
    while (s <= e){
        if(arr[m] == key) return m;
        else if(arr[m] > key) e = m -1;
        else s = m + 1;
        m = s + (e - s) / 2;
    }
    return -1;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    cout << Binary_search(arr, 5, 10);
    return 0;
}