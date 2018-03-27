/*
2018��3��14��15:39:48
������һ��m�к�n�еķ���
һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*/
#include "iostream"
#include <vector>
using namespace std;

/*
����˼·�������㷨
������(0��0)��ʼ Ȼ����һ��bool���� ����ǵ�ǰ�����Ƿ����ڿ��Խ���ĸ��� 
���û����㷨���ӵ�ǰ���ӳ����������ǰ���ӿ��Ե��� �ٽ�һ���ж�������ӵ��������ҵ��ĸ������Ƿ��ܹ�����  ÿ�ж�һ�����ӿ��Ե��� ��ô�ͽ�bool������ӦԪ����λtrue.
��Ҫ�Ը����������Ч�Խ����ж� ���겻���� ֱ�ӷ��� false 
bool new ����֮���Ѿ��������˳�ʼ�� Ϊfalse;
Ȼ��ͳ��bool������Ԫ��ֵΪ true �ĸ�����Ϊ�������ܹ�����ĸ�����
*/

class Solution_demo52 {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *flag= new bool[rows*cols]();  
		int total = 0;
		Canreach(threshold,rows,cols,0,0,flag);    //�ӣ�0,0����ʼ
		for(int i=0;i<rows*cols;++i)
		{
			if(flag[i]==true)
				++total;
		}
		if(flag!=NULL)
		{
			free(flag);
			flag = NULL;
		}
		return total;
	}
private:
	vector<int> GetBit(int num)
	{
		vector<int>v_res;
		if(num<10&&num>=0)       //��λ��ֱ�ӷ��ؼ��� 
		{
			v_res.push_back(num);
			return v_res;
		}
		while(num>0)                //һ��ʼ��������ط�д���� д����while(n/10>0) ������ȡnum��ÿһλ��ʱ�� ��©�����λ
		{
			v_res.push_back(num%10);
			num/=10;
		}
		return v_res;
	}
	///////
	bool isOk(vector<int>&input1,vector<int>&input2,int threshold)
	{
		if(input1.size()<1||input2.size()<1||threshold<0)
		{
			return false;
		}
		int total = 0;
		vector<int>::iterator it;
		for(it=input1.begin();it!=input1.end();++it)
		{
			total+=*it;
		}
		for(it=input2.begin();it!=input2.end();++it)
		{
			total+=*it;
		}
		if(total>threshold)
			return true;
		return false;
	}
	//////
	bool Canreach(int threshold, int rows, int cols,int curx,int cury,bool *flag)
	{
		if(curx>=rows||curx<0||cury>=cols||cury<0)
		{
			return false;
		}
		vector<int>v_curx,v_cury;
		v_curx = GetBit(curx);
		v_cury = GetBit(cury);
		if(isOk(v_curx,v_cury,threshold)||flag[curx*cols+cury])
			return false;
		v_curx.clear();
		v_cury.clear();
		flag[curx*cols+cury] = true;
		bool sign =  Canreach(threshold,rows,cols,curx-1,cury,flag)||\
			Canreach(threshold,rows,cols,curx+1,cury,flag)||\
			Canreach(threshold,rows,cols,curx,cury-1,flag)||\
			Canreach(threshold,rows,cols,curx,cury+1,flag);
		return sign;
	}
};


void main_demo52()
{
	Solution_demo52 s1;
	int res = 0;
	res = s1.movingCount(15,20,20);
	cout<<"�û������ܹ�����ĸ���Ϊ��"<<res<<endl;
	system("pause");
}