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

