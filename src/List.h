#pragma once
#include <cassert>
#include <cstring>
#include <iostream>

class List
{
	struct Node
	{
		char* name;
		int value;
		Node* next;
	};

public:
	static Node* NewNode(char* name, int value)
	{
		Node* newNode = new Node;
		newNode->name = name;
		newNode->value = value;
		newNode->next = nullptr;
		return newNode;
	}

	static Node* AddFront(Node* list, Node* newNode)
	{
		newNode->next = list;
		return newNode;
	}

	static Node* AddEnd(Node* list, Node* newNode)
	{
		if (list == nullptr)
		{
			return newNode;
		}

		Node* current = list;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = newNode;
		return list;
	}

	static void Print(Node* list)
	{
		apply(list, printNode, "%s (%d)\n");
	}

	static int Size(Node* list)
	{
		int size = 0;
		apply(list, increaseCount, &size);
		return size;
	}

	static Node* DeleteAll(Node* list)
	{
		Node* next;

		while (list != nullptr)
		{
			next = list->next;
			delete list;
			list = next;
		}

		return list;
	}

	static Node* Delete(Node* list, char* name)
	{
		Node* prev = nullptr;

		for (Node* current = list; current != nullptr; current = current->next)
		{
			if (strcmp(current->name, name) == 0)
			{
				if (prev == nullptr)
				{
					list = current->next;
				}
				else if (current->next == nullptr)
				{
					prev->next = nullptr;
				}
				else
				{
					prev->next = current->next;
				}

				delete current;
				return list;
			}

			prev = current;
		}

		assert(false);
		return nullptr;
	}

public:
	static void Test()
	{
		std::cout << std::endl << __FUNCTION__ << std::endl;

		Node* list = nullptr;

		{
			list = AddFront(list, NewNode("apple", 5));
			list = AddFront(list, NewNode("banana", 6));
			list = AddFront(list, NewNode("car", 3));
			list = AddFront(list, NewNode("deer", 4));
			list = AddFront(list, NewNode("elephant", 8));
			Print(list);
			std::cout << "-> Size: " << Size(list) << std::endl;
		}

		{
			list = DeleteAll(list);
			Print(list);
			std::cout << "-> Size: " << Size(list) << std::endl;
		}

		{
			list = AddEnd(list, NewNode("apple", 5));
			list = AddEnd(list, NewNode("banana", 6));
			list = AddEnd(list, NewNode("car", 3));
			list = AddEnd(list, NewNode("deer", 4));
			list = AddEnd(list, NewNode("elephant", 8));
			Print(list);
			std::cout << "-> Size: " << Size(list) << std::endl;
		}

		{
			list = Delete(list, "apple");
			list = Delete(list, "elephant");
			list = Delete(list, "car");
			Print(list);
			std::cout << "-> Size: " << Size(list) << std::endl;
		}
	}

private:
	static void apply(Node* list, void (*fn)(Node*, void*), void* arg)
	{
		for (; list != nullptr; list = list->next)
		{
			(*fn)(list, arg);
		}
	}

	static void printNode(Node* node, void* arg)
	{
		char* fmt = static_cast<char*>(arg);
		printf(fmt, node->name, node->value);
	}

	static void increaseCount(Node* node, void* arg)
	{
		int* size = static_cast<int*>(arg);
		++(*size);
	}
};