/*
2018年3月15日14:17:47
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

#include "iostream"
using namespace std;

/*
解题思路：
链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c
来源：牛客网

解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
    首先，考虑特殊情况：
         1>两个字符串都为空，返回true
         2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
            匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
            功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
            所以有可能匹配成功）
    之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
    下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
    不为‘*’：
          1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
            匹配成功，继续匹配下一个；如果匹配失败，直接返回false。
			注意这里的“匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
            当前字符为‘.’,同时str的当前字符不为‘\0’。
          2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
            这里把这些情况都考虑到：
               a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
                跳过这个‘*’符号；
               b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
                不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
                由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
                当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
    之后再写代码就很简单了。
*/

/*
根据pattern的第二个字符是否是'*' 将问题分成两种大的情况
*/
/*****************函数递归调用*********************/
class Solution_demo53 {
public:
	bool match(char* str, char* pattern)
	{
		if(str==NULL||pattern==NULL)
		{
			return false;
		}
		if(*str=='\0'&&*pattern=='\0')      //字符串 模式都为空 返回true
			return true;
		if(*pattern=='\0'&&*str!='\0')      //字符串非空  模式为空 直接返回false
			return false;
		if(*(pattern+1)!='*')				//pattern的下一个字符不为'*'
		{
			if(*str == *pattern||(*str!='\0'&&*pattern=='.'))  //匹配成功就继续匹配剩下的字符串
			{
				return match(str+1,pattern+1);
			}
			else                                            //不匹配直接返回false
				return false;                 
		}
		else								  //pattern的下一个字符为'*'
		{
			if(*str==*pattern||(*str!='\0'&&*pattern=='.'))              //*表示1个的时候
			{
				return match(str,pattern+2)||match(str+1,pattern);          //
			}
			else
			{
				return match(str,pattern+2);     //*表示0个的时候
			}
		}
		return true;
	}
};


/*
第一种情况：
*str == *pattern  --->>> 匹配（字符相同） --->>>   str++;pattern++;
(*str!='\0'&&*pattern=='.') --->>> 匹配（字符跟'.'匹配了）--->>> str++;pattern++;

第二种情况:
match(str,pattern+2) --->>>匹配上了（字符相同）pattern+=2（跳过*） 
match(str+1,pattern) --->>>匹配上了（字符和'.'匹配）   为什么str+=1 --->>>主要是为了确定*表示前面一个字符到底出现了多少次....


match(str,pattern+2) --->>>没有匹配上（*表示前面的字符出现0次）
*/

void main_demo53()
{
	Solution_demo53 s1;
	char *str = "aaa";
	char *pattern = "a*a";
	char *pattern_1 ="ab*a*c*a"; 
	bool res = s1.match(str,pattern);
    
	if(res)
		cout<<"匹配"<<endl;
	else
		cout<<"不匹配"<<endl;
	system("pause");
}

