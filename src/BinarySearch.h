#include <cstring>
#include <iostream>

class BinarySearch
{
private:
	struct Node
	{
		char* name;
		int value;
	};

public:
	int operator()(Node target, Node* nodes, int len)
	{
		int low = 0;
		int high = len - 1;
		int mid;
		int cmp;

		while (low <= high)
		{
			mid = (low + high) / 2;
			cmp = strcmp(target.name, nodes[mid].name);

			if (cmp < 0)
			{
				high = mid - 1;
			}
			else if (cmp > 0)
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}

		return -1;
	}

public:
	static void Test()
	{
		Node tokens[] = {
			{ "apple", 5 },
			{ "banana", 6 },
			{ "car", 3 },
			{ "deer", 4 },
			{ "elephant", 8 },
			{ "fish", 4 },
			{ "ground", 6 },
			{ "horse", 5 },
			{ "iphone", 6 },
		};

		int index;
		BinarySearch lookup;

		std::cout << std::endl << __FUNCTION__ << std::endl;

		{
			Node target;
			target.name = "apple";
			index = lookup(target, tokens, sizeof(tokens) / sizeof(tokens[0]));
			std::cout << target.name << " -> " << index << std::endl;
		}

		{
			Node target;
			target.name = "ground";
			index = lookup(target, tokens, sizeof(tokens) / sizeof(tokens[0]));
			std::cout << target.name << " -> " << index << std::endl;
		}

		{
			Node target;
			target.name = "zebra";
			index = lookup(target, tokens, sizeof(tokens) / sizeof(tokens[0]));
			std::cout << target.name << " -> " << index << std::endl;
		}
	}
};