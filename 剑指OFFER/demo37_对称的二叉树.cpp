/*
2018年2月28日21:31:54
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

#include "iostream"
using namespace std;


//定义树结点
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
		if(pRoot==NULL)
		{
			return false;
		}
    
    }

};






void main_demo37()
{
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);


	system("pause");
}