#include "iostream"
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        int length = str.size();
       
        int cnt = factorial(length);
        vector<string>res(cnt);
		 if(length == 0)
        {
            return res;
        }
        int num = 1;
        //char *i,*ii,*j;
		string::iterator i,ii,j;
        while(++num<=cnt)
        {
			i = str.begin()+length -2;
			ii = str.begin()+length -1;
			j = ii;
			while(*i>=*j)
				i--,ii--;
			while(*i >= *j)
				j--;
			swap(*i,*j);
			//reverse(ii);
			cout<< str << " ";

        }
        
    }
    int  factorial(int n)     //全排列组合数为 n!
    {
        if(n == 1)
            return 1;
        return n*factorial(n-1);
    }
    void reverse(string str)
    {
		int len =str.size();
        int i = 0;
        for(i=0;i<len/2;i++)
        {
            swap(str.at(i),str.at(len-1-i));
        }
    }
};


//clang下 编译未通过 
void main_demo22()
{
	string str = "abc";
	Solution s1;
	s1.Permutation(str);


	system("pause");
}