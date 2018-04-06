/*
2018年4月6日11:40:12
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
#include "iostream"
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
当B到达叶子结点，但是A没有到达叶子结点，也是正确的（B树是A树的一部分）
但是如果A树到达叶子结点而B树没有到达，返回false
因为不是二叉排序树，所以结点的值没有限制，如果不同的结点有相同的值，这就要注意了！
可能找到和B根结点一样的值，但是从该结点往下查看，发现结点没有对应，不要直接返回false！

因为可能有别的结点有相同的值，从该结点往下和B一样！此时要设置一个标志位，
当是子结构是返回true，当不是子结构时返回false，
此时再去搜索A的下一个结点，继续判断。

*/

class Solution_demo60 {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)   //@pRoot1  A树  @pRoot2  B树
	{
		if(pRoot1==NULL||pRoot2==NULL)
			return false;
		bool flag = false;
		
		if(pRoot1->val==pRoot2->val)
			flag = IsMatch(pRoot1,pRoot2);
		if(!flag)
		{
			flag = IsMatch(pRoot1->left,pRoot2)||IsMatch(pRoot1->right,pRoot2);
		}
		return flag;
	}
private:
	bool IsMatch(TreeNode *A,TreeNode *B)
	{
		if(B==NULL)
			return true;
		else
		{
			if(A==NULL)
				return false;
		}
		if(A->val==B->val)     //当前结点val值相等,在考虑左子树和右子树的情况
		{
			return IsMatch(A->left,B->left)&&IsMatch(A->right,B->right);
		}
		else
			return false;
	}
};

/*
A树和B树结点不是在同一个内存地址上的  只要保证结点间的关系和结点的val值 是子结构就可以
*/
void main_demo60()
{
	Solution_demo60 s1;
	TreeNode t1(8),t2(8),t3(7),t4(9),t5(2),t6(4),t7(7),t8(3);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	bool res = true;
	res = s1.HasSubtree(&t1,&t2);
	if(res)
	{
		cout<<"B树是A树的子结构"<<endl;
	}
	else
	{
		cout<<"B树不是A树的子结构"<<endl;
	}
	cout<<"sizeof(res):"<<sizeof(res)<<endl;
	system("pause");
}


/*
相关知识小结：
子树的意思是包含了一个结点，就得包含这个结点下的所有结点，一棵大小为n的二叉树有n个子树，
就是分别以每个结点为根的子树
子结构的意思是包含了一个结点，可以只取左子树或者右子树，或者都不取
*/