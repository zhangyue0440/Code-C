////����AutoPtr�����⣬���Բ�������ScopedPtr ����ʵ�ֻ����Ƿ�����
////���巽���ǹ��캯���͸�ֵ=����ֻ�����������壬�������Ӳ��������Ҷ���Ϊ˽�л��߱�����
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
//	//����˴��������õĻ����޷�ͨ��ָ�����޸�����ָ��ռ������,*ֻ�ܷ�����������
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	//����->��Ϊ�˷����Զ�������
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