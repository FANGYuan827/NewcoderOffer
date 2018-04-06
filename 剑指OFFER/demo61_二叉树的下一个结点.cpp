/*
2018��4��6��17:06:37
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
�Լ��Ľ���˼·��
��������������ص㣬Ҫ�ҵ�һ���ڵ����һ���ڵ��޷Ǿ������������
1��������������ʱֻ��Ҫ�����Һ�����Ϊ��һ�������ģ�������Ҫ�ҵģ��ڵ㣬
Ȼ�����Ÿýڵ��������������еĻ���������ֱ������Ҷ�ӽڵ㣬��ô��Ҷ�ӽڵ��������һ��Ҫ�ҵĽڵ㣻

2��û�������������жϸýڵ��Ƿ����丸�ڵ�����ӣ������ ������һ��Ҫ�ҵĽڵ����丸�ڵ㣻

3����������丸�ڵ�����ӣ�����丸�ڵ���Ϊ��һ�������Ľڵ㣬���ϻ���,ֱ���ҵ����ڵ� 
û�и��ڵ㲢�Ҹ��ڵ��Ǹ��ڵ�ĸ��ڵ������Ϊֹ��

�ۺ�����������Ϳ����ҵ�������������һ���ڵ����һ���ڵ㡣
*/
class Solution_demo60 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		if(pNode==NULL)
			return NULL;
        TreeLinkNode *res = NULL;
		if(pNode->right!=NULL)     //�������������
		{
			res = pNode->right;
			while(res->left!=NULL)    //����������һֱ�ҵ�Ҷ�ӽ��
			{
				res = res->left;
			}
			return res;
		}
        
		if(pNode->right==NULL)   //û������������� 
		{
            if(pNode->next==NULL)
                return NULL;
            res = pNode->next;
			
            if(res->left==pNode)    //����ý�����丸��������
			{
				res = pNode->next;
				return res;
			}
			                       //�ý�㲻���丸��������
			res = pNode->next; 
			while(res->next!=NULL)    //�ҵ������
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
		cout<<"�������н��Ϊ:"<<res->val<<endl;
	system("pause");
}

/*
����˼·��
��������������һ����㣬һ����һ�������
1��������Ϊ�� �򷵻ؿգ�

2���ý���Һ��Ӵ��ڣ�������һ��ָ��Ӹý����Һ��ӳ������ҳ��ý���Һ��ӵ���������Ҷ�ӽ�� ��Ϊ��һ�����

3����㲻�Ǹ���� 
����ý�����丸�������ӣ��򷵻ظ��׽��
���򣨲����丸�׽������㣩�������ϱ����ý��ĸ����ĸ���� �ظ�֮ǰ���жϣ� ���ؽ��
*/