/*
Approach:
To solve this problem in O(n) time complexity
We will divide our job and process each array one at a time
1. For second array we will find all nextGreater element using stack (We will see how) and then store our answers in a hash map.
2. And for array 1 we will get all the answers in O(1) from hash map

* Algorithm for finding next greater element using stack

Here we will start processing from rightmost element as we have to find next greater elemment.
Step 1: Create a stack and push -1 in it initially. (As For elements with no nextGreater we have to store -1 as answer)

Step 2: Start traversing nums2 from rightmost element and search for answer in stack top

Step 3: Now stack top will either have smaller or greater number.

if(greater_Num_Found_At_Stack_Top){

    1. Store that number in hashmap as an answer for current 
    2. And push current element in stack
}

else
{
    1. Now you are in else block means smaller element found at stack top
    2. if(that smaller number is -1)
        {
            1. store -1 in map.
            2. push current element in stack
        }
        else
        {
            1. Means smaller number other than -1 is found
            2. so search in stacktop till you find either greater number or -1
            3. if(greater number found ){
                    1. store it in map
                    2. push current element in stack
                }
               else{
                    //Found -1
                    1. store -1 in map.
                    2. push current element in stack
               }
        } 
}

* Now traverse through nums1 and search for ans in hashMap
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Algorithm for finding next greater element using stack
        int n = nums2.size()-1;
        stack<int> st;
        st.push(-1);
        unordered_map<int,int> map;
        for(int i = n; i>=0 ;i--)
        {
            if(st.top() > nums2[i])
            {
                //Greater element found
                map[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            else
            {
                if(st.top() == -1)
                {
                    map[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
                else
                {
                    while(st.top() <= nums2[i] && st.top() != -1)
                    {
                        st.pop(); 
                    }
                    if(st.top() == -1)
                    {
                        map[nums2[i]] = st.top();
                        st.push(nums2[i]);
                    }
                    else{
                        map[nums2[i]] = st.top();
                        st.push(nums2[i]);
                    }
                }
            }
        }
        
        // Finding answer
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++)
        {
            ans.push_back(map[nums1[i]]);
        }
        
        return ans;
    }
};
