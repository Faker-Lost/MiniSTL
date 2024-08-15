#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace {

	//List�ڵ���
	template<class T>
	struct ListNode
	{
		
		ListNode(const T& value = T()) :
			_data(value), _next(nullptr), _prev(nullptr) {}
		
		
		T _data;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};


	//������
	//Ref :reference ���� Ptr :pointer
	template <class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		
	public:
		//���캯��
		ListIterator(Node* node = nullptr) :_node(node) {}
		//++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		//--it
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//it--
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		//!= ==
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
		//*������
		Ref operator*()
		{
			return _node->_data;
		}
		const Ref operator*() const
		{
			return _node->_data;
		}

		//->
		Ptr operator->()
		{
			return &(_node->_data);
		}
		const Ptr operator->() const
		{
			return &(_node->_data);
		}
		Node* _node;
	};

	//list��
	template<class T>
	class List 
	{
		typedef ListNode<T> Node;			   //������ΪNode
	public:
		typedef ListIterator<T, T&, T*> iterator;//������iterator
		//typedef ListIterator<T> const_iterator;
		//���캯�� ˫��ѭ������
	public:
		List()
		{
			CreateHead();
		}
		//��������
		List(const List<T>& l)
		{
			_head = new Node;
			_head->_prev = _head->_next = _head; //���ú�������ͷ�ڵ�
			for (auto val : l)
			{
				push_back(val);
			}
		}
		//��������
		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_prev = _head->_next = _head; //���ú�������ͷ�ڵ�
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//���ظ�ֵ=
		List<T>& operator=(List<T> l)
		{
			this->swap(l);
			return *this;
		}
		//��������
		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//list Iterator
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		/*const iterator begin()
		{
			return _head->_next;
		}
		const iterator end()
		{
			return _head;
		}*/

		//list �������
		size_t size() const
		{
			size_t count = 0;
			iterator it = begin();
			while (it != end())
			{
				count++;
				++it;
			}
			return count;
		}
		bool empty()const
		{
			return _head == _head->_next;
		}

		//list Ԫ�ط���
		T& front()
		{
			return _head->_next->_data;
		}
		const T& front() const
		{
			return _head->_next->_data;
		}
		T& back()
		{
			return _head->_prev->_data;
		}
		const T& back() const
		{
			return _head->_prev->_data;
		}

		//list modify
		void push_back(const T& val) {

			insert(end(), val);
		}
		void pop_back() {
			erase(--end());
		}
		void push_front(const T& val) {
			insert(begin(), val);
		}
		void pop_front() {
			erase(begin());
		}
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		void insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* prev = pos._node;

			newNode->_prev = prev->_prev;
			newNode->_next = prev;
			newNode->_prev->_next = newNode;
			prev->_prev = newNode;
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			assert(pos != end());		//��ֹͷ�ڵ㱻ɾ��

			Node* cur = pos._node;	   //posλ��

			Node* cur_prev = cur->_prev;//posǰ��
			Node* cur_next = cur->_next;//pos����

			delete cur;

			cur_prev->_next = cur_next;
			cur_next->_prev = cur_prev;

			return cur_next;

		}
		void clear()
		{
			iterator cur = begin();
			while (cur != end())
			{
				erase(cur++);
			}
		}
		void swap(List<T>& l)
		{
			swap(_head, l._head);

		}

	private:

		void CreateHead()			//��ʼ��ͷ�ڵ�
		{
			_head = new Node;
			_head->_prev = _head->_next = _head;
		}
		Node* _head;

	};
}
