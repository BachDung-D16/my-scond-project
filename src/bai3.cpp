#include<iostream>
#include<conio.h>
#include<fstream>
int a[101][101];
int trace[101];
int n, m, dau, cuoi;
using namespace std;
void DFS(int u)
{
	for (int v = 1; v <= cuoi; v++)
	{
		if (a[u][v] == 1 && trace[v] == 0)
		{
			trace[v] = u;
			DFS(v);
		}
	}
}
int main()
{
	ifstream FileIn;
	int x, y;
	int i = 1, b[100], dem = 0;
	FileIn.open("INPUT.TXT");
	if (!FileIn)
	{
		cout << "Khong ton tai file";
	}
	FileIn >> n;
	cout << "So tuyen pho co the di duoc:" << n << endl;
	FileIn >> m;
	cout << "So tuyen duong co the di duoc:" << m << endl;
	FileIn >> dau;
	cout << "So hieu PTIT:" << dau << endl;
	FileIn >> cuoi;
	cout << "So hieu sbox:" << cuoi << endl;
	FileIn.close();
	ofstream FileOut;
	FileOut.open("output.txt");
	if (!FileOut)
	{
		cout << "Khong ton tai file";
	}
	for (int i = 1; i <= m; i++)
	{
		FileIn >> x >> y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	DFS(dau);
	if (trace[cuoi] == 0)
	{
		FileOut << "Khong co duong di";
	}
	else
	{
		while (cuoi != dau)
		{
			b[i] = cuoi;
			cuoi = trace[cuoi];
			i++;
			dem++;
		}
	}
	FileOut << dau << "\t";
	for (int i = dem; i>0; i--)
	{
		FileOut << b[i] << "\t";
	}
	FileOut.close();
	_getch();
	return 0;
}

