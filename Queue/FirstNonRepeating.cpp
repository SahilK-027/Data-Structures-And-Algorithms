/* First non-repeating character in a stream */

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> map;
        queue<char> q;
        int n = A.length();
        string ans;
        for (int i = 0; i < n; i++)
        {
            char ch = A[i];
            // Increase the count
            map[ch]++;
            // Push in queue
            q.push(ch);
            while (!q.empty())
            {
                if (map[q.front()] > 1)
                {
                    // Repeating character
                    q.pop();
                }
                else
                {
                    // Non repeating character
                    ans.push_back(q.front());
                    break;
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
