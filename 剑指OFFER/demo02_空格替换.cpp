/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
2017年11月21日21:55:40
细节没有注意啊 还要多加练习 
replaceSpace()是自己写的代码,需要另外开辟一块内存来做buffer,所占用的资源多;
replaceSpace1()是网上大神写的代码，是在原来的字符串上面移动,不需要buffer内存 占用资源少.....
*/
#include "iostream"
using namespace std;
void replaceSpace(char *str,int length) 
{
	char *tmp2 =str;
	int num = length;
	if(tmp2==NULL||length<=0)
	{
		cout<<"Error!"<<endl;
		return;
	}
	int i = 0;
	for(i=0;*(tmp2+i)!='\0';i++)
	{
		if(*(tmp2+i)==' ')
		{
			num+=2;
		}
	}
	char *tmp1 = (char *)malloc((num+1)*sizeof(char));
	char *t = NULL;
	t = tmp1;
	tmp2 = str;
	for(i=0;*(tmp2+i)!='\0';i++)
	{
		if(*(tmp2+i)==' ')
		{
			strcpy(tmp1,"%20");
			tmp1+=3;
		}
		else
		{
			*tmp1++ = *(tmp2+i);
		}
	}
	*tmp1 = '\0';
	strcpy(str,t);
	//printf("%s\n",t);
}

void replaceSpace2(char *str,int length)
{
	if(str == NULL)
	{
		printf("the parameter is error.....\n");
		return;
	}
	int lengthtmp = 0;
	int spacecount = 0;
	for(int i = 0;*(str+i)!='\0';i++)
	{
		lengthtmp++;
		if(*(str+i)==' ')
		{
			spacecount++;
		}
	}
	int len = lengthtmp+2*spacecount;
	if(len+1 > length)
	{
		printf("the memory overflow.....\n");
		return ;
	}
	char *ptmp1 = str+lengthtmp;
	char *ptmp2 = str+lengthtmp+2*spacecount;
	while(ptmp1<ptmp2)
	{

		if(*ptmp1==' ')
		{
			*ptmp2--='0';
			*ptmp2--='2';
			*ptmp2--='%';
		}
		else
			*ptmp2-- = *ptmp1;
		ptmp1--;      //不管是不是空格 都要往前移
	}
}

void main_demo02()
{
	char pin[100]= "hello world 123 ";
	int length = sizeof(pin);
	cout<<length<<endl;
	//replaceSpace(pin,length);
	replaceSpace2(pin,length);
	printf("%s\n",pin);

	system("pause");
}