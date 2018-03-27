/*
2018��2��5��09:49:32
����һ�ö��������жϸö������Ƿ���ƽ���������
*/

#include "iostream"
#include "math.h"
using namespace std;

struct TreeNode
{
public:
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};



class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot==NULL)
		{
			return true;
		}
		int left_depth = Deepth(pRoot->left);
		int right_depth = Deepth(pRoot->right);
		if(abs(left_depth-right_depth)<=1)
		{
			return true;
		}
		else
		{
			return false;
		}
		IsBalanced_Solution(pRoot->left);         //�����仰����if���֮�� �ȷ��� if���֮ǰҪ��Լ�����ĵݹ����
		IsBalanced_Solution(pRoot->right);
    }
private:
	int Deepth(TreeNode *pRoot)
	{
		if(pRoot==NULL)
		{
			return 0;
		}
		int left_deepth = Deepth(pRoot->left);
		int right_deepth = Deepth(pRoot->right);
		return (left_deepth>right_deepth?left_deepth:right_deepth)+1;
	}
};



void main_demo32()
{
	Solution s1;
	struct TreeNode *Root = NULL;
	struct TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t4.left = &t6;
	t4.right = &t7;
	Root = &t1;
	int res = s1.IsBalanced_Solution(Root);
	if(res)
	{
		printf("����һ��ƽ�������\n");
	}
	else
		printf("�ⲻ��һ��ƽ�������\n");

	system("pause");
}