#pragma once
#include <iostream>
#include <vector>

class iterator;
class List
{

private:
	struct Node
	{
		Node* next;
		int value;
		Node(int a) : value(a), next(nullptr) {}
	};
protected:
	Node* first = nullptr;


public:
	friend class iterator;
	List(int n = 0)
	{
		if (n < 0) throw std::exception();
		while (n--)
		{
			Node* curr = first;
			first = new Node(0);
			first->next = curr;
		}
	}
	~List()
	{
		Node* curr;
		while (first != nullptr)
		{
			curr = first;
			first = first->next;
			delete curr;
		}
	}
	List(const List& other)
	{
		Node* curr1 = other.first;
		Node* curr2 = new Node(curr1->value);
		first = curr2;
		while (!curr1->next)
		{
			curr2->next = new Node(curr1->next->value);
			curr2 = curr2->next;
			curr1 = curr1->next;
		}
	}

	void print()
	{
		Node* curr = first;
		while (curr)
		{
			std::cout << curr->value << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}
	size_t size() const
	{
		Node* curr = first;
		size_t sz = 0;
		while (curr != nullptr)
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
		{
			curr = curr->next;
			if (curr == nullptr)
				throw std::exception();
		}
		return *curr;
	}
	Node* operator()(int i)
	{
		Node* curr = first;
		while (i--)
		{
			curr = curr->next;
			if (curr == nullptr)
				throw std::exception();
		}
		return curr;
	}
	void insert_after(int data, Node* prev)
	{
		Node* tmp = new Node(data);
		tmp->next = prev->next;
		prev->next = tmp;
	}
	void insert_front(int data)
	{
		Node* curr = first;
		first = new Node(data);
		first->next = curr;
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
		Node* tmp = first;
		if (tmp)
		{
			first = first->next;
			delete tmp;
		}
	}
	int* find_mid() //task 4: finding the middle of the list
	{
		Node* curr1 = first;
		Node* curr2 = first;
		int A[2];
		while ((curr2->next != nullptr) && (curr2->next->next != nullptr))
		{
			curr1 = curr1->next;
			curr2 = curr2->next->next;
		}
		if (curr2->next != nullptr)
		{
			A[0] = (curr1->value);
			A[1] = (curr1->next->value);
		}
		else
			A[0] = (curr1->value);
		return A;
	}
};
class iterator
{
protected:
	List::Node* it;
public:
	iterator(List::Node* l)
	{
		it = l;
	}
	friend iterator operator ++ (iterator& a)
	{
		a.it = a.it->next;
		return a;
	}
	iterator operator ++ (int)
	{
		iterator b(*this);
		it = it->next;
		return b;
	}
	iterator operator + (int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (it == nullptr)
				throw std::exception();
			it++;
		}
		return *this;
	}
	List::Node* GetNode()
	{
		return it;
	}
	int GetValue()
	{
		return it->value;
	}
	iterator& operator += (int a)
	{
		*this = *this + a;
		return *this;
	}
	friend std::ostream& operator << (std::ostream& ostr, const iterator& a) //Вывод
	{
		ostr << a.it->value;
		return ostr;
	}
	bool operator < (const iterator& a)
	{
		iterator nwit(*this);
		while ((nwit != a) && (nwit.it->next != nullptr))
			nwit.it = nwit.it->next;
		if (nwit == a)
			return 1;
		else
		{
			iterator nwit2(a);
			while (nwit2.it->next != nullptr)
				nwit2.it = nwit2.it->next;
			if (nwit2 != nwit)
				throw std::exception();
			else
				return 0;
		}

	}
	bool operator > (const iterator& a)
	{
		iterator nwit(a);
		while ((nwit != *this) && (nwit.it->next != nullptr))
			nwit.it = nwit.it->next;
		if (nwit == a)
			return 1;
		else
		{
			iterator nwit2(*this);
			while (nwit2.it->next != nullptr)
				nwit2.it = nwit2.it->next;
			if (nwit2 != nwit)
				throw std::exception();
			else
				return 0;
		}
	}
	bool operator == (const iterator& a)
	{
		return (this->it == a.it);
	}
	bool operator <= (const iterator& a)
	{
		return !(this->it > a.it);
	}
	bool operator >= (const iterator& a)
	{
		return !(this->it < a.it);
	}
	bool operator != (const iterator& a)
	{
		return !(*this == a);
	}
};