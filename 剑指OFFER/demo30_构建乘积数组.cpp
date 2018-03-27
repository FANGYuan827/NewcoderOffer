/*
2018年1月22日21:30:42
给定一个数组A[0,1,...,n-1],
请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。

*/

#include "iostream"
#include <vector>
using namespace std;

class Solution {
public:
	//算法复杂度 O(n^2)
    vector<int> multiply(const vector<int>& A) {
		vector<int>v_res;
		int len = A.size();
		int POW = 1;
		//int i = 0;
		if(len == 0)
		{
			return v_res;
		}
		for(int i = 0;i<len;i++)
		{
			for(int j = 0;j<len;j++)
			{
				if(j==i)
				{
					continue;
				}
				else
				{
					POW*=A[j];
				}
			}
			v_res.push_back(POW);
			POW = 1;
		}
		return v_res;
    }

	//优化算法  算法复杂度:O(n) 这种算法根本就想不到    .......
	vector<int> multiply2(const vector<int>& A) {
		vector<int> vec;
		int sz=A.size();
		if(sz==0)
			return vec;
		vec.push_back(1);
		for(int i=0;i<sz-1;i++)
			vec.push_back(vec.back()*A[i]);
		int tmp=1;
		for(int i=sz-1;i>=0;i--)
		{
			vec[i]=vec[i]*tmp;
			tmp=tmp*A[i];
		}
		return vec;
	}
};

void main_demo30()
{
	Solution s1;
	vector<int> Input;
	vector<int> Output;
	for(int i  = 0;i<5;i++)
	{
		Input.push_back(i+1);
	}
	Output = s1.multiply2(Input);
	for(int i=0;i<Output.size();i++)
	{
		printf("%d  ",Output[i]);
	}

	/*
	int myArray[10][10] ;
	for(int i=0;i<10;i++)
		memset(myArray[i],0,sizeof(myArray[i]));
	for(int i =0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			printf("%d  ",myArray[i][j]);
		printf("\n");
	}
	*/


	printf("\n");
	system("pause");
}

/*
memset()函数小测试的代码：
int myArray[10][10] ;
	for(int i=0;i<10;i++)
		memset(myArray[i],0,sizeof(myArray[i]));
	for(int i =0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			printf("%d  ",myArray[i][j]);
		printf("\n");
	}
*/


/*
大神的解题方法：
链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46
来源：牛客网

<分析>：
解释下代码，设有数组大小为5。
对于第一个for循环
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4]; 
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2]; 
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1]; 
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。
class Solution {
public:
  vector<int> multiply(const vector<int>& A) {
  vector<int> vec;
  int sz=A.size();
  if(sz==0)
   return vec;
  vec.push_back(1);
  for(int i=0;i<sz-1;i++)
   vec.push_back(vec.back()*A[i]);
  int tmp=1;
  for(int i=sz-1;i>=0;i--)
  {
   vec[i]=vec[i]*tmp;
   tmp=tmp*A[i];
  }
  return vec;
    }
};
*/


/*
链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46
来源：牛客网

剑指的思路：
B[i]的值可以看作下图的矩阵中每行的乘积。
下三角用连乘可以很容求得，上三角，从下向上也是连乘。
因此我们的思路就很清晰了，先算下三角中的连乘，即我们先算出B[i]中的一部分，然后倒过来按上三角中的分布规律，把另一部分也乘进去。
public class Solution {
    public int[] multiply(int[] A) {
        int length = A.length;
        int[] B = new int[length];
        if(length != 0 ){
            B[0] = 1;
            //计算下三角连乘
            for(int i = 1; i < length; i++){
                B[i] = B[i-1] * A[i-1];
            }
            int temp = 1;
            //计算上三角
            for(int j = length-2; j >= 0; j--){
                temp *= A[j+1];
                B[j] *= temp;
            }
        }
        return B;
    }
}

*/