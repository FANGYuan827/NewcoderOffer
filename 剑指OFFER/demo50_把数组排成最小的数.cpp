/*
2018年3月10日21:13:11
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include "iostream"
#include <sstream>
#include <algorithm>
#include <vector>
#include "string"
using namespace std;

/*
解题思路：
先将整型数组转换成String数组 然后将String数组排序 最后将排好序的字符串拼接起来

string数组的排序:
自定义一个比较大小的函数 比较两个字符串s1、s2大小的时候 先将它们拼接起来 
比较s1+s2 和 s2+s1那个大 如果s1+s2大 说明s2应该放在前面 按照这个规则 s2就应该排在s1前面
*/

class Solution_demo50 {
public:
    string PrintMinNumber(vector<int> numbers) {
        string s_res;
		if(numbers.size()<1)
		{
			return s_res;
		}
		int length = numbers.size();
		vector<string> str_tmp;
		for(int i=0;i<length;++i)
		{
			stringstream ss;
			ss<<numbers[i];
			str_tmp.push_back(ss.str());                  //将int类转换成了string类
		}
		sort(str_tmp.begin(),str_tmp.end(),Compare);
		vector<string>::iterator it;
		for(it=str_tmp.begin();it!=str_tmp.end();it++)
		{
			s_res+=*it;
		}
		return s_res;
    }
private:
	static bool Compare(const string &s1,const string s2)     //比较s1+s2 和 s2+s1的大小     //不加static  --->>>sort(str_tmp.begin(),str_tmp.end(),Compare); 编译不通过
	{
		string S1 = s1+s2;
		string S2 = s2+s1;
		return S1<S2;                //(s1+s2 < s2+s1返回true)
	}
	
};

/*
重要说明:
sort中的比较函数要声明为静态成员函数或者全局函数 不能作为普通成员函数 否则编译器会报错
因为非静态成员函数是依赖于具体的对象的，而std::sort这类函数是全局的 因此无法在sort中调用非静态成员函数
静态成员函数或者全局函数是不依赖于具体对象的，可以独立访问，无需创建任何对象实例就可以访问 
同时静态成员函数不可以调用类的非静态成员...
介绍：C++引入了ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含sstream.h头文件。
istringstream类用于执行C++风格的串流的输入操作。
ostringstream类用于执行C风格的串流的输出操作。 
stringstream类同时可以支持C风格的串流的输入输出操作。
小结：
1）在istringstream类中 构造字符串流时 空格会成为字符串参数的内部分界
2）istringstream类可以作为string与各种类型的转换途径
3）ignore函数参数：需要读取字符串的最大长度 需要忽略的字符
示例代码：
http://blog.csdn.net/sophia1224/article/details/53054698
*/

void main_demo50()
{
	Solution_demo50 s1;
	vector<int> v_input;

	v_input.push_back(97);
	v_input.push_back(32);
	v_input.push_back(321);

	string res = s1.PrintMinNumber(v_input);
	cout<<"所排成的最小的数为:"<<res<<endl;
	system("pause");
}