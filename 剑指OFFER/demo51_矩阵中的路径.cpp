/*
2018年3月12日21:03:04
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/


#include "iostream"
using namespace std;

class Solution_demo51 {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)   //rows cols是这个矩阵的行数和列数
    {
		if(str==NULL||matrix==NULL||rows<1||cols<1)
		{
			return false;
		}
		bool *flag_matrix = new bool[rows*cols]();           //定义一个标志位来标记某个字符是否被访问过     
		for(int i=0;i<rows;i++)                                   //两层for循环嵌套的目的是找到第一个字符...... 
		{
			for(int j=0;j<cols;j++)
			{
				if(hasChar(matrix,rows,cols,str,flag_matrix,i,j))
					return true;
			}
		}
		return false;
    }
private:
	bool hasChar(char *matrix,int rows,int cols,char *str,bool *flag_matrix,int curx,int cury)
	{
		if(*str=='\0') 
			return true;
		if(cury==cols)      //当上一行到达最右边一列时 直接接到下一行
		{
			curx++;
			cury=0;
		}
		if(cury==-1)     //当前行到达最左边一列时  回到上一行的最右一列
		{
			curx--;
			cury=cols-1;
		}
		if(curx<0||curx>=rows)            //当前到达第一行的上一行||当前行到达最后一行的下一行 直接返回 因为超出了所给字符串的范围了
		{
			return false;
		}
		if(flag_matrix[curx*cols+cury]||*str!=matrix[curx*cols+cury])    //这个格子进过了||这个格子的字符不等于   flag_matrix[curx*cols+cury]=true;表示经过这个格子
			return false;
		flag_matrix[curx*cols+cury] = true;
		bool sign = hasChar(matrix,rows,cols,str+1,flag_matrix,curx-1,cury)||							//在当前格子的四周进行查找
			hasChar(matrix,rows,cols,str+1,flag_matrix,curx+1,cury)||
			hasChar(matrix,rows,cols,str+1,flag_matrix,curx,cury-1)||
			hasChar(matrix,rows,cols,str+1,flag_matrix,curx,cury+1);
		flag_matrix[curx*cols+cury] = false;
		return sign;
	}

};
/*
链接：https://www.nowcoder.com/questionTerminal/c61c6999eecb4b8f88a98f66b273a3cc
来源：牛客网

分析：回溯算法
 这是一个可以用回朔法解决的典型题。首先，在矩阵中任选一个格子作为路径的起点。如果路径上的第i个字符不是ch，那么这个格子不可能处在路径上的
第i个位置。如果路径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边界上的格子之外，其他格子都有4个相邻的格子。
重复这个过程直到路径上的所有字符都在矩阵中找到相应的位置。
　　由于回朔法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符的位置之后，在与第n个字符对应的格子的周围都没有找到第n+1个
字符，这个时候只要在路径上回到第n-1个字符，重新定位第n个字符。
　　由于路径不能重复进入矩阵的格子，还需要定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子。 
当矩阵中坐标为（row,col）的格子和路径字符串中相应的字符一样时，从4个相邻的格子(row,col-1),(row-1,col),(row,col+1)以及(row+1,col)中去定位路径字符串中下一个字符
如果4个相邻的格子都没有匹配字符串中下一个的字符，表明当前路径字符串中字符在矩阵中的定位不正确，我们需要回到前一个，然后重新定位。
　　一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到合适的位置......
*/

void main_demo51()
{
	Solution_demo51 s1;
	char *str_input = "abcesfcsadee";
	char *sub_str = "bcced";
	bool res = true;
	res  = s1.hasPath(str_input,3,4,sub_str);
	if(res==true)
	{
		cout<<"存在一条字符串的路径"<<endl;
	}
	else
	{
		cout<<"不存在一条字符串的路径"<<endl;
	}
	system("pause");
}

