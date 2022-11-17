#include<unordered_map>
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    
    // Craeting value->count mapping
    for(int i = 0 ; i < arr.size() ;i++){
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = 1;
        }
        else{
            mp[arr[i]]++;
        }
    }
    
    // Finding maximum occurring freq
    int maxi = INT_MIN;
    for(auto i: mp){
        if(i.second > maxi){
            maxi = i.second;
        }
    }
    
    // Return 
    int ans = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        if(mp[arr[i]] == maxi){
            ans = arr[i];
            break;
        }
    }
    return ans;
}
