/*
2018年1月16日14:19:35
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度。
*/


/*
解题思路：
分别切左子树 右子树的深度 取两者中大的一个 并加1 
这个值即为树的深度
利用递归的方法求解
*/

#include "iostream"
#include <list>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


//递归法实现
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
		if(pRoot==NULL)
		{
			return 0;
		}
		int left_depth = 0,right_depth = 0;
		left_depth = TreeDepth(pRoot->left);
		right_depth = TreeDepth(pRoot->right);
		return (left_depth>right_depth?left_depth:right_depth)+1;
       
    }
};
 //非递归实现
 //思想:nextCount记录每层元素的个数 count记录该层的元素是否全部弹出 如果全部弹出depth+1 计算从上到下
class Solution_1 {
public:
	int TreeDepth(TreeNode *pRoot)
    {
        if(pRoot == NULL){
            return 0;
        }
        //Queue<TreeNode> queue = new LinkedList<TreeNode>();
		list<TreeNode *>l;
		l.push_back(pRoot);
        int depth = 0, count = 0, nextCount = 1;    
        while(l.size()!=0){
			TreeNode *top = l.front();
			l.pop_front();
            count++;
            if(top->left != NULL)
			{
				l.push_back(top->left);
            }
            if(top->right != NULL)
			{
				l.push_back(top->right);
            }
            if(count == nextCount)
			{
                nextCount = l.size();
                count = 0;
                depth++;
            }
        }
        return depth;
    }
};


void main_demo24()
{
	 Solution s1;
	 Solution_1 s_1;
	 int deepth = 0;
	 struct TreeNode t1(1),t2(2),t3(3),t4(4);
	 t1.left = &t2;
	 t2.left = &t3;
	 t1.right = &t4;
	// deepth = s1.TreeDepth(&t1);
	 deepth = s_1.TreeDepth(&t1);
	 printf("所求树的深度为:%d\n",deepth);
	 system("pause");
}