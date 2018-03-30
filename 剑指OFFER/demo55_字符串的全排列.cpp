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
		Permutation_1(v_res,v_tmp,0,v_tmp.size()-1);
		sort(v_res.begin(),v_res.end());
		return v_res;
    }
private:
	void Permutation_1(vector<string> &v_res,vector<char> &v,int start,int end)
	{
		string s_tmp;
		if(start==end)
		{
			for(int i=0;i<=end;++i)     //将字符合并成字符串
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
					My_Swap(v[start],v[i]);
					Permutation_1(v_res,v,start+1,end);
					My_Swap(v[start],v[i]);
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
/*
利用栈来实现：
链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7
来源：牛客网
public class Solution {
    public ArrayList<String> Permutation(String str) 
	{
        TreeSet<String> tree = new TreeSet<>();
        Stack<String[]> stack = new Stack<>();
            ArrayList<String> results = new ArrayList<>();
            stack.push(new String[]{str,""});
            do{
                String[] popStrs = stack.pop();
                String oldStr = popStrs[1];
                String statckStr = popStrs[0];
                for(int i =statckStr.length()-1;i>=0;i--)
				{
                    String[] strs = new String[]{statckStr.substring(0,i)+statckStr.substring(i+1),oldStr+statckStr.substring(i,i+1)};
                    if(strs[0].length()==0){
                        tree.add(strs[1]);
                    }else{
                        stack.push(strs);
                    }
                }
             }
			while(!stack.isEmpty());
        for(String s : tree)
            results.add(s);
        return results;
    }
}
*/
void main_demo55()
{
	string str = "cba";
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