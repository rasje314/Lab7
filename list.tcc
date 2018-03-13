#include <iostream>
#include <string>
#include "list.h"

template<class T>
void List<T>::insert(T const & d)
{
	//first = new Link(d, first);
	Link* il = new Link(d, nullptr);
	if (!first)
	{
		first = il;
	}
	else
	{
		Link* crawler = first;
		while (crawler->next)
		{
			crawler = crawler->next;
		}
		crawler->next = il;
	}
}

template<class T>
List<T>::List(List const & l)
{
	std::clog << "***Copy construction" << std::endl;
	first = Link::clone(l.first);
}

template<class T>
List<T>::List(List && l)
{
	std::clog << "***Move construction" << std::endl;
	first = l.first;
	l.first = nullptr;
}

template<class T>
List<T> & List<T>::operator=(List const & rhs)
{
	std::clog << "***Copy assignment" << std::endl;
	if (&rhs != this)
	{
		List copy(rhs);
		std::swap(first, copy.first);
	}
	return *this;
}

template<class T>
List<T> & List<T>::operator=(List && rhs)
{
	std::clog << "***Move assignment" << std::endl;
	if (&rhs != this)
	{
		std::swap(first, rhs.first);
	}
	return *this;
}

template<class T>
class List<T>::Iterator
{
	public:
		Iterator() noexcept :
			position(first) {
		}
		Iterator(const Link* l) noexcept :
			position(l) {}

		Iterator& operator=(Link* l)
		{
			this->position = l;
			return *this;
		}

		//prefix
		Iterator& operator++()
		{
			if (position)
				position = position->next;
			return *this;
		}

		//postfix
		Iterator operator++(int)
		{
			Iterator iter = *this;
			++*this;
			return iter;
		}

		bool operator!=(const Iterator& iterator)
		{
			return position != iterator.position;
		}

		T operator*()
		{
			return position->data;
		}

		friend class List;

	private:
		const Link* position;

};