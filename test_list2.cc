#include <iostream>
#include <string>

#include "list.h"

using namespace std;

List<string> moveit(List<string>);

int main()
{

	// Minimal code to use the list

	// You are recommended to start with your template implementation
	// and convert this code to instantiate it.
	// Move on to the iterator once it compiles.
	cout << "list0 testing iteration positions" << endl;
	cout << "list0 " << endl;
	List<string> list0;

	list0.insert("first");
	list0.insert("second");
	list0.insert("third");
	list0.insert("fourth");
	list0.insert("fifth");

	List<string>::Iterator iter0 = list0.begin();

	cout << "Should be \"first\". It is: " << *iter0 << endl;
	iter0++;
	cout << "Should be \"second\". It is: " << *iter0 << endl;
	++iter0;
	cout << "Should be \"third\". It is: " << *iter0 << endl;

	cout << "List<string> list00(moveit(list0)); " << endl;
	List<string> list00(moveit(list0));
	cout << endl;

	cout << "list00 = list0; " << endl;
	list00 = list0;
	cout << endl;

	cout << "list00 = moveit(list0);" << endl;
	list00 = moveit(list0);
	cout << endl;

	cout << "list1 " << endl;
	List<int> list1;

	cout << "list2(list1) " << endl;
	List<int> list2(list1);

	for (int i = 1; i <= 10; ++i)
	{
		list1.insert(i);
		list2.insert(i * 2);
	}

	List<int>::Iterator iter1 = list1.begin();
	auto iter2 = list2.begin();
	auto iter3 = list1.end();
	auto iter4 = list2.end();

	cout << endl << "for (auto it = list1.begin(); it != list1.end(); ++it)" << endl;

	for (auto it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl << "for (auto s : list2)" << endl;

	for (auto s : list2)
	{
		cout << s << endl;
	}

	cout << endl << "cout << list1 << endl;" << endl;

	cout << list1 << endl;

	cout << endl << "cout << list2 << endl;" << endl;

	cout << list2 << endl;
	// example of using the list with integers
		List<int> list;
		decltype(list)::value_type number;
		cout << "Enter numbers, finish by '-1' " << endl;
		while (cin >> number)
		{
			list.insert(number);
			if (number == -1)
				break;
		}

		for (decltype(list)::Iterator it{ list.begin() };
			it != list.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		for (auto i : list)
		{
			cout << i << " ";
		}
		cout << endl;

		cout << list << endl;
	cin.clear();

	// example of using the list with std::string
	// ( notice the overwhelming similarity to above code? )
		List<string> lists;
		decltype(lists)::value_type word;

		cout << "Enter words, finish by 'END' " << endl;
		while (cin >> word)
		{
			lists.insert(word);
			if (word == "END")
				break;
		}

		for (decltype(lists)::Iterator it{ lists.begin() };
			it != lists.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		for (auto w : lists)
		{
			cout << w << " ";
		}
		cout << endl;

		cout << lists << endl;

	return 0;
}

List<string> moveit(List<string> l)
{
	return l;
}