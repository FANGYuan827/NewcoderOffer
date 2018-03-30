/*
2018年3月29日16:21:56
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
#include "iostream"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
算法思路：全排列可以看做固定前i位，对第i+1位之后的再进行全排列
比如固定第一位，后面跟着n-1位的全排列
那么解决n-1位元素的全排列就能解决n位元素的全排列了，这样的设计很容易就能用递归实现
*/
class Solution_demo56 {
public:
    vector<string> Permutation(string str) 
	{
		vector<string> v_res;
		vector<char> v_tmp;
		if(str.length()<1)
		{
			return v_res;
		}
		
		if(str.length()==1)
		{
			v_res.push_back(str);
			return v_res;
		}
		
		char ch = str.at(0);
		int count = 0;
		for(int i=0;i<str.length();i++)
		{
			char tmp = str.at(i);
			if(tmp==ch)
				count++;
			v_tmp.push_back(tmp);
		}
		if(count==str.length())
		{
			v_res.push_back(str);
			return v_res;
		}
		//sort(v_tmp.begin(),v_tmp.end());     //按字典序排序
		Permutation_1(v_res,v_tmp,0,v_tmp.size()-1);
		sort(v_res.begin(),v_res.end());
		return v_res;
    }
	void Permutation_1(vector<string> &v_res,vector<char> &v,int start,int end)
	{
		string s_tmp;
		if(start==end)
		{
			for(int i=0;i<=end;++i)
			{
				s_tmp+=v[i];
			}
			v_res.push_back(s_tmp);
		}
		else
		{
			for(int i=start;i<=end;++i)
			{
				if(Is_MySwap(v,start,i))
				{
					My_Swap(v[i],v[start]);
					Permutation_1(v_res,v,start+1,end);
					My_Swap(v[i],v[start]);
				}
			}
		}
	}
	void My_Swap(char &c1,char &c2)
	{
		char tmp = c1;
		c1 = c2;
		c2 = tmp;
	}
	bool Is_MySwap(vector<char> &v,int start,int end)
	{
		for(int i=start;i<end;i++)
			if(v[i]==v[end])
				return false;
		return true;
	}
};

void main()
{
	string str = "aabb";
	vector<string>v_res;
	Solution_demo56 s1;
	v_res = s1.Permutation(str);
	vector<string>::iterator it;
	for(it=v_res.begin();it!=v_res.end();it++)
	{
		cout<<*it<<endl;
	}
	system("pause");
}