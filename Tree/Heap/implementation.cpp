#include <bits/stdc++.h>
using namespace std ;
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        this->size = 0;
    }
    void insert(int val){
        // Step 1 : Insert at last position
        size = size +1;
        int index = size ;
        arr[index] = val;

        // Step 2 : 
        while(index > 1){
            int parent = index /2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void deletion(){
        if(size == 0){
            cout<<"heap Underflow";
            return;
        }
        // Step 1: Swap last element to first position
        arr[1] = arr[size];

        // Step 2: Delete  last element 
        size--;

        // Step 3: Take root again to its correct position
        int i = 1;
        while(i<size){
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i + 1;

            if(leftChildIndex < size && arr[i] < arr[leftChildIndex]){
                swap(arr[i] , arr[leftChildIndex]);
                i = leftChildIndex;
            }
            else if(rightChildIndex < size && arr[i] < arr[rightChildIndex]){
                swap(arr[i] , arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 1 ; i <=size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
int main()
{
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);

    h.print();

    h.deletion();
    h.print();
    return 0;
}
