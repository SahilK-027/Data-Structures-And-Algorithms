class Solution {
public:
    vector<string> sortStrBasedOnLen(vector<string>& words) {
        int n = words.size();
        // Define a lambda function as the comparison function
        auto compareByLength = [](string& s1, string& s2) {
            return s2.length() > s1.length();
        };
        sort(words.begin(), words.end(), compareByLength);

        return words;
    }
};
