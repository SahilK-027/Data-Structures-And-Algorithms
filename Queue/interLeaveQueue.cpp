
/*
EX: Q = {1,2,3,4,5,6,7,8}
Approach 1: Using Extra Queue
Step 1: Fetch first half elements from queue and push them in a new queue.
```
After this your two queues will look like
NewQueue      -> {1,2,3,4}
OqiginalQueue -> {5,6,7,8}

```

Step 2: while(!newQueue.empty())
        {
            1. Remove element from front of new queue and push it 
                in original queue
            2. Remove element fron front of original queue and push
                it in original queue
        }

Step 3: END

TC : O(N)
SC : O(N)
*/

#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    int size = q.size();
    int half = size / 2;
    int count = 0;
    queue<int> newQueue;
    // Step 1:
    while(count < half){
        int element = q.front();
        newQueue.push(element);
        q.pop();
        count++;
    }
    // Step 2:
    while(!newQueue.empty()){
        //1.
        int newElement = newQueue.front();
        q.push(newElement);
        newQueue.pop();
        //2.
        int element = q.front();
        q.push(element);
        q.pop();
    }
}
