void heapify(int *arr, int n, int i){
    // Take current find its right and left child
    int current = i;
    int left = 2*i;
    int right = 2*i+1;

    // If small found then swap
    if(left <= n && arr[current] < arr[left]){
        current = left;
    }

    if(right <= n && arr[current] < arr[right]){
        current = right;
    }

    // if current got updated then check again for bottom subtree
    if( current != i){
        swap(arr[current], arr[i]);
        heapify(arr,n,current);
    }
}

void heapSort(int *arr, int n){
    int size = n ;
    while(size > 1){
        //Step 1 :  Swap last element with fist
        swap(arr[size], arr[1]);

        // Step 2:
        size--;

        // Step 3: heapify
        heapify(arr, size, 1);
    }
}
int main()
{
    int arr[6] = {-1,54,53,55,52,50};

    // Heap creation
    int n = 5;
    for(int i = n / 2 ; i > 0 ;i-- ){
         heapify(arr, n, i);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;

    // Heap sort
    heapSort(arr, n);
    for(int i = 1 ; i <= n ;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
