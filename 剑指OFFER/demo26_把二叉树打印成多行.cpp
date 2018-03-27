/*
2018��1��16��16:13:43
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
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
��α�������
����˼·
�����Ľ�����ڶ�����,ͬһ���������ҽ�����������λ�� Ȼ����ݶ��е��Ƚ��ȳ����ص� ��һ����������������������ŻὫ���
���������ӽ���������� 
�����롰�������´�ӡ������ͬ�ĵط����� ��Ҫ���ֳ����Ĳ�� ������Ҫ ȷ��ÿһ�����Ľ����� ������ͳ�� �������֮�������һ�� 
ֱ������Ϊ��  ��ʾ���н�㶼���������...... 
@nextCount��ʾ��ǰ��Ľ����
@count ��ʾ��ǰ�����ѱ�������ĸ���

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