////由于AutoPtr有问题，所以才引入了ScopedPtr 它的实现机制是防拷贝
////具体方法是构造函数和赋值=重载只声明，不定义，让他链接不到，并且定义为私有或者保护的
//
//#include<iostream>
//#include<string>
//using namespace std;
// 
//template<typename T>
//class ScopedPtr
//{
//public:
//	ScopedPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	
//
//	//如果此处不传引用的话就无法通过指针来修改他所指向空间的内容,*只能访问内置类型
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	//重载->是为了访问自定义类型
//	T* operator ->()
//	{
//		return _ptr;
//	}
//
//
//	~ScopedPtr()
//	{
//		cout << "delete";
//		delete _ptr;
//	}
//protected:
//	ScopedPtr(const ScopedPtr<T>& sp);
//	ScopedPtr<T>& operator=(ScopedPtr<T>& s);
//
//protected:
//	T* _ptr;
//
//};
//
//struct stu
//{
//	int a;
//	int b;
//};
//
//void test1()
//{
//	ScopedPtr<int> sp1(new int(1));
//	cout << *sp1 << endl;
//	*sp1 = 2;
//	cout << *sp1 << endl;
//}
//
//void test2()
//{
//	ScopedPtr<string> sp1(new string("aa"));
//	cout << *sp1 << endl;
//}
//
//void test3()
//{
//	ScopedPtr<stu> sp1(new stu);
//	(*sp1).a = 1;
//	(*sp1).b = 1;
//
//	sp1->a = 2;
//	sp1->b = 2;
//	cout << (*sp1).a <<endl ;
//	cout << (*sp1).b << endl;
//
//
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	getchar();
//	return 0;
//}