/*
2018��4��7��12:08:08
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
˼·��
1������Ҫ������������ģ����Խ��������������������������Ϊ��������㷨���ص���Ǵ�С������ʽ��
�������������ʱ���������������Ѿ������ ֻ��Ҫ����������ϴη��ʵ������㣨��������ֵ���Ľ�㣩��ָ�����Ӻü���  �������µ�ǰ��������һ�����ָ��

2�����������������������ת��������Ĺ��̣����ɲ��õݹ鴦��
*/
class Solution_demo62 {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)     //��󷵻صĽ����˫�������ͷ���
    {
        if(pRootOfTree==NULL)
			return NULL;

		//�������������
		TreeNode *pLastNodeInList = NULL;
		pLastNodeInList = ConvertNode(pRootOfTree,pLastNodeInList);
		 
		//�ҵ�ת����������ͷ���
		TreeNode* pHead = pLastNodeInList;
		while(pHead!=NULL&&pHead->left!=NULL)
		{
			pHead = pHead->left;
		}
		//����ͷ���
		return pHead;
    }

	TreeNode* ConvertNode(TreeNode* pRootOfTree,TreeNode* pLastNodeInList)
	{
		if(pRootOfTree==NULL)
			return NULL;
		TreeNode *pCurrent = pRootOfTree;
		
		if(pCurrent->left!=NULL)   //�ݹ鴦��������
		{
			pLastNodeInList = ConvertNode(pRootOfTree->left,pLastNodeInList);
		}

		pCurrent->left = pLastNodeInList;      //����ǰ��� ����ǰ������ָ��ָ���Ѿ�ת���õ���������һ��λ��
		
		if(pLastNodeInList!=NULL)            //���Ѿ�ת���õ���������һ��������ָ��ָ��ǰ��� 
		{
			pLastNodeInList->right = pCurrent;
		}

		pLastNodeInList = pCurrent;         //�����Ѿ�ת���õ���������һ����� 


		if(pCurrent->right!=NULL)          //�ݹ鴦��������
		{
			pLastNodeInList = ConvertNode(pRootOfTree->right,pLastNodeInList);
		}
		return pLastNodeInList;
	}
	
};



void main_demo62()
{
	Solution_demo62 s1;
	TreeNode t1(10),t2(6),t3(14),t4(4),t5(8),t6(12),t7(16);//,t8(8);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	TreeNode *res = NULL;
	res = s1.Convert(&t1);
	while(res!=NULL)
	{
		cout<<res->val<<"->";
		res = res->right;
	}
	cout<<endl;
	system("pause");
}