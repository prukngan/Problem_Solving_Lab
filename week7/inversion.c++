#include <bits/stdc++.h>
using namespace std;

long long	inversion = 0;
vector<int>	arr;

template<template<typename...> class arr, typename type, typename myIterator>
void	ft_memcpy(arr<type> &dest, myIterator src, size_t size)
{
	for (int i = 0; i < size; i++)
		dest[i] = *(src++);
}

void	merge(int low, int mid, int high)
{
	int	leftLen = mid - low + 1;
	int	rightLen = high - mid;

	vector<int>	left(leftLen);
	vector<int>	right(rightLen);

	ft_memcpy(left, arr.begin() + low, leftLen);
	ft_memcpy(right, arr.begin() + mid + 1, rightLen);

	int	i = 0, j = 0, k = low;
	while (i < leftLen && j < rightLen)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
		{
			arr[k++] = right[j++];
			inversion += (leftLen - i);
		}
	}
	while (i < leftLen)
		arr[k++] = left[i++];
	while (j < rightLen)
		arr[k++] = right[j++];
}

void	split(int low, int high)
{
	if (low >= high)
		return ;
	int mid = (low + high) / 2;
	split(low, mid);
	split(mid + 1, high);
	merge(low, mid, high);
}

void	countInversion(int size) {
	split(0, size - 1);
}

int	main()
{
	int	n, number;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		arr.push_back(number);
	}
	countInversion(n);
	cout << inversion << '\n';
	return (0);
}