/*
2018��3��27��19:31:21
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

#include "iostream"
#include <vector>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution_demo54 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if(pHead==NULL)
		{
			return NULL;
		}
		vector<RandomListNode*> m_vector;
		RandomListNode *pHead_tmp =(RandomListNode *)calloc(sizeof(RandomListNode),1);   //�����ڴ�
		pHead_tmp->label = pHead->label;
		pHead_tmp->next = NULL;
		m_vector.push_back(pHead_tmp);
		RandomListNode *tmp1 = pHead->next;
		RandomListNode *tmp2 = NULL;
		while(tmp1!=NULL)
		{
			RandomListNode *node =(RandomListNode *)calloc(sizeof(RandomListNode),1);   //�����ڴ� calloc()���������ڴ���г�ʼ��
			node->label = tmp1->label;
			m_vector.push_back(node);
			if(pHead_tmp->next==NULL)
			{
				pHead_tmp->next = node;
			}
			else
			{
				tmp2->next = node;
			}
			tmp1 = tmp1->next;
			tmp2 = node;
		}
		tmp1= pHead;
		RandomListNode *tmp3 = pHead_tmp;
		int count=0;
		while(tmp1!=NULL)
		{
			tmp2 = pHead;
			while(tmp1->random!=tmp2)
			{
				tmp2 = tmp2->next;
				++count;
			}
			if(tmp1->random!=NULL)           //����ж������Ҫ���ж�random�ڵ�Ϊ�յ�ʱ��
			{
				tmp3->random = m_vector[count];
			}
			tmp3 = tmp3->next;
			tmp1 = tmp1->next;
			count=0;
		}
		return pHead_tmp;
    }
};


void main_demo54()
{
	Solution_demo54 s1;
	RandomListNode r1(1),r2(2),r3(3),r4(4);
	r1.next = &r2;
	r1.random = &r3;
	r2.next = &r3;
	r2.random = &r4;
	r3.next = &r4;
	r3.random = &r1;
	r4.next = NULL;
	r4.random = &r1;
	RandomListNode *res = NULL;
	res= s1.Clone(&r1);
    while(res!=NULL)
	{
		cout<<res->label<<"---"<<(res->random)->label<<endl;
		res = res->next;
	}
	system("pause");
}

