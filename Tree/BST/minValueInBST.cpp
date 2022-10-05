// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
