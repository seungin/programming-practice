#pragma once
#include <cassert>
#include <iostream>

class QuickSort
{
public:
	void operator()(int* nodes, int len)
	{
		if (len <= 1)
		{
			return;
		}

		int pivot = rand() % len;
		int last = 0;

		swap(nodes, 0, pivot);
		for (int i = 1; i < len; ++i)
		{
			if (nodes[0] > nodes[i])
			{
				swap(nodes, ++last, i);
			}
		}
		swap(nodes, 0, last);

		operator()(nodes, last);
		operator()(nodes + last + 1, len - last - 1);
	}

public:
	static void Test()
	{
		int numbers[] = { 9, 2, 4, 6, 7, 1, 5, 3, 8 };
		int len = sizeof(numbers) / sizeof(numbers[0]);

		std::cout << std::endl << __FUNCTION__ << std::endl;

		QuickSort sort;
		print(numbers, len);
		sort(numbers, len);
		print(numbers, len);
	}

private:
	static void print(int* nodes, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << " " << nodes[i];
		}

		std::cout << std::endl;
	}

	void swap(int* nodes, int a, int b)
	{
		assert(a >= 0);
		assert(b >= 0);

		int temp = nodes[a];
		nodes[a] = nodes[b];
		nodes[b] = temp;
	}
};