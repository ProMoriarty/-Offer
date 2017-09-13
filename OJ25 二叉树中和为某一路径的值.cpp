/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
    /*
    struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) :
                val(x), left(NULL), right(NULL) {
        }
    };*/
    class Solution {
    public:
        vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
            if(root) dfsFind(root, expectNumber);
            return allRes;
        }
    private:
        vector<vector<int>> allRes;
        vector<int> tmp;
        void dfsFind(TreeNode* root,int left){
            tmp.push_back(root->val);
            if(left-root->val==0 && root->left==NULL && root->right==NULL)
                allRes.push_back(tmp);
            else{
                if(root->left)
                    dfsFind(root->left,left-root->val);
                if(root->right)
                    dfsFind(root->right,left-root->val);
            }
            tmp.pop_back();
        }
    };


