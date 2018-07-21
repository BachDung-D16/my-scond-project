#include<iostream>
#include<stdio.h>
#include<stack>
#include <fstream>
#include<conio.h>
using namespace std;
int Dem(char str[200], stack<char> a)
{
	int dem = 0;
	for (int i = 0; i< strlen(str); i++)
	{
		if (str[i] == '(')
			a.push(str[i]);
		else
		{
			if (!a.empty())
				a.pop();
			else
				dem++;
		}
	}
	while (!a.empty()) {
		a.pop();
		dem++;
	}
	return dem;
}

void KiemTra(char str[200], stack<char> a)
{

	int j = 0;
	//khong qua 200 dau ngoac
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] == '(')
		{
			a.push(str[i]);
		}
		else
		{
			if (!a.empty())
			{
				a.pop();
			}
			else
			{
				ofstream ghi;
				ghi.open("output.txt");
				ghi << "( " << j << endl;
				j--;
				ghi.close();
			}
			
		}
	}

	int vt = strlen(str);
	while (!a.empty()) {
		ofstream ghi;
		ghi.open("output.txt");
		ghi << ") " << vt << endl;
		vt++;
		a.pop();
		ghi.close();
	}
	
}
int main()
{
	char str[200];
	stack<char> a;
	ifstream doc;
	doc.open("input.txt");
	gets_s(str, 200);
	doc.close();
	ofstream ghi;
	ghi.open("output.txt");
	ghi << Dem(str, a) << endl;
	if (Dem(str, a) != 0)
		KiemTra(str, a);
	return 0;
	ghi.close();
	_getch();
}