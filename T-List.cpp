#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template <class T>
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	T _data;

	ListNode(const T& x)
		:_next(NULL)
		, _prev(NULL)
		, _data(x)
	{}
};

template<class T>
class Linklist
{
	typedef ListNode<T> Node;
public:

	Linklist()
		:_head(NULL)
		, _tail(NULL)
	{}

	Linklist(const Linklist<T> &s)
		:_head(NULL)
		, _tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			this->Pushback(cur->_data);
			cur = cur->_next;
		}
	}

	

	//Linklist<T>& operator=( Linklist<T> &s)
	//{
	//	if (this != &s)
	//	{
	//		Linklist<T> tmp(s);
	//		Swap(tmp);
	//	}
	//	return *this;
	//}

	Linklist<T>& operator=(Linklist<T> s)
	{
		Swap(s);
		return *this;
	}

	~Linklist()
	{
		Clear();
	}

	void Clear()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}

		_tail = _head = NULL;
	}

	void Pushback(const T& x)
	{
		Node* cur = new Node(x);
		if (_head == NULL)
		{
			_tail=_head = cur;
		}
		else
		{
			_tail->_next = cur;
			cur->_prev = _tail;
			_tail = cur;
		}
	}

	void PopBack()
	{
		if (_head == NULL)
		{
			return;
		}

		if (_head&&_head->_next == NULL)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			//记得在将tail向前移的时候将他的next置为NULL，否则打印的时候会访问非法内存
			Node* del = _tail;
			_tail = _tail->_prev;
			_tail->_next = NULL;
			delete del;
		}
	}

	void PushFront(const T& x)
	{
		Node* cur = new Node(x);
		if (_head == NULL)
		{
			_head = cur;
			_tail = _head;
		}
		else
		{
			cur->_next = _head;
			_head->_prev = cur;
			_head = cur;
		}
	}

	void PopFront()
	{
		if (_head == NULL)
		{
			return;
		}

		else if (_head&&_head->_next == NULL)
		{
			delete _head;
			_head = _tail = NULL;
		}

		else
		{
			Node* del = _head;
			_head = _head->_next;
			delete del;
		}
	}

	Node* Find(const T& x)
	{
		Node* cur = _head;
		while (cur)
		{
			if (cur->_data == x)
			{
				return cur;
			}

			cur = cur->_next;
		}
		return NULL;
	}

	void Insert(Node* pos, T x)
	{
		if (pos == _head)
		{
			this->PushFront(x);
		}
		else
		{
			Node* cur = new Node(x);
			Node* pre = pos->_prev;
			cur->_next = pos;
			cur->_prev = pre;
			pre->_next = cur;
			pos->_prev = cur;

		}
	}

	void Erase(Node* pos)
	{
		if (_head == NULL)
		{
			return;
		}
		if(pos == _head)
		{
			this->PopFront();
		}
		if (pos == _tail)
		{
			this->PopBack();
		}
		else
		{
			Node* pre = pos->_prev;
			Node* next = pos->_next;
			pre->_next = next;
			next->_prev = pre;
			delete pos;
		}

	}

	void Reverse()
	{
		assert(_head!=NULL);
		if (_head&&_head->_next == NULL)
		{
			return;
		}
		Node* p1 = _head;
		Node* p2 = _tail;
		//考虑奇数和偶数情况不同
		while (p1 != p2&&p1->_prev != p2)
		{
			swap(p1->_data, p2->_data);
			p1 = p1->_next;
			p2 = p2->_prev;
		}
	}

	void Swap(Linklist<T>& s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
	}

	void Printf()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << "";
			cur = cur->_next;
		}
		cout << endl;
	}

private:
	Node* _head;
	Node* _tail;

};

//测试构造析构，拷贝
void test1()
{
	Linklist<string> s1;

	s1.Pushback("aa");
	s1.Pushback("bb");
	s1.Pushback("cc");
	s1.Pushback("dd");
	s1.Printf();

	Linklist<string> s2(s1);
	s2.Printf();
	Linklist<string> s3;
	s3 = s1;
	
}

void test2()
{
	Linklist<string> s1;
	s1.Pushback("aa");
	s1.Pushback("bb");
	s1.Pushback("cc");
	s1.Pushback("dd");
	s1.Printf();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.Printf();
	s1.PopBack();
	s1.PopBack();

}

void test3()
{
	Linklist<int> s1;
	s1.PushFront(1);
	s1.PushFront(1);
	s1.PushFront(1);
	s1.PushFront(1);
	s1.Printf();
	s1.PopFront();
	s1.PopFront();
	s1.PopFront();
	s1.Printf();
	s1.PopFront();
	s1.PopFront();

}


//测试查找，插入删除
void test4()
{
	Linklist<int> s1;
	s1.PushFront(6);
	s1.PushFront(4);
	s1.PushFront(3);
	s1.PushFront(1);
	s1.Printf();
	ListNode<int>*  pos1 = s1.Find(1);
	ListNode<int>*  pos2= s1.Find(3);
	ListNode<int>*  pos3= s1.Find(6);
	s1.Insert(pos1, 0);
	s1.Insert(pos2, 2);
	s1.Insert(pos3, 5);
	s1.Printf();
	s1.Erase(pos1);
	s1.Erase(pos2);
	s1.Erase(pos3);
	s1.Printf();

}

//测试反转链表   没有节点 一个  多个
void test5()
{
	Linklist<string> s1;
	s1.Reverse();
	s1.Pushback("aa");
	s1.Pushback("bb");
	s1.Pushback("cc");
	s1.Pushback("dd");
	s1.Printf();
	s1.Reverse();
	s1.Printf();

}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	getchar();
	return 0;
}