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
    BSTIterator(TreeNode *root) {
        curr = buildTraverseStack(root);
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
    // buildTraverseStack track traverse path
    // return pointer of smallest TreeNode
    TreeNode* buildTraverseStack(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* smallest = root;

        TreeNode* rightMostSmallestElem = buildTraverseStack(root->right);
        if (rightMostSmallestElem != nullptr && rightMostSmallestElem != root->right) {
            nextElems.push(rightMostSmallestElem);
        }
        if (root->left != nullptr) {
            nextElems.push(root);
            smallest = buildTraverseStack(root->left);
        }
        return smallest;
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
