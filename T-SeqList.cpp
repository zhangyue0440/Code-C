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
//				//因为Sstring中的内容并不是直接存在char* 指针所指向的数组
//				//当它小于16 个字符的时候直接存在它的buffer里，这个时候就可以直接用memcpy进行拷贝
//				//当它大于16 个字节的时候才会存在char* 所指向的数组里，所以在
//				//用memcpy进行拷贝的时候只是浅拷贝,会发生内存泄漏
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
////测试构造。拷贝构造，=重载
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
////测试尾插入删除
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
////测试头插 删
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
////测试查找插入，删除
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