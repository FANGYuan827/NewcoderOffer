/*
2018年3月29日16:21:56
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;


class Solution_demo22 {
public:
    vector<string> Permutation(string str) {
		vector<string> v_res;
		if(str.size()<=1)
		{
			v_res.push_back(str);
			return v_res;
		}


		return v_res;
        
    }
};


//VS下运行有问题  并没有运行这个cpp文件下的main()函数  从新添加了一个cpp文件 一切正常了 不知道为什么
void main_demo22()
{
	string str = "a";
	vector<string>v_res;
	Solution_demo22 s1;
	v_res = s1.Permutation(str);
	vector<string>::iterator it;
	for(it=v_res.begin();it!=v_res.end();it++)
	{
		cout<<*it<<endl;
	}
	system("pause");
}