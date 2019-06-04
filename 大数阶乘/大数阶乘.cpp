// 大数阶乘.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int factorial(int n)
{
	int a[2001]; //确保保存最终运算结果的数组足够大
	int carry;//进位
	int digit = 1;//位数
	a[0] = 1;//将结果先初始化为1
	int temp;//阶乘的任一元素与临时结果的某位的乘积结果
	int i,j;
	for(i = 2; i <= n; ++i)//开始阶乘，阶乘元素从2开始依次“登场”
	{//按最基本的乘法运算思想来考虑，将临时结果的每位与阶乘元素相乘
		for(j = 1, carry = 0; j <= digit; ++j)
		{
			temp = a[j-1] * i + carry;//相应阶乘中的一项与当前所得临时结果的某位相乘（加上进位）
			a[j-1] = temp % 10;//更新临时结果的位上信息
			carry = temp / 10; //看是否有进位
		}
		while(carry)//如果有进位
		{
			a[++digit-1] = carry % 10;//新加一位，添加信息。位数增1
			carry /= 10;//看还能不能进位
		}
	}
	printf("结果是:\n%d ! = ",n);//显示结果
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
