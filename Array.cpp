#include"Str.h"
#include<typeinfo>
using namespace std;
template<class InputIterator, class OutputIterator>
OutputIterator safe_copy(InputIterator*, size_t, OutputIterator*);
class Array {
private:
	int* arr;
	int size;
public:
	Array(int s) {
		size = s;
		arr = new int[s];
	}
	~Array() {
		delete[]arr;
	}
	int& operator[](int j) {
		if (j >= size)
		{
			++size;
			int* buf = new int[size - 1];
			std::copy(arr, (arr + size - 1), buf);
				delete[]arr;
				arr = new int[size];
				std::copy(buf, (buf + size - 1), arr);
				delete[]buf;
		}

		return arr[j];
	}
	Array& operator=(Array& right) {
		if (size >= right.size) { std::copy(right.arr, right.arr + right.size, arr); }
		else{
			delete[]arr;
			arr = new int[right.size];
			size = right.size;
			std::copy(right.arr, right.arr + right.size, arr);
		}
		return *this;
	}
	Array (Array& right) {
		size = right.size;
		arr = new int[size];
		std::copy(right.arr, right.arr + right.size, arr);
	}
};

int main()
{
	setlocale(0, "");

	Array arr(10),arr1(5);
	for (int i = 0; i < 11; i++)
	{
		arr[i] = i * i;
	}

	arr1 = arr;
	for (int i = 0; i < 12; i++)
	{
		cout << arr1[i] << ' ';
	}
	Array ar2(arr1);
	for (int i = 0; i < 12; i++)
	{
		cout << ar2[i] << ' ';
	}
}   
template<class InputIterator, class OutputIterator>
OutputIterator safe_copy(InputIterator *first, size_t size_cpy, OutputIterator *result) {
	size_t num_to_grow = sizeof(first) / sizeof(InputIterator);
	OutputIterator* buf = new OutputIterator[size_cpy];
	std::copy(result, (result + size_cpy), buf);
	delete[]result;
	result = new int[size_cpy + num_to_grow];
	std::copy(buf, (buf + size_cpy), result);
	for (size_t i = size_cpy ; i < size_cpy + num_to_grow; ++i)
	{
		result[i] = *first++;
	}
	delete[]buf;
	return result;
}

//class publication {
//public:
//	virtual void putdata() {
//		cout << "Введите название:  "; cin >> name; 
//		cout << "Введите стоимость:  "; cin >> cost;
//	}
//	virtual void getdata() {
//		cout << "Название: " << name << endl;
//		cout << "Стоимость" << cost << endl;
//	};
//protected:
//	Str name;
//	float cost;
//};
//
//class book : public publication {
//private:
//	int pages_count;
//public:
//	void change_pages(int p) {
//		pages_count = p;
//	}
//	void putdata() {
//		publication::putdata();
//		cout << "Введите количество страниц:  "; cin >> pages_count;
//	}
//	void getdata() {
//		publication::getdata();
//		cout << "Количество страниц:  "<< pages_count<<endl;
//	}
//};
//
//class tape:public publication{
//private:
//	int minutes;
//public:
//	void putdata() {
//		publication::putdata();
//		cout << "Введите количество минут:  "; cin >> minutes;
//	}
//	void getdata() {
//		publication::getdata();
//		cout << "Количество минут:  " << minutes << endl;
//	}
//};

	//publication *p1[2];
	//tape* t1 = new tape;
	//book *b1 = new book;
	//t1->putdata();
	//b1->putdata();
	//p1[0] = t1;
	//p1[1] = b1;
	//p1[0]->getdata();
	//p1[1]->getdata();