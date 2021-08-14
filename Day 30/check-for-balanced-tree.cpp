// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

int height(Node *root)
{
       if (root== NULL)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    if(root==NULL)
    {
        return 1;
    }
    //  Your Code here
    int left=height(root->left);
    int right=height(root->right);
    if(abs(left-right)<=1&& isBalanced(root->left) && isBalanced(root->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
