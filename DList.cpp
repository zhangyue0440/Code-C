#include<iostream>
#include<assert.h>
using namespace std;
typedef  int DataType ;
struct DListNode
{
	DListNode *_next;
	DListNode* _pre;
	DataType _data;

	DListNode(DataType x)
		:_data(x),
		_next(NULL),
		_pre(NULL)
	{}
};

class DList
{
	typedef DListNode Node;
public:
	DList()
		:_head(NULL),
		_tail(NULL)
	{}
	
	~DList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}

	void PushBack(DataType x)
	{
		if (_head == NULL)
		{
			_head = _tail = new Node(x);
		}
		else
		{
			Node* cur = new Node(x);
			_tail->_next = cur;
			cur->_pre = _tail;
			_tail = cur;
		}
	}
	void PopBack()
	{
		//考虑一个节点，多个节点
		if (_head == NULL)
		{
			return ;
		}
		else if (_head!=NULL&&_head->_next==NULL)
		{
			delete _head;
			_tail = _head = NULL;
		}
		else
		{
			Node* del = _tail;
			_tail = _tail->_pre;
			delete del;
			_tail->_next = NULL;
		}
	}

	void PushFront(DataType x)
	{
		if (_head == NULL)
		{
			_head = new Node(x);
			_tail = _head;
		}
		else
		{
			Node* cur = new Node(x);
			_head->_pre = cur;
			cur->_next = _head;
			_head = cur;
		}
	}
	void PopFront()
	{
		if (_head == NULL)
		{
			return;
		}
		else if (_head != NULL&&_head->_next == NULL)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			Node* del = _head;
			_head = _head->_next;
			delete del;
			_head->_pre = NULL;
		}
	}

	Node* Find(DataType x)
	{
		if (_head->_data == x)
		{
			return _head;
		}
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

	void Erase(Node* pos)
	{
		if (pos == _head)
		{
			this->PopFront();
		}
		else if (pos == _tail)
		{
			this->PopBack();
		}
		else
		{
			Node* p1 = pos->_pre;
			Node* p2 = pos->_next;
			p1->_next = p2;
			p2->_pre = p1;
			delete pos;
		}
	}
	void Insert(Node* pos,DataType x)
	{
		assert(pos);
		if (pos == _head)
		{
			this->PushFront(x);
		}
		else
		{
			Node* p1 = pos->_pre;
			Node* cur = new Node(x);
			cur->_next = pos;
			cur->_pre = pos->_pre;
			pos->_pre = cur;
			p1->_next = cur;
		}
	}

	DList(const DList& s)
		:_head(NULL),
		_tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	DList& operator=(const DList& s)
	{
		if (this != &s)
		{
			DList tmp(s);
			Swap(tmp);
		}
		return *this;
	}

	/*DList& operator=(DList s)
	{
		Swap(s);
		return *this;
	}*/

	void Swap(DList& s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
	}
     
	void ReverseDList()
	{
		//考虑他没有节点和一个节点
		assert(_head != NULL);
		if (_head&&_head->_next == NULL)
		{
			return;
		}
		Node* p1 = _head;
		Node* p2 = _tail;
		//考虑奇数个和偶数个的时候，基数的时候hui错开，偶数时候不会相等
		while (p1 != p2&&p1->_pre!=p2)
		{
			swap(p1->_data, p2->_data);
			p1 = p1->_next;
			p2 = p2->_pre;
		}
	}

	void Printf()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;

		if (_head == NULL)
		{
			printf("NULL");
		}
	}
private:
	Node* _head;
	Node* _tail;
};

//尾插 尾删
void test1()
{
	DList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.Printf();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.Printf();
}

//头插 头删
void test2()
{
	DList s1;
	s1.PushFront(3);
	s1.PushFront(2);
	s1.PushFront(1);
	s1.PushFront(0);
	s1.Printf();
	s1.PopFront();
	s1.PopFront();
	s1.PopFront();
	s1.PopFront();
	s1.PopFront();

	s1.Printf();

}

//赋值= 重载
void test3()
{
	DList s1;
	s1.PushBack(1);
	s1.PushBack(2);		
	s1.PushBack(3);
	s1.PushBack(4);
	DList s2;
	s2 = s1;
	s1.Printf();
	s2.Printf();
}

//任意位置删除
void test4()
{
	DList s1;
	s1.PushBack(1);
	s1.PushBack(2);		
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.Printf();
	DListNode* pos1 = s1.Find(1);
	s1.Erase(pos1);
	DListNode* pos2 = s1.Find(5);
	s1.Erase(pos2);
	DListNode* pos3 = s1.Find(3);
	s1.Erase(pos3);
	DListNode* pos4 = s1.Find(4);
	s1.Erase(pos4);
	DListNode* pos5 = s1.Find(2);
	s1.Erase(pos5);

	s1.Printf();
}

//任意位置插入
void test5()
{
	DList s1;
	s1.PushBack(1);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.Printf();
	DListNode* pos =s1. Find(1);
	s1.Insert(pos,0);
	DListNode* pos1 = s1.Find(3);
	s1.Insert(pos1, 2);
	DListNode* pos2 = s1.Find(5);
	s1.Insert(pos2, 6);
	s1.Printf();
}

void test6()
{
	DList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.ReverseDList();
	s1.Printf();
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);
	s1.Printf();
	s1.ReverseDList();
	s1.Printf();
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	getchar();
	return 0;
}

