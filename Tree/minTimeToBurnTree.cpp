// Approach:
/*
Step 1: Create Node to parent mapping
Step 2: Find the target node from given tree
Step 3: Start buring tree
        * For burining tree make use of Visited map and Queue
        * In queue we will only be storing the elements which are not already visited
        So, whenever we do insertion in queue means node is not burned ==> increment time
        else do nothing.
Step 4: End
*/

class Solution
{
private:
    Node *createNodeToParentMapping(Node *root, int target, unordered_map<Node *, Node *> &NodeToParent)
    {
        // This function does both Step1 and Step2
        Node *targetNode = NULL;
        // Level order traversal to create mapping
        queue<Node *> q;
        q.push(root);
        NodeToParent[root] = NULL;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == target)
            {
                targetNode = temp;
            }

            if (temp->left)
            {
                NodeToParent[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right)
            {
                NodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return targetNode;
    }

    int burnTree(Node *targetNode, unordered_map<Node *, Node *> &NodeToParent)
    {
        // This function will perfor step 3
        // Created map for already burned tree
        unordered_map<Node *, bool> burned;

        // Doing level order traversal
        queue<Node *> q;
        q.push(targetNode);
        burned[targetNode] = true;

        int mintime = 0;
        while (!q.empty())
        {
            bool queueInsertion = false;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                // Process all the neighbours
                Node *temp = q.front();
                q.pop();

                // 3 neighbours
                // left, right, parent
                if (temp->left && burned[temp->left] != true)
                {
                    q.push(temp->left);
                    burned[temp->left] = true;
                    queueInsertion = true;
                }
                if (temp->right && burned[temp->right] != true)
                {
                    q.push(temp->right);
                    burned[temp->right] = true;
                    queueInsertion = true;
                }
                if (NodeToParent[temp] && burned[NodeToParent[temp]] != true)
                {
                    q.push(NodeToParent[temp]);
                    burned[NodeToParent[temp]] = true;
                    queueInsertion = true;
                }
            }
            if (queueInsertion == true)
            {
                mintime++;
            }
        }
        return mintime;
    }

public:
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> NodeToParent;
        Node *targetNode = createNodeToParentMapping(root, target, NodeToParent);
        int mintime = burnTree(targetNode, NodeToParent);
        return mintime;
    }
};
