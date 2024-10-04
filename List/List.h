#pragma once
#include <iostream>
class List
{
	struct Node
	{
		Node* next;
		int value;
		Node(int value, Node* next);
	};
private:
	Node* first = nullptr;
	//size_t size;


public:
	List(int n = 0) //: size(n)
	{
		while (n--)
			first = new Node(0, first);
	}
	~List()
	{
		Node* curr;
		while (first)
		{
			curr = first->next;
			delete first;
			first = curr;
		}
	}
	List(const List& other)
	{
		Node* curr1 = other.first;
		Node* curr2 = new Node(curr1->value, nullptr);
		first = curr2;
		while (!curr1->next)
		{
			curr2->next = new Node(curr1->next->value, nullptr);
			curr2 = curr2->next;
			curr1 = curr1->next;
		}
	}

	void print()
	{
		Node* curr = first;
		while (curr)
		{
			std::cout << curr->value; //переделать на ostream
			curr = curr->next;
		}
	}
	size_t size() const
	{
		Node* curr = first;
		size_t sz = 0;
		while (curr)
		{
			curr = curr->next;
			sz++;
		}
		return sz;
	}
	List(List&& other)
	{
		this->first = other.first;
		other.first = nullptr;
	}
	Node operator[](int i)
	{
		Node* curr = first;
		while (i--)
			curr = curr->next;
		return *curr;
	}
	Node* insert_after(int data, Node* prev)
	{
		Node* tmp = new Node(data, prev->next);
		prev->next = tmp;
		return tmp;
	}
	Node* insert_front(int data)
	{
		first = new Node(data, first);
		return first;
	}
	void erase_after(Node* prev)
	{
		Node* tmp = prev->next;
		if (tmp)
		{
			prev->next = prev->next->next;
			delete tmp;
		}
	}
	void erase_front()
	{
		Node* tmp = first->next;
		if (tmp)
		{
			first->next = first->next->next;
			delete tmp;
		}
	}

};