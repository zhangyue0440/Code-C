//#include<iostream>
//#include<assert.h>
//#include<string>
//using namespace std;
//
//template<typename T>
//class Seqlist
//{
//public:
//	Seqlist()
//	:_a(NULL)
//	, _size(0)
//	, _capacity(0)
//	{}
//
//	Seqlist(const Seqlist& s)
//	{
//		_a = new T[sizeof(T)*s._size];
//		memcpy(_a, s._a, sizeof(T)*s._size);
//		_size = s._size;
//		_capacity = s._size;
//	}
//
//	Seqlist<T>& operator=(Seqlist<T> s)
//	{
//		swap(_a, s._a);
//		swap(_size, s._size);
//		swap(_capacity, s._capacity);
//
//		return *this;
//	}
//	
//
//	/*~Seqlist()
//	{
//		if (_a)
//		{
//			delete[] _a;
//			_capacity = 0;
//		}
//	}*/
//
//	void PushBack(const T&x)
//	{
//		CheckCapacity();
//		_a[_size] = x;
//		_size++;
//	}
//
//	void PopBack()
//	{
//		if (_size > 0)
//		{
//			_a[_size - 1] = '\0';
//			_size--;
//		}
//	}
//
//	void PushFront(const T& x)
//	{
//		CheckCapacity();
//		if (_size != 0)
//		{
//			for (int i = _size; i >= 0; i--)
//			{
//				_a[i] = _a[i - 1];
//			}
//		}
//		_a[0] = x;
//		_size++;
//	}
//
//	void PopFront()
//	{
//		if (_size > 0)
//		{
//			for (int i = 0; i < _size-1; i++)
//			{
//				_a[i] = _a[i + 1];
//			}
//			_size--;
//		}
//	}
//
//	int Find(T x)
//	{
//		for (int i = 0; i < (int)_size; i++)
//		{
//			if (_a[i] == x)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//
//	void Erase(int pos)
//	{
//		assert(pos <(int) _size);
//		for (size_t i = pos; i < _size - 1; i++)
//		{
//			_a[i] = _a[i + 1];
//		}
//		_size--;
//	}
//
//	void Insert(int pos,T x)
//	{
//		CheckCapacity();
//		for (int i = _size; i>pos; i--)
//		{
//			_a[i] = _a[i - 1];
//		}
//		_a[pos] = x;
//		_size++;
//	}
//
//	void CheckCapacity()
//	{
//		if (_size >= _capacity)
//		{
//			_capacity = _capacity * 2 + 3;
//			T* tmp = new T[_capacity];
//			if (_a)
//			{
//				//��ΪSstring�е����ݲ�����ֱ�Ӵ���char* ָ����ָ�������
//				//����С��16 ���ַ���ʱ��ֱ�Ӵ�������buffer����ʱ��Ϳ���ֱ����memcpy���п���
//				//��������16 ���ֽڵ�ʱ��Ż����char* ��ָ��������������
//				//��memcpy���п�����ʱ��ֻ��ǳ����,�ᷢ���ڴ�й©
//				//memcpy(tmp, _a,sizeof(T)* _size);
//				for (size_t i = 0; i < _size; i++)
//				{
//					tmp[i] = _a[i];
//				}
//				delete[]_a;
//			}
//
//			_a = tmp;
//		}
//	}
//
//	void Printf()
//	{
//		for (size_t i = 0; i < _size; ++i)
//	{
//		cout << _a[i] << " ";
//	}
//	cout << endl;
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
//
////���Թ��졣�������죬=����
//void test()
//{
//	Seqlist<string> s1;
//	s1.PushBack("aaaaaaaaaaaaaaaaaaa");
//	s1.PushBack("bb");
//	s1.PushBack("cc");
//	s1.PushBack("dd");
//	Seqlist<string>s2;
//	s2 = s1;
//	s2.Printf();
//	s1.Printf();
//
//}
//
////����β����ɾ��
//void test1()
//{
//	Seqlist<int> s1;
//	s1.PushBack(1);
//	s1.PushBack(1);
//	s1.PushBack(1);
//	s1.PushBack(1);
//	s1.Printf();
//	Seqlist<int>s2(s1);
//    Seqlist<int>s3;
//	s3 = s1;
//	s2.Printf();
//	s3.Printf();
//
//
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.Printf();
//}
//
////����ͷ�� ɾ
//void test2()
//{
//	Seqlist<int> s1;
//	s1.PushFront(1);
//	s1.PushFront(1);
//	s1.PushFront(1);
//	s1.PushFront(1);
//	s1.Printf();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.Printf();
//}
//
////���Բ��Ҳ��룬ɾ��
//void test3()
//{
//	Seqlist<int> s1;
//	s1.Insert(0, 1);
//	s1.Insert(0, 2);
//	s1.Insert(0, 3);
//	s1.Insert(0, 4);
//	s1.Printf();
//	cout<<s1.Find(1)<<endl;
//	cout << s1.Find(0) << endl;
//	s1.Erase(1);
//	s1.Erase(1);
//	s1.Erase(1);
//	s1.Erase(1);
//	s1.Erase(1);
//	s1.Printf();
//	
//}
//
//int main()
//{
//	test();
//	//test1();
//	//test2();
//	//test3();
//	getchar();
//	return 0;
//}