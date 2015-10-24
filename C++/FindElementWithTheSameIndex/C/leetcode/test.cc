/*tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stddef.h>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
enum LCAStatus {FINDING, ONE_AT_THE_TOP, ONE_FOUND, BOTH_FOUND};
    
class Solution {
    
public:
    // The root is definitely the LCA then find the next 
    LCAStatus updateStatus (LCAStatus status, TreeNode* c, TreeNode* p, TreeNode* q) {
        if ((c == p) || (c == q)) {
            if (status == FINDING)
                return ONE_FOUND;
            else if (status == ONE_FOUND)
                return BOTH_FOUND;
        }
        return status;
    }
    
    TreeNode* traversing (TreeNode* lca, TreeNode* c, TreeNode* p, TreeNode* q, LCAStatus &status) {
        if (c == NULL || p == NULL || q == NULL)
            return lca;
        if (status == BOTH_FOUND)
            return lca;
        
        LCAStatus newStatus = updateStatus (status, c, p, q);
        
        if (status != newStatus) {
            status = newStatus;
            if (status == ONE_FOUND) {
                lca = c;
            } else if (status == BOTH_FOUND) {
                lca = c;
                return lca;
            }
        }
        
        //looking on the left node;
        if (c->left != NULL) {
            lca = traversing (lca, c->left, p, q, status);
            if (status == BOTH_FOUND)
                return lca;
        }
        if (c->right != NULL) {
            return traversing (lca, c->right, p, q, status);
        }
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Call common ancestor then next common ancestor until can not find one and return the last one.
        return traversing (NULL, root, p, q, FINDING);
    }
};

int main() {
return 0;
}
