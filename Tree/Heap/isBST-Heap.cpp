class Solution
{
private:
    int countNodes(struct Node *root)
    {
        // Base case
        if (root == NULL)
        {
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }

    bool solveCBT(struct Node *root, int index, int nodeCount)
    {
        // Base case
        if (root == NULL)
        {
            return true;
        }

        // If range exceeds
        if (index >= nodeCount)
        {
            return false;
        }

        // Else check for remaining subtrees
        else
        {
            bool leftAns = solveCBT(root->left, 2 * index + 1, nodeCount);
            bool rightAns = solveCBT(root->right, 2 * index + 2, nodeCount);
            return (leftAns && rightAns);
        }
    }
    bool solveHeap(struct Node *root)
    {
        // Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // Only left child exists
        if (root->right == NULL)
        {
            return root->data > root->left->data;
        }

        // Else both children exists
        else
        {
            bool leftAns = solveHeap(root->left);
            bool rightAns = solveHeap(root->right);
            return (root->data > root->left->data) && (root->data > root->right->data) && leftAns && rightAns;
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        // Step1: Check if given binary tree is complete or not
        /*
        If given tree is complete binary tree then index of each node in tree will always less
        than total number of nodes in that tree
        */
        int nodeCount = countNodes(tree);
        int index = 0;

        // Step2: Check if it statisfies heap property or not
        /*
        Now we will check if tree is heap or not using heap property
        */
        // Checking for both properties to statisfy
        return (solveCBT(tree, index, nodeCount) && solveHeap(tree));
    }
};
