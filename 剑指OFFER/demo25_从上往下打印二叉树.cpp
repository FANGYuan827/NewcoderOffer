/*
2018年1月16日15:23:12 
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
#include "iostream"
#include <vector>
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

/*
层次遍历法：
解题思路：
直接将树的结点入队列  一边入队列一边出队列 在出队列时将树结点的数据域压入动态数组中 同时将这个结点的左右子树结点再入队列中
直到队列中的元素都处理完成

*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) 
	{
		vector<int>v_tmp;
		if(root==NULL)
		{
			return v_tmp;
		}
		//int count = 0,nextCount = 1;
		list<TreeNode *> l_tmp;
		l_tmp.push_back(root);
		while(l_tmp.size()!=0)
		{
			TreeNode *top = l_tmp.front();

			int tmp = top->val;
			v_tmp.push_back(tmp);
			l_tmp.pop_front();
			if(top->left!=NULL)
			{
				l_tmp.push_back(top->left);
			}
			if(top->right!=NULL)
			{
				l_tmp.push_back(top->right);
			}
		}
		return v_tmp;
	}
};

void main_demo25()
{
	Solution s1;
	vector<int> v_res;
	struct TreeNode t1(1),t2(22),t3(333),t4(4444);
	t1.left = &t2;
	t2.right = &t3;
	t1.right = &t4;
	int i = 0;
	v_res = s1.PrintFromTopToBottom(&t1);
	while(i<v_res.size())
	{
		printf("%d  ",v_res.at(i));
		i++;
	}
	printf("\n");
	system("pause");
}