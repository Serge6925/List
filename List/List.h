#pragma once
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
};