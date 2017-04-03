#include<iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 01, int day = 01)
		:_year(year),
		_month(month),
		_day(day)
	{
		assert(IsInvalid());
	}
	Date(const Date&d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		//cout << "Date(const Date&d)" << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			/*Date tmp(d);
			std::swap(*this, tmp);*/
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		//cout << "Date& operator=(const Date& d)" << endl;
		return *this;
	}

	void Dispaly()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	bool IsInvalid()
	{
		if (_year >= 1900
			&& _month > 0 && _month<13 &&
			_day>0 && _day <= GetMonthDays(_year, _month))
		{
			return true;
		}
		else
			return false;
	}


	int GetMonthDays(int year, int month)
	{
		int Month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month != 2)
		{
			return Month[month];
		}
		else
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				return 29;
			else
				return 28;
		}
	}

	// d1 + 100 d1.operator+(&d1, 100)
	// d1 + (-100)
	Date operator+(int day)
	{
		if (day<0)
		{
			return *this - (-day);
		}
		Date tmp(*this);
		tmp._day = tmp._day + day;
		while (tmp._day > GetMonthDays(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDays(tmp._year, tmp._month);
			
			if (tmp._month == 12)
			{
				tmp._year += 1;
				tmp._month = 1;
			}
			else
			{
				tmp._month += 1;
			}
		}
		return tmp;
	}


	// d1 += 100
	inline Date& operator += (int day)
	{
		*this = *this + day;
		return *this;
	}

	Date operator-(int day)
	{
		if (day < 0)
		{
			return *this + (-day);
		}
		Date tmp(*this);
		tmp._day -= day;

		while (tmp._day <= 0)
		{
			if (tmp._month == 1)
			{
				tmp._year -= 1;
				tmp._month = 12;
			}
			else
			{
				tmp._month -= 1;
			}
			tmp._day = GetMonthDays(tmp._year, tmp._month) + tmp._day;
		}
		return tmp;
	}
	inline Date& operator -=(int day)
	{
		*this = *this - day;
		return *this;
	}
	 Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
    Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		*this = *this - 1;
		return tmp;
	}

	bool operator > (const Date& d)
	{
		if (_year > d._year
			|| (_year == d._year&&_month > d._month)
			|| (_year == d._year&&_month == d._month&&_day > d._day))
		{
			return true;
		}
		else
			return false;
	}

	bool operator >= (const Date& d)
	{
		if ((*this == d) || (*this > d))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator < (const Date& d)
	{
		if (_year < d._year
			|| (_year == d._year&&_month < d._month)
			|| (_year == d._year&&_month == d._month&&_day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator <= (const Date& d)
	{
		if ((*this == d) ||( *this < d))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const Date& d)
	{
		if (!(*this==d))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator == (const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int operator-(const Date& d)
	{
		int count = 0;
		int flag = 0;
		Date max = *this;
		Date min = d;
		if (max < min)
		{
			flag = -1;
			Date d1;
			d1 = max;
			max = min;
			min = d1;
		}
		while(max != min)
		{
			min++;
			count++;
		}
		if (flag == -1)
		{
			count *= -1;
		}
		return count;
	}
private:
	int _year;
	int _month;
	int _day;
};

//测试构造，赋值运算符重载
void test1()
{
	Date d1;
	d1.Dispaly();
	Date d2(2017, 04, 01);
	d2.Dispaly();
	Date d3(d1);
	d3.Dispaly();
	d3 = d2;
	d3.Dispaly();
	//Date d4(1989, 01, 33);
}

//测试日期加天数
void test2()
{
	Date d1(2016,12,31);
	d1.Dispaly();
	Date d2 = d1 + 1;
	d2.Dispaly();
	Date d3 = d1 + 60;
	d3.Dispaly();
	Date d4 = d1 + 390;
	d4.Dispaly();
	Date d5 = d1 + (-5);
	d5.Dispaly();
	Date d6 = d1 + (-60);
	d6.Dispaly();
	Date d7 = d1 + (-390);
	d7.Dispaly();
	
	}

//测试日期减天数
void test3()
{
	Date d1(2017, 04, 03);
	d1.Dispaly();
	Date d2 = d1 -5;
	d2.Dispaly();
	Date d3 = d1 - 60;
	d3.Dispaly();
	Date d4 = d1 - 390;
	d4.Dispaly();
	Date d5 = d1 - (-5);
	d5.Dispaly();
	Date d6 = d1 - (-60);
	d6.Dispaly();
	Date d7 = d1 - (-390);
	d7.Dispaly();

}

//测试日期的++  --
void test4()
{
	Date d1(2017, 04, 03);
	Date d2=d1++;
	d2.Dispaly();
	++d1;
	d1.Dispaly();
	Date d3(2017, 04, 03);
	Date d4=d2--;
	d4.Dispaly();
	--d2;
	d2.Dispaly();

}
//测试日期的+=   -=
void test5()
{
	Date d1(2017, 04, 03);
	Date  d2(d1+=60);
	d2.Dispaly();
	Date d3(d1 += 390);
	d3.Dispaly();

	Date  d5(d1 -= 390);
	d5.Dispaly();
	Date d6(d1 -= 60);
	d6.Dispaly();
}

//测试对于日期大小的比较
void test6()
{
	//Date d1(2017, 03, 31);
	//Date d2(2017, 03, 29);
	Date d1(2017, 4, 3);
	Date d2(2017, 4, 3);
	cout <<( d1 > d2);
	cout << (d1 >= d2);
	cout << (d1 <d2);
	cout << (d1 <= d2);
	cout << endl;

	//Date d3(2017, 03, 31);
	//Date d4(2017,04 ,28 );
	Date d3(2016, 12, 31);
	Date d4(2017, 4, 2);
	cout << (d3 > d4);
	cout << (d3 >= d4);
	cout << (d3 <d4);
	cout << (d3 <= d4);
}

//计算日期相隔多少天
void test7()
{
	Date d1(2017, 4, 2);
	Date d2(2017, 4, 2);
	Date d3(2017, 1,10);
	Date d4(2016, 12, 27);
	Date d5(2016,2, 27);
	//测试相等时候的返回值
	cout << d2 - d1<<endl;
	// 测试相差一月之内
	cout << d3 - d4<<endl;
	//相差大于一月
	cout << (d1 - d3)<<d3-d1<<endl;

	//相差大于一年
	cout << d1 - d5<<d5-d1;
	
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	getchar();
	return 0;
}
