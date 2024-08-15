#pragma once
namespace zl {

	//�������������ʵ�ְ汾
	template<class iterator,class Ref,class Ptr>
	struct reverse_iterator
	{
		typedef reverse_iterator<iterator, Ref, Ptr> Self;
		reverse_iterator(iterator it)
			:_it(it)
		{}
		Ref operator*()
		{
			iterator prev(_it);
			return *(--prev);
		}
		Ptr operator->()
		{
			iterator prev = _it;
			return &(operator*());  //���������operator*()
		}
		Self& operator++()  //������������෴�������������++��ʵ�������������--����֮Ҳ����
		{
			--_it;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp = _it;
			--_it;
			return tmp;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp = _it;
			++_it;
			return tmp;
		}
		bool operator!=(const Self& s) const
		{
			return _it != s._it;
		}

		iterator _it;
	};

	template<class T>
	class List {
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, T&, T*> iterator;
	};

}