/*
2018��4��6��11:40:12
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
��B����Ҷ�ӽ�㣬����Aû�е���Ҷ�ӽ�㣬Ҳ����ȷ�ģ�B����A����һ���֣�
�������A������Ҷ�ӽ���B��û�е������false
��Ϊ���Ƕ��������������Խ���ֵû�����ƣ������ͬ�Ľ������ͬ��ֵ�����Ҫע���ˣ�
�����ҵ���B�����һ����ֵ�����ǴӸý�����²鿴�����ֽ��û�ж�Ӧ����Ҫֱ�ӷ���false��

��Ϊ�����б�Ľ������ͬ��ֵ���Ӹý�����º�Bһ������ʱҪ����һ����־λ��
�����ӽṹ�Ƿ���true���������ӽṹʱ����false��
��ʱ��ȥ����A����һ����㣬�����жϡ�

*/

class Solution_demo60 {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)   //@pRoot1  A��  @pRoot2  B��
	{
		if(pRoot1==NULL||pRoot2==NULL)
			return false;
		bool flag = false;
		
		if(pRoot1->val==pRoot2->val)
			flag = IsMatch(pRoot1,pRoot2);
		if(!flag)
		{
			flag = IsMatch(pRoot1->left,pRoot2)||IsMatch(pRoot1->right,pRoot2);
		}
		return flag;
	}
private:
	bool IsMatch(TreeNode *A,TreeNode *B)
	{
		if(B==NULL)
			return true;
		else
		{
			if(A==NULL)
				return false;
		}
		if(A->val==B->val)     //��ǰ���valֵ���,�ڿ����������������������
		{
			return IsMatch(A->left,B->left)&&IsMatch(A->right,B->right);
		}
		else
			return false;
	}
};

/*
A����B����㲻����ͬһ���ڴ��ַ�ϵ�  ֻҪ��֤����Ĺ�ϵ�ͽ���valֵ ���ӽṹ�Ϳ���
*/
void main_demo60()
{
	Solution_demo60 s1;
	TreeNode t1(8),t2(8),t3(7),t4(9),t5(2),t6(4),t7(7),t8(3);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	bool res = true;
	res = s1.HasSubtree(&t1,&t2);
	if(res)
	{
		cout<<"B����A�����ӽṹ"<<endl;
	}
	else
	{
		cout<<"B������A�����ӽṹ"<<endl;
	}
	cout<<"sizeof(res):"<<sizeof(res)<<endl;
	system("pause");
}


/*
���֪ʶС�᣺
��������˼�ǰ�����һ����㣬�͵ð����������µ����н�㣬һ�ô�СΪn�Ķ�������n��������
���Ƿֱ���ÿ�����Ϊ��������
�ӽṹ����˼�ǰ�����һ����㣬����ֻȡ���������������������߶���ȡ
*/