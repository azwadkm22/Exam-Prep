


//algo for right rotate

void rightRotate(node* root)
{
    node* temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    root = temp;
}


void leftRotate(node* root)
{
    node* temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    root = temp;
}
