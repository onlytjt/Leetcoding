/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
        return;
        TreeLinkNode *FirstNode;
        FirstNode = root->left;
        root->next=NULL;
        while (FirstNode != NULL)
        {
            root->left->next = root->right;
            if(root->next!=NULL)
            {
                root->right->next = root->next->left;
                root = root->next;
            }
            else
            {
                root->right->next = NULL;
                root = FirstNode;
                FirstNode = root->left;
            }
        }
    }
};
