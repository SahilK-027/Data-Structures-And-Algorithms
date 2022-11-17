// Craeting map of roll number and nams
#include <bits/stdc++.h>
#include<unordered_map>
#include<map>
using namespace std ;
int main()
{
    // Creation
    unordered_map<int, string>u_map;

    // Insertion
    u_map[1] = "SK";
    u_map[2] = "AK";
    u_map[3] = "JK";
    u_map[4] = "RK";

    // Updation
    u_map[4] = "PK";

    // Searcing
    //1. 
    cout<<u_map[4]<<endl;
    //2.
    cout<<u_map.at(4)<<endl;
    //3. Accesing popsition which haven't yet created
    //cout<<u_map.at(5)<<endl;  // This line will throw error
    cout<<u_map[5]<<endl;       // This line will create a new entry corresponding to the entered key with NULL as value

    // Check if a particular key is present
    cout<<u_map.count(15)<<endl;      // If key is absent count will return 0 else 1.


    // How to traverse map
    // 1. Using for each loop
    for(auto i: u_map){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    // 2. Using iterator
    unordered_map<int, string> :: iterator it = u_map.begin();
    while(it != u_map.end()){
        cout<<it->first<<" -> "<<it->second<<endl;
        it++;
    }
    return 0;
}
