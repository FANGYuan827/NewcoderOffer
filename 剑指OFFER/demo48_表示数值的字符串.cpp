/*
2018年3月6日10:25:52
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）.
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值.
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是.
*/
#include "iostream"
using namespace std;

class Solution_demo48 {
public:
	bool isNumeric(char* string)
	{
		if(string==NULL)
		{
			return false;
		}
		int point_count = 0;
		int e_positon = 0;
		if(string[0]=='E'||string[0]=='e')
		{
			return false;
		}
		if(!(string[0]>='0'&&string[0]<='9'||string[0]!='-'||string[0]!='+'))
		{
			return false;
		}
		e_positon = Get_E_Position(string);
		if(string[e_positon+1]=='\0')
			return false;
		if(e_positon==-1)      //非0表示找到了E的位置
		{
			return false;
		}
		for(int i=1;i<e_positon;i++)
		{
			if(string[i]>='0'&&string[i]<='9'||string[i]=='.')     
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		for(int i=e_positon+1;string[i]!='\0';i++)
		{
			if(e_positon==0)
			{
				if(string[i]=='.')
				{
					point_count++;
					if(point_count>1)
						return false;
				}
				else
				{
					if(string[i]>='0'&&string[i]<='9')
						;
					else
						return false;
				}
			}
			else
			{
				if((string[i]>='0'&&string[i]<='9')||string[i]=='-'||string[i]=='+')
				{
					continue;
				}
				else
					return false;
			}
		}
		return true;
	}
private:
	int Get_E_Position(char *string)
	{
		if(string==NULL)
		{
			return 0;
		}
		int pos = 0;
		int j = 0;
		for(int i=1;string[i]!='\0';i++)
		{
			if(string[i]=='e'||string[i]=='E')
			{
				pos = i;
				j++;
				if(j>1)          //表示有至少两个E 直接返回0
					return -1;
			}
		}
		return pos;
	}
};

/*
链接：https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2
来源：牛客网

class Solution {
public:
    bool isNumeric(char* string)
    {
        int len=strlen(string);
        int i=0,dot=0,nume=0,num=0;
        if(len==0)
            return true;
        if(string[0]=='+'||string[0]=='-')     //判断字符串的第一个字符的情况
            i++;
       while(i<len)
	   {
            if(string[i]>='0'&&string[i]<='9')
			{
                i++;
                num=1;
            }
            else 
				if(string[i]=='.')
				{
                	if(nume>0)
                    	return false;
                	dot++;
                	i++;
            	}
                else 
					if(string[i]=='e' ||string[i]=='E')
					{
                		if(nume>0 || num==0)       //nume>1表示不止有一个e   num==0 表示此时e是第一个字符  
                    		return false;
                		nume++;
                		i++;
                		if(string[i]=='-'||string[i]=='+')
                    		i++;
                		if(string[i]=='\0')     //此时表示+ -是最后的字符
                    		return false;
            		}
            		else
                		return false;               //表示当前字符是除了- + . e 数字 之外的其他字符
                   
        }
        if(dot>1 ||nume>1)
            return false;
        return true;
    }
};
*/


/*
网上参考答案：
https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2
*/

void main_demo48()
{
	Solution_demo48 s1;
	bool res = true;
	char *str_input  = "3.14e+15-9.+";
	res = s1.isNumeric(str_input);
	if(res==true)
	{
		cout<<"字符串表示数值"<<endl;
	}
	else
	{
		cout<<"字符串不表示数值"<<endl;
	}
	system("pause");
}