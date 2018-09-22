/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root): curr(nullptr) {
        curr = mostSmallestElem(root);
        buildTraverseStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       if (curr == nullptr && nextElems.size() == 0) {
           return false;
       }
       return true;
    }

    /** @return the next smallest number */
    int next() {
       if (curr == nullptr || (nextElems.size() > 0 && curr->val >= nextElems.top()->val)) {
           curr = nextElems.top();
           nextElems.pop();
       }
       int value = curr->val;
       curr = curr->right;
       return value;
    }
private:
    TreeNode* mostSmallestElem(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr) {
            return root;
        }     
        return mostSmallestElem(root->left);
    }

    void buildTraverseStack(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        buildTraverseStack(root->right);

        TreeNode* rightMostSmallestElem = mostSmallestElem(root->right);
        if (rightMostSmallestElem != nullptr && rightMostSmallestElem != root->right) {
            nextElems.push(rightMostSmallestElem);
        }
        if (root->left != nullptr) {
            nextElems.push(root);
        }

        buildTraverseStack(root->left);
    }
private:
    TreeNode* curr;
    stack<TreeNode*> nextElems;

};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
