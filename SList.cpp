//#include<iostream>
//#include<assert.h>
//using namespace std;
//typedef int DataType;
//struct SListNode
//{
//	DataType _data;
//	SListNode* _next;
//
//	SListNode(DataType x)
//		:_data(x),
//		_next(NULL)
//	{}
//};
//
//class SList
//{
//	typedef SListNode Node;
//public:
//	SList()
//		:_head(NULL)
//		, _tail(NULL)
//	{}
//	~SList()
//	{
//		Node* cur = _head;
//		while (cur)
//		{
//			Node* del = cur;
//			cur = cur->_next;
//			delete del;
//		}
//
//	}
//
//	void PushBack(DataType x)
//	{
//		if (_head == NULL)
//		{
//			_head = _tail = new Node(x);
//		}
//		else
//		{
//			_tail->_next = new Node(x);
//			_tail = _tail->_next;
//		}
//	}
//
//	void Popback()
//	{
//		if (_head == NULL)
//		{
//			return;
//		}
//		else if (_head->_next == NULL)
//		{
//			delete _head;
//			_tail = _head = NULL;
//		}
//		else
//		{
//			Node* cur = _head;
//			while (cur->_next->_next)
//			{
//				cur = cur->_next;
//			}
//			delete _tail;
//			_tail = cur;
//			_tail->_next = NULL;
//
//		}
//	}
//
//	void PushFront(DataType x)
//	{
//		if (_head == NULL)
//		{
//			_head = _tail = new Node(x);
//		}
//		else
//		{
//			Node* cur = new Node(x);
//			cur->_next = _head;
//			_head = _tail = cur;
//		}
//	}
//
//	void PopFront()
//	{
//		if (_head == NULL)
//		{
//			return;
//		}
//		else if (_head->_next == NULL)
//		{
//			delete _head;
//			_tail = _head = NULL;
//		}
//		else
//		{
//			Node* cur = _head->_next;
//			delete _head;
//			_head = cur;
//		}
//	}
//
//	void Printf()
//	{
//		Node* cur = _head;
//		while (cur)
//		{
//			cout << cur->_data << "->";
//			cur = cur->_next;
//		}
//		if (_head == NULL)
//		{
//			printf("NULL");
//		}
//	}
//
//	SList(const SList& s)
//		:_head(NULL),
//		_tail(NULL)
//	{
//		Node* cur = s._head;
//		while (cur)
//		{
//			this->PushBack(cur->_data);
//			cur = cur->_next;
//		}
//	}
//
//	/*SList& operator =(const SList& s)
//	{
//	if (this != &s)
//	{
//	SList tmp(s);
//	Swap(tmp);
//	}
//	return *this;
//	}*/
//	SList& operator=(SList s)
//	{
//		Swap(s);
//		return *this;
//	}
//	//这里在进行插入的时候先插入到后面，然后用临时对象进行交换
//	void Insert(Node* pos, DataType x)
//	{
//		assert(pos);
//		if (pos == _head)
//		{
//			this->PushFront(x);
//		}
//		else
//		{
//			Node* tmp = new Node(x);
//			tmp->_next = pos->_next;
//			pos->_next = tmp;
//			swap(pos->_data, tmp->_data);
//		}
//
//	}
//	void Erase(Node* pos)
//	{
//		assert(pos);
//
//		if (pos == _head)
//		{
//			this->PopFront();
//		}
//		else if (pos == _tail)
//		{
//			this->Popback();
//		}
//		else
//		{
//			Node* del = pos->_next;
//			pos->_data = del->_data;
//			//删除倒数第二个节点
//			if (del->_next == NULL)
//			{
//				delete del;
//				pos->_next = NULL;
//				_tail = pos;
//			}
//			else
//			{
//				pos->_next = del->_next;
//				delete del;
//			}
//		}
//	}
//	Node* Find(DataType x)
//	{
//		if (_head->_data == x)
//		{
//			return _head;
//		}
//		
//		else if (_tail->_data== x)
//		{
//			return _tail;
//		}
//		else
//		{
//			Node* cur = _head->_next;
//			while (cur!=_tail)
//			{
//				if (cur->_data == x)
//				{
//					return cur;
//				}
//				cur = cur->_next;
//			}
//		}
//	}
//
//
//	void Swap(SList& s)
//	{
//		swap(_head, s._head);
//		swap(_tail, s._tail);
//	}
//private:
//	Node* _head;
//	Node* _tail;
//};
//
////测试尾插 尾删
//void test1()
//{
//	SList s1;
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.Printf();
//	cout << endl;
//	s1.Popback();
//	s1.Popback();
//	s1.Popback();
//	s1.Popback();
//	s1.Printf();
//}
//
////头插  头删
//void test2()
//{
//	SList s1;
//	s1.PushFront(3);
//	s1.PushFront(2);
//	s1.PushFront(1);
//	s1.PushFront(0);
//	s1.Printf();
//	cout << endl;
//	s1.PopFront();
//	s1.PopFront();
//	s1.PopFront();
//	s1.PopFront();
//	s1.PopFront();
//	s1.Printf();
//
//}
//
////链表复制
//void test3()
//{
//	SList s1;
//	s1.PushBack(1);
//	s1.PushBack(2);		
//	s1.PushBack(3);
//	s1.PushBack(4);
//	SList s2;
//	s2 = s1;
//	s1.Printf();
//	s2.Printf();
//}
//
////任意位置插入（头尾任意位置都要检测）
//void test4()
//{
//	SList s1;
//	s1.PushBack(1);
//	s1.PushBack(2);		
//	s1.PushBack(4);
//	s1.PushBack(6);
//	s1.Printf();
//	cout << endl;
//	SListNode* pos =s1. Find(1);
//	s1.Insert(pos,0);
//	SListNode* pos2 = s1.Find(4);
//	s1.Insert(pos2, 3);
//	SListNode* pos3 = s1.Find(6);
//	s1.Insert(pos3, 5);
//	s1.Printf();
//}
//
////任意位置删除
//void test5()
//{
//	SList s1;
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//	s1.PushBack(5);
//	SListNode* pos1 = s1.Find(1);
//	s1.Erase(pos1);
//	SListNode* pos2 = s1.Find(4);
//	s1.Erase(pos2);
//	//s1.Printf();
//	SListNode* pos3 = s1.Find(5);
//	s1.Erase(pos3);
//
//	s1.Printf();
//	
//
//}
//
//int main()
//{
//	//test1();
//	//test2(); 
//	//test3();
//	//test4();
//	test5();
//	getchar();
//	return 0;
//}
//
