/*
2018年1月15日21:15:31
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/*
 解题思路：
 1)先从先序遍历中找出根结点 再根据根结点在中序遍历中的位置 区分出左子树和右子树
 2)在左子树中 找出左子树的根结点（在先序遍历中找） 转步骤1
   在右子树中 找出右子树的根结点（在先序遍历中找） 转步骤1
关键 是如何把左子树、右子树给分别提取出来;
*/
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;



/*
 Definition for binary tree
*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.size()==0||vin.size()==0)
		{
			return NULL;
		}
		int len = vin.size();
		vector<int> left_pre,right_pre,left_in,right_in;
		//int i = 0,j = 0,k = 0;
		int gen_position = 0;
		TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
		if(tmp == NULL)
		{
			return NULL;
		}
		//while(i<len)
		for(int i = 0;i<len;i++)
		{
			if(vin[i]==pre[0])
			{
				gen_position = i;
				break;
			}
		}
		//vector<int> vin_tmp1(10),vin_tmp2(10);
		
		for(int i =0;i<gen_position;i++)
		{
			left_in.push_back(vin[i]);       //直接访问vector的某个元素会报错(超出范围)  但是利用对象的方法:push_back()来进行元素的插入就不会直接报错(out of range)
			left_pre.push_back(pre[i+1]);
		}
		for(int i = gen_position+1;i<len;i++)
		{
			right_in.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		tmp->val = pre[0];
		tmp->left = reConstructBinaryTree(left_pre,right_in);
		tmp->right = reConstructBinaryTree(right_pre,right_in);
		return tmp;
    }
};

void LDR(TreeNode *root)     //先序遍历一棵树
{
	if(root)
	{
		printf("%d  ",(root->val));
		LDR(root->left);
		LDR(root->right);
		//printf("\n");
	}

}


void main_demo23()
{
	// vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
    //vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Solution s1;
	vector<int> pre(8); //{1,2,4,7,3,5,6,8};
	vector<int> vin(8); //{4,7,2,1,5,84,8,6};
	pre[0] = 1;
	pre[1] = 2;
	pre[2] = 4;
	pre[3] = 7;
	pre[4] = 3;
	pre[5] = 5;
	pre[6] = 6;
	pre[7] = 8;

	vin[0] = 4;
	vin[1] = 7;
	vin[2] = 2;
	vin[2] = 1;
	vin[2] = 5;
	vin[2] = 3;
	vin[2] = 8;
	vin[2] = 6;

	TreeNode *tmp = NULL;
	tmp = s1.reConstructBinaryTree(pre,vin);

	LDR(tmp);
	printf("\n");
	system("pause");
}



/*
public class Solution {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in)
	{
        TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    private TreeNode reConstructBinaryTree(int [] pre,int startPre,int endPre,int [] in,int startIn,int endIn) 
	{
        if(startPre>endPre||startIn>endIn)
            return null;
        TreeNode root=new TreeNode(pre[startPre]);    //新建一个业务结点 
        for(int i=startIn;i<=endIn;i++)
            if(in[i]==pre[startPre])			//确定根结点的位置
			{
                root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);			// 直接将树结点带进去 而不是在另外分配内存来存储左右子树
                root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
                break;
            }
        return root;
    }
}
*/





