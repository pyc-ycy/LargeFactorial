// �����׳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int factorial(int n)
{
	int a[2001]; //ȷ�����������������������㹻��
	int carry;//��λ
	int digit = 1;//λ��
	a[0] = 1;//������ȳ�ʼ��Ϊ1
	int temp;//�׳˵���һԪ������ʱ�����ĳλ�ĳ˻����
	int i,j;
	for(i = 2; i <= n; ++i)//��ʼ�׳ˣ��׳�Ԫ�ش�2��ʼ���Ρ��ǳ���
	{//��������ĳ˷�����˼�������ǣ�����ʱ�����ÿλ��׳�Ԫ�����
		for(j = 1, carry = 0; j <= digit; ++j)
		{
			temp = a[j-1] * i + carry;//��Ӧ�׳��е�һ���뵱ǰ������ʱ�����ĳλ��ˣ����Ͻ�λ��
			a[j-1] = temp % 10;//������ʱ�����λ����Ϣ
			carry = temp / 10; //���Ƿ��н�λ
		}
		while(carry)//����н�λ
		{
			a[++digit-1] = carry % 10;//�¼�һλ�������Ϣ��λ����1
			carry /= 10;//�����ܲ��ܽ�λ
		}
	}
	printf("�����:\n%d ! = ",n);//��ʾ���
	for(i = digit; i >=1; --i)
	{
		printf("%d",a[i-1]);
	}
	return 0;
}
void main()
{
	long double A[20000];
	long int n;
	cin >> n;
	int a, b = 1, i, j;
	int t;
	A[0] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 1, a = 0; j <= b; j++)
		{
			t = A[j - 1] * i + a;
			A[j - 1] = t % 10;
			a = t / 10;
		}
		while (a)
		{
			b++;
			A[b - 1] = a % 10;
			a /= 10;
		}
	}
	for (i = b; i >= 1; i--)
		cout << A[i - 1];
	cout << endl;
}
