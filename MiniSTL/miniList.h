#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace {

	//List节点类
	template<class T>
	struct ListNode
	{
		
		ListNode(const T& value = T()) :
			_data(value), _next(nullptr), _prev(nullptr) {}
		
		
		T _data;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};


	//迭代器
	//Ref :reference 引用 Ptr :pointer
	template <class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		
	public:
		//构造函数
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
		//*解引用
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

	//list类
	template<class T>
	class List 
	{
		typedef ListNode<T> Node;			   //重命名为Node
	public:
		typedef ListIterator<T, T&, T*> iterator;//重命名iterator
		//typedef ListIterator<T> const_iterator;
		//构造函数 双向循环链表
	public:
		List()
		{
			CreateHead();
		}
		//拷贝构造
		List(const List<T>& l)
		{
			_head = new Node;
			_head->_prev = _head->_next = _head; //调用函数构造头节点
			for (auto val : l)
			{
				push_back(val);
			}
		}
		//拷贝构造
		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_prev = _head->_next = _head; //调用函数构造头节点
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//重载赋值=
		List<T>& operator=(List<T> l)
		{
			this->swap(l);
			return *this;
		}
		//析构函数
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

		//list 容量相关
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

		//list 元素访问
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
		// 在pos位置前插入值为val的节点
		void insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* prev = pos._node;

			newNode->_prev = prev->_prev;
			newNode->_next = prev;
			newNode->_prev->_next = newNode;
			prev->_prev = newNode;
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			assert(pos != end());		//防止头节点被删除

			Node* cur = pos._node;	   //pos位置

			Node* cur_prev = cur->_prev;//pos前驱
			Node* cur_next = cur->_next;//pos后驱

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

		void CreateHead()			//初始化头节点
		{
			_head = new Node;
			_head->_prev = _head->_next = _head;
		}
		Node* _head;

	};
}
