//#include<iostream>
//using namespace std;
////1.ΪʲôҪ������ָ���أ�
////��Ϊ�����ڶ��ڴ�����Ŀռ���Ҫ��������ϵͳ�ģ�����ᷢ���ڴ�й©��
////��ʱ���������Լ�����ȥ�ͷţ�����һЩʱ���ǳ���û��ִ�е��ͷŵĵط�������return�ˣ����������쳣������
////2.����ָ���ǹ���ָ����ָ�������ͷ����⣬�Լ�Ҫ��ԭ��ָ��һ��ȥ�������
////����* ��Ϊ�˹����������ͣ�����->��Ϊ�˹����Զ�������
//template<typename T>
//class AutoPtr
//{
//public:
//	AutoPtr( T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//���������=���ض��ǹ���Ȩת�ƣ����˵�ǰ�����������󶼲��ٹ���
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
////����*  ->������
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
////���Կ�������ֵ
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