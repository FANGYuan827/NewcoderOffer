/*
2018年4月7日16:01:47
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
#include "iostream"
#include <vector>
using namespace std;

/*
思路：
1、二叉搜索树：树的左结点小于根结点 右结点大于根结点
2、后序遍历：遍历的末结点是根结点
3、由末结点分开左子树和右子树两部分，再判断右子树是否全部大于根结点 是 则递归判断左子树和右子树两部分是否符合二叉搜索树
*/

class Solution_demo63 {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size()<1)
			return false;
		return VerifySquenceOfBST_SubTree(sequence,0,sequence.size()-1);
    }

private:
	bool VerifySquenceOfBST_SubTree(vector<int> &sequence,int start,int end)
	{
		if(start>=end)					//只剩一个结点是 符合要求  （递归结束的条件）
			return true;

		int RootPos = 0;
		for(int i=RootPos;sequence[i]<sequence[end]&&RootPos<end-1;i++)
		{
			RootPos++;    //找到左、右子树的分界位置
		}
		for(int i=RootPos;i<end-1;i++)
		{
			if(sequence[i]<sequence[end])  
				return false;
		}
		return VerifySquenceOfBST_SubTree(sequence,start,RootPos-1)&&VerifySquenceOfBST_SubTree(sequence,RootPos,end-1);     //递归的条件不是固定不变的
	}
};


void main_demo63()
{
	Solution_demo63 s1;
	vector<int> input;
	input.push_back(4);
	input.push_back(8);
	input.push_back(6);
	input.push_back(12);
	input.push_back(16);
	input.push_back(14);
	input.push_back(10);

	bool res = false;
 	res = s1.VerifySquenceOfBST(input);
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	system("pause");
}