/*
2018年4月17日18:46:52
请实现两个函数，分别用来序列化和反序列化二叉树

如果二叉树的序列化是从根结点开始的，那么对应的二叉树反序列化也是从根结点开始的。
因此可以使用二叉树的前序遍历来序列化二叉树，当前序遍历碰到NULL值时，使用'#'表示 每一个结点的数值之间用'，'隔开。
*/
#include "iostream"
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution_demo68 {
public:
    char* Serialize(TreeNode *root) {    
        if(root == NULL)
		{
			return NULL;
		}
		string str;
		Serialize(root,str);
		int length = str.size();
	    char *res = (char *)calloc(length,sizeof(char));
		strcpy(res,str.c_str());
		return res;
    }
    TreeNode* Deserialize(char *str) 
	{
		if(str == NULL)
		{
			return NULL;
		}
		return deserialize(&str);
    }
private:
	void Serialize(TreeNode *root,string &str)
	{
		if(root==NULL)
		{
			str += '#';
			return;
		}
		str += to_string((long double)root->val);
		//str += NumToStr(root->val);
		str+=',';
        Serialize(root->left,str);
		Serialize(root->right,str);
	}
	string NumToStr(int num)
	{
		char str[100];
		sprintf(str,"%d",num);
		return str;
	}
	TreeNode *deserialize(char **str)
	{
		if(**str == '#')
		{	
			++(*str);
			return NULL;
		}
		int val = 0;
		while(**str!=','&&**str!='\0')
		{
			val = val*10+(**str-'0');
			++(*str);
		}
		TreeNode *root = new TreeNode(val);
		if(**str == '\0')
		{
			return root;
		}
		else
		{
			++(*str);
		}
		root->left = deserialize(str);
		root->right = deserialize(str);
		return root;
	}
};
void  main()
{
	Solution_demo68 s1;
	TreeNode t1(1),t2(6),t3(3),t4(4),t5(8),t6(6),t7(77);//,t8(8);//t8(8),t9(9),t10(10);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	char *res = NULL;
	res = s1.Serialize(&t1);
	if(res!=NULL)
		cout<<res<<endl;

	system("pause");
}