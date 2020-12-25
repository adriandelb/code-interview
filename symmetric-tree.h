#include <iostream>
//easy
//https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return recurseSym(root, root);
    }
    
    bool recurseSym(TreeNode * lt, TreeNode * rt)
    {
        if(lt == nullptr && rt == nullptr) return true;
        if(lt == nullptr || rt == nullptr) return false;
        
        return (lt->val == rt->val) && recurseSym(lt->right, rt->left) && recurseSym(lt->left, rt->right);
    }
};