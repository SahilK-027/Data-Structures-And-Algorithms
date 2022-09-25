class solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, map<int, vector<int>>> mp;
        queue<pair<Node *, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int no_line_dist = temp.second.first;
            int lvl = temp.second.second;

            mp[no_line_dist][lvl].push_back(frontNode->data);

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(no_line_dist - 1, lvl + 1)));
            }
            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(no_line_dist + 1, lvl + 1)));
            }
        }
        for (auto i : mp)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
