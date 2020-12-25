#include <vector>
#include <iostream>

//medium
//https://leetcode.com/problems/binary-tree-level-order-traversal/
//This is using BFS search
using namespace std;

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
    vector<vector<int>> levelkeep;


    vector<vector<int>> levelOrder(TreeNode* root) {
        //check if root is valid
        if(root == nullptr) return levelkeep;
        //call helper function
        helper(root, 0);
        return levelkeep;
        
    }
    
    void helper(TreeNode * node, int level)
    {
        //start the current level
        if(levelkeep.size() == level)
        {
            //create a vector and push into main vector
            vector<int>inner;
            levelkeep.push_back(inner);
        }
        
        //push node into its corresponding vector block
        levelkeep[level].push_back(node->val);
        
        //check if children are valid
        if(node -> left != nullptr)
            helper(node->left, level + 1);
        if(node -> right != nullptr)
            helper(node->right, level + 1);
        
    }
};