/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map <void*, int> used;
    unordered_map <void*, int> notUsed;

     int next(TreeNode *p, bool used1)
     {
         if(p == NULL) return 0;

         if(used1 == true)
         {
             if(used.find(p) != used.end()) return used[p];

             used[p] = next(p->left, false) + next(p->right, false) + p->val;
             return used[p];
         }

         if(notUsed.find(p) != notUsed.end()) return notUsed[p];
         notUsed[p] = max(next(p->left, true), next(p->left, false))
                    + max(next(p->right, true), next(p->right, false));
         return notUsed[p];
     }

    int rob(TreeNode* root)
    {
        if(root == NULL) return 0;

        int sum = 0;
        sum = max(next(root,true), next(root, false));
        return sum;
    }
};
