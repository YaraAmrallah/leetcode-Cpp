/*

The thief has found himself a new place for his thievery again.
There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that "all houses in this place
forms a binary tree".
It will automatically contact the police if two directly-linked
houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight
without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/


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
