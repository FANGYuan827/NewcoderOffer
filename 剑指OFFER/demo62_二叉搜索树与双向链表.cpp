/*
2018年4月7日12:08:08
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
思路：
1、由于要求链表是有序的，可以借助二叉搜索树的中序遍历，因为中序遍历算法的特点就是从小到大访问结点
当遍历到根结点时，假设根结点的左侧已经处理好 只需要将根结点与上次访问的最近结点（左子树中值最大的结点）的指针连接好即可  进而更新当前链表的最后一个结点指针

2、由于中序遍历过程正好是转换成链表的过程，即可采用递归处理
*/
class Solution_demo62 {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)     //最后返回的结果是双向链表的头结点
    {
        if(pRootOfTree==NULL)
			return NULL;

		//处理二叉搜索树
		TreeNode *pLastNodeInList = NULL;
		pLastNodeInList = ConvertNode(pRootOfTree,pLastNodeInList);
		 
		//找到转换后的链表的头结点
		TreeNode* pHead = pLastNodeInList;
		while(pHead!=NULL&&pHead->left!=NULL)
		{
			pHead = pHead->left;
		}
		//返回头结点
		return pHead;
    }

	TreeNode* ConvertNode(TreeNode* pRootOfTree,TreeNode* pLastNodeInList)
	{
		if(pRootOfTree==NULL)
			return NULL;
		TreeNode *pCurrent = pRootOfTree;
		
		if(pCurrent->left!=NULL)   //递归处理左子树
		{
			pLastNodeInList = ConvertNode(pRootOfTree->left,pLastNodeInList);
		}

		pCurrent->left = pLastNodeInList;      //处理当前结点 将当前结点的左指针指向已经转换好的链表的最后一个位置
		
		if(pLastNodeInList!=NULL)            //将已经转换好的链表的最后一个结点的右指针指向当前结点 
		{
			pLastNodeInList->right = pCurrent;
		}

		pLastNodeInList = pCurrent;         //更新已经转换好的链表的最后一个结点 


		if(pCurrent->right!=NULL)          //递归处理右子树
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