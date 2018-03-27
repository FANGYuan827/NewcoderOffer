/*
2018��1��20��21:46:58

���������Ķ�����������任ΪԴ�������ľ���
�������ľ����壺
Դ������ 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
���������
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7   5

*/

#include "iostream"
#include <vector>
#include <list>
#include <stack>
using namespace std;


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
    void Mirror(TreeNode *pRoot) 
	{
		if(pRoot==NULL)
		{
			return ;
		}
		stack<TreeNode *>s_res;
		s_res.push(pRoot);
		while(s_res.size()!=0)
		{
			TreeNode *tmp = s_res.top();
			s_res.pop();
			if(tmp)
			{
				My_Swap(&(tmp->left),&(tmp->right));
			}
			if(tmp->left)
				s_res.push(tmp->left);
			if(tmp->right)
				s_res.push(tmp->right);
		}

    }
	template <class T>
	void My_Swap(T tree1,T tree2)
	{
		if(tree1==NULL||tree2==NULL)
		{
			return;
		}
		T tmp = (T)malloc(sizeof(T));
		if(tmp)
		{
			*tmp = *tree1;
			*tree1 = *tree2;
			*tree2 = *tmp;
			free(tmp);     //�ͷ��ڴ�
			tmp = NULL;
		}
	}
};

/*
����˼·��
�������õݹ�ķ���������

*/
class Solution_2
{
public:
	void Mirror(TreeNode *pRoot) {
		if(pRoot)
		{
			My_Swap(&(pRoot->left),&(pRoot->right));
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	
	}
	template <class T>
	void My_Swap(T tree1,T tree2)
	{
		if(tree1==NULL||tree2==NULL)
		{
			return;
		}
		T tmp = (T)malloc(sizeof(T));
		if(tmp)
		{
			*tmp = *tree1;
			*tree1 = *tree2;
			*tree2 = *tmp;
			free(tmp);     //�ͷ��ڴ�
			tmp = NULL;
		}
	}

};

void LDR_demo29(TreeNode *pRoot)
{
	if(pRoot)
	{
		printf("%d  ",pRoot->val);
		LDR_demo29(pRoot->left);
		LDR_demo29(pRoot->right);
	}
	//printf("\n");
}

void main_demo29()
{
	 //Solution_2 s1;
	 Solution s1;
	 struct TreeNode t1(8),t2(6),t3(10),t4(5),t5(7),t6(9),t7(11);
	
	 t1.left = &t2;
	 t1.right = &t3;
	 t2.left = &t4;
	 t2.right = &t5;
	 t3.left = &t6;
	 t3.right = &t7;
	
	 LDR_demo29(&t1);
	 printf("\n");
	 s1.Mirror(&t1);
	 
	 LDR_demo29(&t1);
	 printf("\n");
	 system("pause");
}

/*
һ��ʼ�Ľ���˼·�ʹ��� û���ҵ������Ĺ��� ...... 
ֱ�ӽ������������Ϳ����� �����еķ�Ҷ�ӽ�㶼��ֱ�ӽ�����������
*/


