/*
2018年4月6日17:06:37
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

#include "iostream"
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
/*
自己的解题思路：
根据中序遍历的特点，要找到一个节点的下一个节点无非就是三种情况：
1、有右子树，这时只需要把其右孩子作为下一个遍历的（并不是要找的）节点，
然后沿着该节点的左子树（如果有的话）出发，直到遇到叶子节点，那么该叶子节点就是其下一个要找的节点；

2、没有右子树，则判断该节点是否是其父节点的左孩子，如果是 则其下一个要找的节点是其父节点；

3、如果不是其父节点的左孩子，则把其父节点作为下一个遍历的节点，向上回溯,直到找到父节点 
没有父节点并且父节点是父节点的父节点的左孩子为止。

综合这三种情况就可以找到二叉树中任意一个节点的下一个节点。
*/
class Solution_demo60 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		if(pNode==NULL)
			return NULL;
        TreeLinkNode *res = NULL;
		if(pNode->right!=NULL)     //有右子树的情况
		{
			res = pNode->right;
			while(res->left!=NULL)    //沿着左子树一直找到叶子结点
			{
				res = res->left;
			}
			return res;
		}
        
		if(pNode->right==NULL)   //没有右子树的情况 
		{
            if(pNode->next==NULL)
                return NULL;
            res = pNode->next;
			
            if(res->left==pNode)    //如果该结点是其父结点的左孩子
			{
				res = pNode->next;
				return res;
			}
			                       //该结点不是其父结点的左孩子
			res = pNode->next; 
			while(res->next!=NULL)    //找到父结点
			{
				if(res == res->next->left)
					return res->next;
                res = res->next;
			}
		}
		return NULL;
    }
};


void main()
{
	Solution_demo60 s1;
	TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8);
	t1.left = &t2;
	t1.right = &t3;

	t2.left = &t4;
	t2.right = &t5;
	t2.next = &t1;
	
	t3.left = &t6;
	t3.right = &t7;
	t3.next = &t1;

	t4.next = &t2;
	t5.next = &t2;

	t6.next = &t3;
	t7.next = &t3;

	TreeLinkNode *res = NULL;
	res = s1.GetNext(&t2);
	if(res!=NULL)
		cout<<"程序运行结果为:"<<res->val<<endl;
	system("pause");
}

/*
其他思路：
分析二叉树的下一个结点，一共有一下情况：
1、二叉树为空 则返回空；

2、该结点右孩子存在，则设置一个指针从该结点的右孩子出发，找出该结点右孩子的左子树的叶子结点 即为下一个结点

3、结点不是根结点 
如果该结点是其父结点的左孩子，则返回父亲结点
否则（不是其父亲结点的左结点）继续向上遍历该结点的父结点的父结点 重复之前的判断， 返回结果
*/