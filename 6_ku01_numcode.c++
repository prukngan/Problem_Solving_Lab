#include <bits/stdc++.h>
using namespace std;

void	decode(int *code, int size, int lv)
{
	cout << (code[0] > size ? 1 : 0) << '\n';
	if (lv > 1)
	{
		for (int j = 1; j < size; j++)
		{
			code[j] -= code[j - 1];
			if (code[j] > code[j - 1] + 1)
				code[j] -= code[j - 1];
			cout << (code[j] > code[j - 1] ? 1 : 0) << '\n';
		}
	}
	else
	{
		for (int j = 1; j < size; j++)
			cout << (code[j] > code[j - 1] ? 1 : 0) << '\n';
	}
}

// void	decode(int size, int lv)
// {
// 	int	n_pre, n_cur;

// 	cin >> n_pre;
// 	cout << (n_pre > size ? 1 : 0) << '\n';
// 	if (lv > 1)
// 	{
// 		for (int j = 1; j < size; j++)
// 		{
// 			cin >> n_cur;
// 			n_cur -= n_pre;
// 			if (n_cur > n_pre + 1)
// 				n_cur -= n_pre;
// 			cout << (n_cur > n_pre ? 1 : 0) << '\n';
// 			n_pre = n_cur;
// 		}
// 	}
// 	else
// 	{
// 		for (int j = 1; j < size; j++)
// 			cout << (n_cur > n_pre ? 1 : 0) << '\n';
// 	}
// }

int	main()
{
	int	size, lv;

	cin >> size >> lv;
	int	code[size];
	for (int i = 0; i < size; i++)
		cin >> code[i];
	decode(code, size, lv);
	return (0);
}