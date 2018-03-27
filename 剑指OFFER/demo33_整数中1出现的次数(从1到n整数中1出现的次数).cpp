/*
2018年2月7日10:41:04
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/
#include "iostream"
#include "vector"
#include <sstream>
using namespace std;

/*
下面这个方法是自己想出来的，傻瓜式方法 
解题思路：
直接循环遍历
通过将数字转换成字符串，然后逐个判断字符串的字符是不是等于'1'
非常耗时间......
*/
class Solution_demo33 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if(n<1)
			return 0;
		if(n<10)
			return 1;
		int count = 0;
		for(int i=1;i<=n;i++)
		{
			count+=CountNumOf1(i);
		}
		return count;
	}
private:
	int GetHigh(int num)
	{
		while(num>10)
		{
			num/=10;
		}
		return num;
	}
	int CountNumOf1(int num)
	{
		vector<string> v_res;
		int count = 0;
		stringstream ss;
		ss<<num;
		v_res.push_back(ss.str());
		char *str = (char *)malloc(sizeof(int)*5);
		string str_tmp = v_res[0];
		for(int i=0;i<str_tmp.size();i++)
		{
			if(str_tmp.at(i)=='1')
				count++;
		}
		if(str!=NULL)
		{
			free(str);
		}
		return count;
	}
};

/*
网上的思路：
链接：https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
来源：牛客网
设N = abcde ,其中abcde分别为十进制中各位上的数字。
如果要计算百位上1出现的次数，它要受到3方面的影响：百位上的数字，百位以下（低位）的数字，百位以上（高位）的数字。

① 如果百位上数字为0，百位上可能出现1的次数由更高位决定。
比如：12013，则可以知道百位出现1的情况可能是：100~199，1100~1199,2100~2199，，...，11100~11199，一共1200个。
可以看出是由更高位数字（12）决定，并且等于更高位数字（12）乘以 当前位数（100）。

② 如果百位上数字为1，百位上可能出现1的次数不仅受更高位影响还受低位影响。
比如：12113，则可以知道百位受高位影响出现的情况是：100~199，1100~1199,2100~2199，，....，11100~11199，一共1200个。
和上面情况一样，并且等于更高位数字（12）乘以 当前位数（100）。
但同时它还受低位影响，百位出现1的情况是：12100~12113,一共114个，等于低位数字（113）+1。

③ 如果百位上数字大于1（2~9），则百位上出现1的情况仅由更高位决定，
比如12213，则百位出现1的情况是：100~199,1100~1199，2100~2199，...，11100~11199,12100~12199,一共有1300个，
并且等于更高位数字+1（12+1）乘以当前位数（100）。
*/
class Solution_demo33_1 {
public:
	int NumberOf1Between1AndN_Solution(int n){
		if(n<1)
			return 0;
		if(n<10)
			return 1;
		int count = 0;
		int i = 1;
		int current = 0,after = 0,before = 0;
		while((n/i)!=0)
		{
			current = (n/i)%10;     //当前位
			before = n/(i*10);     //得到高位
			after = n-(n/i)*i;    //得到低位
			if(current==0)
				count+=before*i;
			else
				if(current==1)
					count+=before*i+after+1;
				else
					count+=(before+1)*i;
			i*=10;
		}
		return count;
	}
};



void main_demo33()
{
	Solution_demo33_1 s1;
	int res = 0;
	int input = 0;
	printf("请输入一个任一非负整数: ");
	scanf("%d",&input);
	res = s1.NumberOf1Between1AndN_Solution(input);
	printf("所求结果为res=%d\n",res);
	system("pause");
}