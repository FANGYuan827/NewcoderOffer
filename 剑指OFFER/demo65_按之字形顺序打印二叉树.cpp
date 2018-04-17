/*
2018年4月10日08:57:38
请实现一个函数按照之字形打印二叉树，即:
第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
*/
#include "iostream"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//广度优先......

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution_demo65 {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> >v_res;
		if(pRoot==NULL)
			return v_res;
		queue<TreeNode *>q_tmp;
		vector<int> v_tmp;
		q_tmp.push(pRoot);
		int i = 0;
		while(q_tmp.size()!=0)
		{
			int count = 0,nextCount = q_tmp.size();
			while(count++<nextCount)
			{
				TreeNode *top = q_tmp.front();
				q_tmp.pop();
				v_tmp.push_back(top->val);
				if(top->left!=NULL)
					q_tmp.push(top->left);
				if(top->right!=NULL)
					q_tmp.push(top->right);
			}
			i++;
			if(i%2==0)      //判断奇偶层 决定是否翻转
			{
				reverse(v_tmp.begin(),v_tmp.end());
			}
			v_res.push_back(v_tmp);
			v_tmp.clear();
		}
		return v_res;
    }
};

void main_demo65()
{
	Solution_demo65 s1;
	TreeNode t1(10),t2(6),t3(4),t4(4),t5(8),t6(6),t7(-4),t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t4.left = &t8;
	t5.right = &t9;
	t8.right = &t10;

	vector<vector<int>>res;
	res = s1.Print(&t1);

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