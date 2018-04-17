/*
2018年4月11日21:35:58
给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/
#include "iostream"
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


/*
解题思路：
二叉搜索树的先序遍历 正好是按照结点val值的大小进行升序排列的 所以通过递归先序遍历 可以找出第k大的结点
*/
class Solution_demo66 {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode *res = NULL;
		if(pRoot==NULL||k<1)
			return res;
		vector<TreeNode *>v_res;
		LDR(pRoot,v_res);
		if(k>v_res.size())
			return res;
		res = v_res[k-1];
		return res;
    }
private:
	int LDR(TreeNode *pRoot,vector<TreeNode *>&res)
	{
		if(pRoot==NULL)
			return -1;
		if(pRoot!=NULL)
		{
			LDR(pRoot->left,res);
			res.push_back(pRoot);
			LDR(pRoot->right,res);
		}
		return 1;
	}
};


void main_demo66()
{
	Solution_demo66 s1;
	TreeNode t1(10),t2(6),t3(14),t4(4),t5(8),t6(12),t7(16);//,t8(8);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	TreeNode *res = NULL;
	res = s1.KthNode(&t1,6);
	if(res!=NULL)
		cout<<"二叉搜索树的第6个结点为："<<res->val<<endl;
	system("pause");
}