/*
2018��1��16��14:19:35
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·����
�·���ĳ���Ϊ������ȡ�
*/


/*
����˼·��
�ֱ��������� ����������� ȡ�����д��һ�� ����1 
���ֵ��Ϊ�������
���õݹ�ķ������
*/

#include "iostream"
#include <list>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


//�ݹ鷨ʵ��
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
		if(pRoot==NULL)
		{
			return 0;
		}
		int left_depth = 0,right_depth = 0;
		left_depth = TreeDepth(pRoot->left);
		right_depth = TreeDepth(pRoot->right);
		return (left_depth>right_depth?left_depth:right_depth)+1;
       
    }
};
 //�ǵݹ�ʵ��
 //˼��:nextCount��¼ÿ��Ԫ�صĸ��� count��¼�ò��Ԫ���Ƿ�ȫ������ ���ȫ������depth+1 ������ϵ���
class Solution_1 {
public:
	int TreeDepth(TreeNode *pRoot)
    {
        if(pRoot == NULL){
            return 0;
        }
        //Queue<TreeNode> queue = new LinkedList<TreeNode>();
		list<TreeNode *>l;
		l.push_back(pRoot);
        int depth = 0, count = 0, nextCount = 1;    
        while(l.size()!=0){
			TreeNode *top = l.front();
			l.pop_front();
            count++;
            if(top->left != NULL)
			{
				l.push_back(top->left);
            }
            if(top->right != NULL)
			{
				l.push_back(top->right);
            }
            if(count == nextCount)
			{
                nextCount = l.size();
                count = 0;
                depth++;
            }
        }
        return depth;
    }
};


void main_demo24()
{
	 Solution s1;
	 Solution_1 s_1;
	 int deepth = 0;
	 struct TreeNode t1(1),t2(2),t3(3),t4(4);
	 t1.left = &t2;
	 t2.left = &t3;
	 t1.right = &t4;
	// deepth = s1.TreeDepth(&t1);
	 deepth = s_1.TreeDepth(&t1);
	 printf("�����������Ϊ:%d\n",deepth);
	 system("pause");
}