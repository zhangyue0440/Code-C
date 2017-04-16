//#include<iostream>
//using namespace std;
////1.为什么要有智能指针呢？
////因为我我在堆内存申请的空间是要还给操作系统的，否则会发生内存泄漏，
////有时候是我们自己忘记去释放，还有一些时候是程序还没有执行到释放的地方就遇到return了，或者遇到异常返回了
////2.智能指针是管理指针所指向对象的释放问题，以及要像原生指针一样去管理对象，
////重载* 是为了管理内置类型，重载->是为了管理自定义类型
//template<typename T>
//class AutoPtr
//{
//public:
//	AutoPtr( T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//拷贝构造和=重载都是管理权转移，除了当前对象其他对象都不再管理
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(NULL)
//	{
//		_ptr = ap._ptr;
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this!=&ap)
//		{
//			delete _ptr;
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return  *_ptr;
//	}
//
//	T* operator ->()
//	{
//		return _ptr;
//	}
//
//	~AutoPtr()
//	{
//		cout << "delete _ptr";
//		delete _ptr;
//	}
//private:
//	T* _ptr;
//
//};
//
//struct AA
//{
//	int a;
//	int b;
//};
//
//void testAutoPtr()
//{
//	int* p = new int(10);
//	AutoPtr<int> ap1(p);
//	cout << *ap1 << endl;
//	//*ap1 = 20;
//	//cout << *ap1;
//}
//
////测试*  ->的重载
//void testAutoPtr1()
//{
//	AutoPtr<AA> ap2(new AA);
//	(*ap2).a = 10;
//	(*ap2).b= 10;
//	ap2->a = 20;
//	ap2->b = 20;
//
//}
//
////测试拷贝，赋值
//void testAutoPtr2()
//{
//	AutoPtr<int> ap1(new int(1));
//	AutoPtr<int> ap2(ap1);
//	cout << *ap2;
//	AutoPtr<int> ap3(new int(2));
//	ap3 = ap2;
//	cout <<  *ap3;
//
//
//}
//
//int main()
//{
//	//testAutoPtr();
//	//testAutoPtr1();
//	testAutoPtr2();
//	getchar();
//	return 0;
//}