#include <bits/stdc++.h>
using namespace std ;
class kQueue{
    private:
        int n;          // Size of array
        int k;          // No. of queues
        int *front;     // Front array
        int *rear;      // Rear array
        int *arr;       // Original array to implement queue
        int curr_available_free_spot;
        int *nextFreeSpot;
    public:
        kQueue(int n, int k){
            this->n = n;
            this->k = k;

            front = new int[k];
            rear = new int[k];
            for(int i = 0 ; i  < k ; i++){
                front[i] = rear[i] = -1;
            }

            nextFreeSpot = new int[n];
            for(int i = 0 ; i < n ; i++){
                nextFreeSpot[i] = i+1;
            }
            nextFreeSpot[n-1] = -1;

            arr = new int[n];

            curr_available_free_spot = 0;
        }

        void enqueue(int data, int qn){

            // overflow
            if(curr_available_free_spot == -1){
                cout<<"Overflow"<<endl;
                return;
            }

            // Find first free index
            int index = curr_available_free_spot;

            // Update freee spot
            curr_available_free_spot = nextFreeSpot[index];

            // Check if its first element in queue
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //Link new element to the previous element
                nextFreeSpot[rear[qn-1]] = index;
            }

            // Update nextFreeSpot
            nextFreeSpot[index] = -1;

            // Update rear
            rear[qn-1] = index;

            // Push
            arr[index] = data;
        }

        int dequeue(int qn){
            //UNderflow
            if(front[qn-1] == -1){
                cout<<"Underflow ";
                return -1;
            }

            // Find index
            int index = front[qn-1];
            int ans =  arr[index];

            // Update front
            front[qn-1] = nextFreeSpot[index];

            //create link with next and curr freee spot
            nextFreeSpot[index] = curr_available_free_spot;

            // Update curr free spot to deleted position
            curr_available_free_spot = index;

            return ans;
        }
};
int main()
{
    kQueue q(9,3);
    q.enqueue(1,1);
    q.enqueue(2,1);
    q.enqueue(10,2);
    q.enqueue(100,3);
    q.enqueue(3,1);
    q.enqueue(200,3);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(2)<<endl;

    return 0;
}
