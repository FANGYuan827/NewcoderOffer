/*
2018年4月8日09:10:56
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
思路：按照路径一条一条的判断，再找路径的同时将结点的val加入到一维数组中，
当走到叶子结点时候满足条件加入二维数组 将一维数组的最后一位清除(不论该条路径是否满足要求)

找路径采用的是递归的方法
DFS解法：深度优先 
*/
class Solution_demo64{
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> >res;
		if(root==NULL)
			return res;
		vector<int>v_tmp;
		FindOnePath(root,v_tmp,res,expectNumber);
		return res;
    }
private:
	int FindOnePath(TreeNode* root,vector<int>&v_tmp,vector<vector<int> >&res,int expectNumber)
	{
		if(root!=NULL&&root->left==NULL&&root->right==NULL)          //当走到叶子结点时
		{
			v_tmp.push_back(root->val);
			if(expectNumber==Sum(v_tmp))
			{
				res.push_back(v_tmp);
				v_tmp.erase(v_tmp.begin()+v_tmp.size()-1);
			}
			else
			{
				v_tmp.erase(v_tmp.begin()+v_tmp.size()-1);
			}
			return -1;
		}
		if(root!=NULL)           //递归找路径
		{
			v_tmp.push_back(root->val);       //非叶子结点 将val值加入一维数组中
			
			FindOnePath(root->left,v_tmp,res,expectNumber);
			
			FindOnePath(root->right,v_tmp,res,expectNumber);

			v_tmp.erase(v_tmp.begin()+v_tmp.size()-1);      //左子树走完了 删除当前结点 进入右子树中
		}
		return 0;
	}
	int Sum(vector<int> &input)
	{
		vector<int>::iterator it;
		int sum = 0;
		for(it=input.begin();it!=input.end();it++)
		{
			sum+=*it;
		}
		return sum;
	}
};


void main_demo64()
{
	Solution_demo64 s1;
	TreeNode t1(10),t2(6),t3(4),t4(4),t5(8),t6(6),t7(-4);//,t8(8);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	vector<vector<int>>res;
	res = s1.FindPath(&t1,20);

	vector<vector<int> >::iterator it_2;
	vector<int>::iterator it_1;
	for(it_2=res.begin();it_2!=res.end();it_2++)
	{
		for(it_1 = (*it_2).begin();it_1!=(*it_2).end();it_1++)
			cout<<*it_1<<ends;
		cout<<endl;
	}
	system("pause");
}