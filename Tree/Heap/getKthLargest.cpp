#include<algorithm>
// Logic 1: TC => O(n sq)
//          SC => O(n sq)
int getKthLargest(vector<int> &arr, int k)
{
    // To store all sub array ans use vector
    vector<int> ans;
    // Looping
	for(int i = 0 ; i < arr.size(); i++){
        int sum = 0 ;
        for(int j = i ; j < arr.size() ; j++){
            sum += arr[j];
            ans.push_back(sum);
        } 
    }
    // Sorting the final ans to get kth largest
    sort(ans.begin(), ans.end());
    int n = ans.size();
    return ans[n-k];
}



#include<bits/stdc++.h>
// Logic 2: TC => O(n sq)
//          SC => O(k)
int getKthLargest(vector<int> &arr, int k)
{
    // To store all sub array ans use heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // Looping
	for(int i = 0 ; i < arr.size(); i++){
        int sum = 0 ;
        for(int j = i ; j < arr.size() ; j++){
            sum += arr[j];
            if(min_heap.size() < k){
              min_heap.push(sum);
            }
            else{
              if(sum > min_heap.top()){
                min_heap.pop();
                min_heap.push(sum);
              }
            }
        } 
    }
    return min_heap.top();
}
