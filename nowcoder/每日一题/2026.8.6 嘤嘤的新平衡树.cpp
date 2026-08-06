/*
标签：树

思路：因为只要返回最后的值，不需要每个节点都填值
左右子树大小相等相当于满二叉树，答案为左右节点最大值×2+1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
    using ll = long long;
    const int mod = 1e9 + 7;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类
     * @return int整型
     */
    ll dfs(TreeNode* tree)
    {
        if (tree)
        {
            return (1 + max(dfs(tree->left), dfs(tree->right)) * 2);
        }
        return 0;
    }
    int getTreeSum(TreeNode* tree)
    {
        return dfs(tree) % mod;
    }
};