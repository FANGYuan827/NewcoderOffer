/*
2018年1月16日16:13:43
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

#include "iostream"
#include <list>
#include <queue>
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
层次遍历法：
解题思路
将树的结点存放在队列中,同一个结点的左右结点会存放在相邻位置 然后根据队列的先进先出的特点 将一个结点的数据域入数组紧接着会将这个
结点的左右子结点继续入队列 
这题与“从上往下打印树”不同的地方就是 需要划分出树的层次 所以需要 确定每一层树的结点个数 并进行统计 处理完成之后进入下一层 
直到队列为空  表示所有结点都处理完成了...... 
@nextCount表示当前层的结点数
@count 表示当前层结点已被处理结点的个数

*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> >v_tmp;
		vector<int> v_tmp2;
		if(pRoot==NULL)
		{
			return v_tmp;
		}
		int i = 0;
		queue<TreeNode *>q_tmp;
		q_tmp.push(pRoot);
		while(q_tmp.size()!=0)
		{
			int count = 0 ,nextCount = q_tmp.size();
			//TreeNode *top = q_tmp.front();
			while(count++<nextCount)
			{
				//i++;
				TreeNode *tmp = q_tmp.front();
				q_tmp.pop();
				v_tmp2.push_back(tmp->val);
				if(tmp->left!=NULL)
				{
					q_tmp.push(tmp->left);
				}
				if(tmp->right!=NULL)
				{
					q_tmp.push(tmp->right);
				}
			}
			i++;
			v_tmp.push_back((i,v_tmp2));
			v_tmp2.clear();
		}
		return v_tmp;
	}

};




void main_demo26()
{
	Solution s1;
	vector<vector<int> > v_res;
	vector<vector<int> >::iterator iter; 
	struct TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	v_res = s1.Print(&t1);
	for(iter = v_res.begin();iter!=v_res.end();iter++)
	{
		vector<int> ::iterator iter_1;
		for(iter_1=(*iter).begin();iter_1!=(*iter).end();iter_1++)
		{
			printf("%d ",*iter_1);
		}
		printf("\n");
	}

	system("pause");
}