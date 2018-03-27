/*
2018年3月1日09:23:46
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
输出描述：
-1表示空字符串的输入;
字符的位置从0开始;
*/

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class 	Solution_demo38{
public:
    int FirstNotRepeatingChar(string str) {         //书本解法：先在hash表中统计个字母出现的次数 第二次扫描直接访问hash表获得次数
		if(str.size()==0)
		{
			cout<<"字符串长度为0"<<endl;
			return -1;
		}
		for(int i=0;i<str.size();i++)
		{
			vec_res.push_back(str[i]);
			Table[str[i]]++;
		}
		for(int i=0;i<vec_res.size();i++)
		{
			if(Table[vec_res[i]] == 1)
			{
				return i;
			}
		}
		return -1;
    }
	Solution_demo38()
	{
		memset(Table,0,128);
	}
private:
	vector<char>vec_res;
	char Table[128];
};



void main_demo38()
{
	Solution_demo38 s1;
	string str = "google";
	//str = "";
	//cout<<str[0]<<endl;
	int pos = s1.FirstNotRepeatingChar(str);
	cout<<"第一次只出现一次的字符的位置是："<<pos<<endl;
	system("pause");
}