#include <cstring>
#include <iostream>

class SequentialSearch
{
private:
	struct Node
	{
		char* name;
		int value;
	};

public:
	int operator()(Node target, Node* nodes)
	{
		for (int i = 0; nodes[i].name != NULL; ++i)
		{
			if (strcmp(target.name, nodes[i].name) == 0)
			{
				return i;
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
			{ NULL, 0 }
		};

		int index;
		SequentialSearch lookup;

		std::cout << std::endl << __FUNCTION__ << std::endl;

		{
			Node target;
			target.name = "apple";
			index = lookup(target, tokens);
			std::cout << target.name << " -> " << index << std::endl;
		}

		{
			Node target;
			target.name = "zebra";
			index = lookup(target, tokens);
			std::cout << target.name << " -> " << index << std::endl;
		}
	}
};