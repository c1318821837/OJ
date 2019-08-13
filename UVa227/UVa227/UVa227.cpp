// UVa227.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	char a[5][5];
	queue<char> q;
	int k = 5;
	int ai=0;
	int aj=0;
	char c;
	
	for (int i = 0; i < 5; i++)
	{
		
		int j = 0;
			while ((c = getchar()) != '\n')
			{
				a[i][j] = c;
				if (a[i][j] == ' ')
				{
					ai = i;
					aj = j;
				}
				j++;
			}
    }
	char b=NULL;
	while(b!='0')
	{
		cin >> b;
		q.push(b);
	}
	int lon = q.size();
	while (lon-1>0)
	{
		char change;
		char w=q.front();
		q.pop();
		if (w == 'A')
		{
			change = a[ai - 1][aj];
			a[ai - 1][aj] = ' ';
			a[ai][aj] = change;
			ai = ai - 1;
			aj = aj;

		}
		else if (w == 'B')
		{
			change = a[ai +1][aj];
			a[ai + 1][aj] = ' ';
			a[ai][aj] = change;
			ai = ai + 1;
			aj = aj;

		}
		else if (w == 'L')
		{
			change = a[ai ][aj-1];
			a[ai ][aj-1] = ' ';
			a[ai][aj] = change;
			ai = ai ;
			aj = aj-1;

		}
		else if (w == 'R')
		{
			change = a[ai ][aj+1];
			a[ai ][aj+1] = ' ';
			a[ai][aj] = change;
			ai = ai ;
			aj = aj+1;

		}
		else 
		{
			cout << "This puzzle has no final configuration." << endl;
		}
		lon--;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			cout <<a[i][j];
		}
		cout << endl;
	}
}

