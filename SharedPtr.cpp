//前面的ScopedPtr虽然解决了autoptr的管理权转移问题，但是解决方法过于粗暴，
//有时候我们还是需要用到拷贝构造和赋值=重载的，所以又有了sharedptr，他的解决办法是加入引用计数
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T >
class Delete
{
public:
	void operator()(T* ptr)
	{
		delete ptr;
	}
};

template<typename T >
class DeleteArr
{
public:
	void operator()(T* ptr)
	{
		delete []ptr;
	}
};

template<typename T>
class Free
{
public:
	void operator()(T* ptr)
	{
		free(ptr);
	}
};

template<typename T>
class Fclose
{
public:
	void operator()(T* ptr)
	{
		fclose(ptr);
	}
};


template<typename T,typename Del=Delete<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _count(new int(1))
	{}

	SharedPtr(const SharedPtr<T>& ap)
	{
		_ptr = ap._ptr;
		_count = ap._count;
		++GetCount();
	}

	SharedPtr<T>& operator=(SharedPtr<T>& ap)
	{
		//注意是否是自己给自己赋值，以及两个指向同一块空间的不同对象之间赋值
		//还要判断自己原来的空间_count--之后是否为0
		if (_ptr != ap._ptr)
		{
			Realse();
			_ptr = ap._ptr;
			_count = ap._count;
			++GetCount();
		}
		return *this;
	}

	~SharedPtr()
	{
		Realse();

	}

	void Realse()
	{
		--GetCount();
		if (GetCount() == 0)
		{
			cout << "delete" <<_ptr << endl;
			_del(_ptr);
			delete _count;
			_count = NULL;
			
		}
		
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	int& GetCount()
	{
		return *_count;
	}
private:
	T* _ptr;
	int* _count;
	Del _del;
};


//void test1()
//{
//	SharedPtr<int> ap1(new int(1));
//	SharedPtr<int> ap2(ap1);
//	SharedPtr<int> ap3(new int(2));
//
//	SharedPtr<int> ap4(new int[10]);
//
//	ap3 = ap1;
//	cout << ap1.GetCount() << endl;
//	cout << ap3.GetCount() << endl;
//
//}

void test2()
{
	SharedPtr<int> ap1(new int[10]);
	SharedPtr<string, DeleteArr<string>> ap2(new string[10]);
	SharedPtr<int, Free<int>> ap3((int*)malloc(sizeof(int)* 10));
	SharedPtr<FILE,Fclose<FILE>> ap4(fopen("a.txt", "w"));
}


int main()
{
	//test1();
	test2();
	getchar();
	return 0;
}