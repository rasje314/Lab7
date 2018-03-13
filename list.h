#include <iostream>
#include <string>

#ifndef _LIST_H_
#define _LIST_H_

template<class T>
class List
{
public:
	List() : first(nullptr)
	{
		std::clog << "***Default construction" << std::endl;
	}
	~List() { delete first; }

	void insert(T const& d);

	List(List const&);
	List(List&&);
	List& operator=(List const&);
	List& operator=(List&&);

private:
	class Link
	{
	public:
		Link(T const& d, Link* n)
			: data(d), next(n) {}
		~Link() { delete next; }

		friend class List;

		static Link* clone(Link const* dolly)
		{
			if (dolly != nullptr)
				return new Link(dolly->data, clone(dolly->next));
			else
				return nullptr;
		}

		T data;
		Link* next;
	};

public:

	Link* first;
	using value_type = T;

	// Suitable place to add things...

	class Iterator;

	Iterator begin()
	{
		return Iterator(first);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
	
	friend std::ostream& operator<<(std::ostream& out, List& l)
	{
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			out << *it << std::endl;
		}
		return out;
	}
};

#include "list.tcc"

#endif