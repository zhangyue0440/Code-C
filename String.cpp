#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//
////class String
////{
////public:
////	String(char* str="" )
////	{
////		_str = new char[strlen(str) + 1];
////		strcpy(_str, str);
////	}
////	
////	/*String(const String& s)
////	{
////		_str = new char[strlen(s._str) + 1];
////		strcpy(_str, s._str);
////		
////	}
////
////	String& operator=(const String&s)
////	{
////		if (this != &s)
////		{
////			char* tmp = new char[strlen(s._str) + 1];
////			strcpy(tmp, s._str);
////			delete[] _str;
////			_str = tmp;
////		}
////		return *this;
////
////	}*/
////
////	
////	//简洁写法
////	//String(const String&s)
////		:_str(NULL)
////	{
////		String tmp(s._str);
////		std::swap(_str, tmp._str);
////	}
////	
////	String& operator=(String s)
////	{
////		std::swap(_str, s._str);
////		return *this;
////	}
////	/*String& operator=(const String& s)
////	{
////		if (this != &s)
////		{
////			String tmp(s._str);
////			std::swap(_str, tmp._str);
////		}
////		return *this;
////		
////	}*/
////
////
////
////	~String()
////	{
////		delete[] _str;
////	}
////
////	void Printf()
////	{
////		cout << this->_str<< endl;
////	}
////private:
////	char* _str;
////};
////
////int main()
////{
////	String s1("111");
////	String s2(s1);
////	s1 = s2;
////	s1.Printf();
////	s2.Printf();
////	String s3("qwe");
////	s3.Printf();
////	s1 = s3;
////	s1.Printf();
////	
////	getchar();
////	return 0;
////}
////
////
//
////写时拷贝
//
class String
{
public:
	String(char* str = "")
	{
		if (str == NULL)
		{
			_str = new char[1 + 4];
			*(int*)(_str) = 1;
			_str += 4;
			*_str = '\0';
		}
		else
		{
			_str = new char[strlen(str) + 5];
			*(int*)_str = 1;
			_str += 4;
			strcpy(_str, str);
		}
	}
	String(const String& s)
		:_str(s._str)
	{
		++GetRef();
	}
	String &operator=(const String & s)
	{
		if (_str != s._str)
		{
			--GetRef();
			ReduceRef();
		}
		else
		{
			_str = s._str;
		}
		return *this;
	}
	~String()
	{
		--GetRef();
		ReduceRef();

	}
	//[]的重载 为了实现写时拷贝的数组[]下标形式的访问
	char &operator[](size_t index)
	{
		if (GetRef() > 1)
		{
			--GetRef();
			char* tmp = new char(strlen(_str) + 1 + 4);
			*(int*)tmp = 1;
			tmp += 4;
			strcpy(tmp, _str);
			_str = tmp;
			
		}
		return _str[index];
	}

public:
	int& GetRef()
	{
		return *(int*)(_str-4);
	}
	void ReduceRef()
	{
		if (0 == --GetRef())
		{
			_str += 4;
			delete[]_str;
			_str = NULL;
		}
	}

	void Printf()
	{
		cout << this->_str << endl ;
	}

private:
	char* _str;
};


int main()
{
	String s1("hello");
	String s2(s1); 
	String s3(s2);
	s3 = s1;
	s3[0] = 'w';//提示不匹配,是因为[]没有重载
	s1.Printf();
	s3.Printf();
	getchar();
	return 0; 
}

