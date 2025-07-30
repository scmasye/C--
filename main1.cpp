#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 创建一个满二叉树，十一层，节点值规则：左=父-1，右=父+1
TreeNode* buildBinaryTree(int levels) {
    if (levels == 0) return nullptr;
    TreeNode* root = new TreeNode(4);
    std::queue<TreeNode*> q;
    q.push(root);
    int currLevel = 1;

    while (currLevel < levels) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front();
            q.pop();
            node->left = new TreeNode(node->val - 1);
            node->right = new TreeNode(node->val + 1);
            q.push(node->left);
            q.push(node->right);
        }
        ++currLevel;
    }
    return root;
}

// 统计最后一层叶子节点值为0的数量
int countZeroLeaves(TreeNode* root, int currLevel, int targetLevel) {
    if (!root) return 0;
    if (currLevel == targetLevel) {
        return root->val == 0 ? 1 : 0;
    }
    return countZeroLeaves(root->left, currLevel + 1, targetLevel) +
           countZeroLeaves(root->right, currLevel + 1, targetLevel);
}

// 释放内存
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int levels = 11; // 修改为11层
    TreeNode* root = buildBinaryTree(levels);
    int zeroCount = countZeroLeaves(root, 1, levels);
    std::cout << "第11层叶子节点值为0的数量: " << zeroCount << std::endl;
    freeTree(root);
    return 0;
}
