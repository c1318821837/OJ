// UVa1586.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include<string>
#include<stdio.h>
using namespace std;
const float C = 12.01;
const float H = 1.008;
const float O = 16.00;
const float N = 14.01;


int main()
{
	int k;
	cin >> k;
	while (k>0)
	{
		k--;
		char str[80];
		cin >> str;
		stack<char> y;
		stack<int> q;
		for (int i = 0; str[i] != NULL; i++)
		{

			if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			{
				if (str[i + 1] - '0' >= 0 && str[i + 1] - '0' <= 9)
				{
					q.push((str[i] - '0') * 10 + (str[i + 1] - '0'));
					i = i + 1;
				}
				else {
					q.push(str[i] - '0');
				}
			}
			 else if(str[i + 1] - '0' < 0 || str[i + 1] - '0'>9)
			{
				y.push(str[i]);
				q.push(1);
			}
			 else 
			{ y.push(str[i]); }		
		}
	   float 	sum = 0;
		while (!y.empty())
		{
			
			char m;
			m = y.top();
		//	cout << y.top() << endl;;
			y.pop();
			if (m == 'C')
			{
				sum = sum + C * q.top();
			//	cout << q.top() << endl;
				q.pop();
			}
			if (m == 'H')
			{
				sum = sum + H * q.top();
			//	cout << q.top() << endl;;
				q.pop();
			}
			if (m == 'O')
			{
				sum = sum +O * q.top();
			//	cout << q.top() << endl;;
				q.pop();
			}
			if (m == 'N')
			{
				sum = sum + N * q.top();
			//	cout << q.top() << endl;;
				q.pop();
			}

		}
		printf("%.3f", sum);
		cout << endl;
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
