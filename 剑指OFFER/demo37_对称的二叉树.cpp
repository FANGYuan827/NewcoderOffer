/*
2018��2��28��21:31:54
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/

#include "iostream"
#include <vector>
using namespace std;


//���������
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


class Solution_demo37 {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
		if(!pRoot)
			return true;
		return Judge(pRoot->left,pRoot->right);
		
    }
private:
	void LDR_1(vector<int>&output,TreeNode *pRoot)
	{
		if(pRoot)
		{
			output.push_back(pRoot->val);
			LDR_1(output,pRoot->left);
			LDR_1(output,pRoot->right);
		}
	}
	void LDR_2(vector<int>&output,TreeNode *pRoot)
	{
		if(pRoot)
		{
			output.push_back(pRoot->val);
			LDR_2(output,pRoot->right);
			LDR_2(output,pRoot->left);
		}
	}
	bool Judge(TreeNode *tree1,TreeNode *tree2)
	{
		if(tree1==NULL&&tree2==NULL)
			return true;
		if(!tree1||!tree2)
			return false;
		return (tree1->val==tree2->val)&&Judge(tree1->left,tree2->right)&&Judge(tree1->right,tree2->left);
	}
};






void main_demo37()
{
	Solution_demo37 s1;
	TreeNode t1(1),t2(2),t3(2),t4(4),t5(4),t6(4),t7(4);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	bool res = false;
	res = s1.isSymmetrical(&t1);
	if(res==true)
		cout<<"�����ǶԳƵĶ�����"<<endl;
	else
		cout<<"�������ǶԳƵĶ�����"<<endl;
	system("pause");
}