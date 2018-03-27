/*
2018年3月1日10:34:20
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/



#include "iostream"
#include <vector>
#include <stack>
using namespace std;


/*
思路：借用一个辅助的栈 遍历压栈顺序，先将第一个放入栈中 然后判断栈顶元素是不是出栈顺序的第一个元素 如果不相等 
我们就继续压栈 直到相等以后开始出栈 出栈第一个元素 则将出栈顺序向后移动一位 直到不相等 
这样循环 等压栈顺序遍历完成 如果辅助栈还不为空 说明弹出序列不是该栈的出栈序列
*/
class Solution_demo39 {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		if(pushV.size()!=popV.size())
		{
			return false;
		}
		if(pushV.size()==1)
		{
			if(pushV[0]==popV[0])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		stack<int> tmp_stack;
		int i = 0;
		int j = 0;
		tmp_stack.push(pushV[0]);
		i++;
		while(i < pushV.size())
		{
			if(tmp_stack.empty())
			{
				tmp_stack.push(pushV[i]);
				i++;
			}
			while(tmp_stack.top()!=popV[j])		
			{
				if(i==pushV.size())
				{
					break;
				}
				tmp_stack.push(pushV[i]);
				i++;
			}
			while(tmp_stack.empty()==0&&tmp_stack.top()==popV[j])
			{
				tmp_stack.pop();
				j++;
			}
		}
		return tmp_stack.empty();
	}
	bool IsPopOrder_2(vector<int> pushV,vector<int> popV) {
		if(pushV.size()!=popV.size())
		{
			return false;
		}
		if(pushV.size()==1)
        {
            if(pushV[0]!=popV[0])
            {
                return false;
            }
            else
                return true;
        }
		int count = 0;
		bool flag = true;
		int length = popV.size();
		for(int i =0;i<pushV.size();i++)
		{
			if(pushV[i]==popV[0])
			{
				count = i;
			}
		}
		for(int i = 0;i<count;i++)
		{
			if(pushV[i]==popV[length-1-i])
			{
				continue;
			}
			else
			{
				flag = false;
				return false;
			}
		}
		return flag;
	}
};
/*

网上大神的代码：
class Solution{
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		if(pushV.size()!=popV.size())
		{
			return false;
		}
		stack<int> tmp_stack;
		int i = 0;
		int j = 0;
		while(i < pushV.size())
		{
			tmp_stack.push(pushV[i]);
			while(!tmp_stack.empty()&&tmp_stack.top()==popV[j])
			{
				tmp_stack.pop();
				j++;
			}
			i++;     
		}
		return tmp_stack.empty();
	}
};
*/
/*
链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
来源：牛客网

好多人用辅助栈来求解，完全没有必要！我的思路：取出弹出序列的第一个元素，然后找到此元素
在入栈序列的位置n，那么入栈序列的前n个元素如果依次等于弹出序列从后往前数的n个元素，那么此
弹出序列就是正确的弹出序列！代码如下，测试已通过:
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size())
            return false;
        int address=-1;   
 
for(int i=0;i<pushV.size();i++) // 找弹出序列的第一个元素在入栈序列中的位置
        {
            if(pushV[i]==popV[0])
                address=i;
        }
        if(address==-1)// 没找到，失败
            return false;
           // 将弹出序列逆序显示
        vector<int> temp=vector<int>(popV.rbegin(),popV.rend());
        for(int i=0;i<address;i++)
        {
            if(pushV[i]!=temp[i])// 若有一个不相等，失败
                return false;
        }
        return true;
    }
};
*/


void main_demo39()
{
	Solution_demo39 s1;
	vector<int>v1;
	vector<int>v2;
	for(int i = 0;i<5;i++)
	{
		v1.push_back(i+1);
	}
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);
	bool res = s1.IsPopOrder_2(v1,v2);
	if(res)
	{
		cout<<"序列2是序列1的出栈序列"<<endl;
	}
	else
		cout<<"序列2不是序列1的出栈序列"<<endl;


	system("pause");
}

