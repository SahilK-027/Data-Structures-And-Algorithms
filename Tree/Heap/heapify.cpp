#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int size, int index)
{
    int current = index;
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;

    // Check if current is smaller than left child
    if (leftChild < size && arr[current] < arr[leftChild])
    {
        current = leftChild;
    }

    // Check if current is smaller than right child
    if (rightChild < size && arr[current] < arr[rightChild])
    {
        current = rightChild;
    }

    // If current is updated
    if (current != index)
    {
        swap(arr[current], arr[index]);
        heapify(arr, size, current);
    }
}
int main()
{
    vector<int> arr ;
    arr.push_back(59);
    arr.push_back(54);
    arr.push_back(53);
    arr.push_back(55);
    arr.push_back(52);
    arr.push_back(50);
    int n = 6;
    for (int i = n / 2 -1 ; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
