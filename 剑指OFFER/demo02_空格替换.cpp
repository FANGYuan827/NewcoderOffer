/*
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
2017��11��21��21:55:40
ϸ��û��ע�Ⱑ ��Ҫ�����ϰ 
replaceSpace()���Լ�д�Ĵ���,��Ҫ���⿪��һ���ڴ�����buffer,��ռ�õ���Դ��;
replaceSpace1()�����ϴ���д�Ĵ��룬����ԭ�����ַ��������ƶ�,����Ҫbuffer�ڴ� ռ����Դ��.....
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
		ptmp1--;      //�����ǲ��ǿո� ��Ҫ��ǰ��
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