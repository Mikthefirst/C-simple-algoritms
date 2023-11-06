
#pragma once
#include "Str.h"


//constructors | destructors
Str::Str() :str_size(0) { str = new char[1]; *str = '\0'; }
Str::Str(const char ch):str_size(1) 
{ str = new char[2];
str[0] = ch;
str[1] = '\0'; }
Str::Str(const char* s) : str_size(len(s))
{
	str = new char[str_size + 1];
	copy(str, s);
}
//Str::~Str() { delete[] str; }





//metods
int Str::size() { return str_size; }
void Str::display() { std::cout << str << std::endl; }
void  Str::erase(int index) {
	
	if ( (index<str_size-1) && index>0 ) {
		--str_size;
		char* buf = new char[str_size + 1];
		for (size_t i = 0, j = 0; i < str_size + 1; ++i, ++j)
			if (j != index) { buf[i] = *(str + j); }
			else { --i; }
		delete[] str;
		str = new char[str_size];
		copy(str, buf);
		delete[] buf;
	}
	else std::cout << "Index that you want to delete do not exist.\n";
		
}

void Str::erase(int index1, int index2) {
	if((index1>0&&index2>0)&&(index1<str_size-1&&index2<str_size-1)){
		if (index1 > index2) { std::swap(index1,index2); }
		str_size = len(str) - (index2 - index1) - 1;
		char* buf = new char[str_size];
		for (size_t i = 0, j = 0; i < str_size + 1 + (index2 - index1); ++i, ++j)
		{
			if (j < index1 || j>index2) { buf[i] = *(str + j); }
			else { --i; }
		}
		delete[] str;
		str = new char[str_size + 1];
		copy(str, buf);
	}
	else std::cout << "Indexes that you want to delete do not exist.\n";
}

char* Str::upit() {
	for (int i = 0; i < str_size; ++i) {
		if (str[i] >= 224 && str[i < 256])str[i] -= 32;
		if (str[i] >= 97 && str[i < 123])str[i] -= 32;
	}
	return str;
}



//operators
Str operator+(Str left_arg, Str right_arg) {
	return Str(add(left_arg.str, right_arg.str, left_arg.str_size));
}

void Str::operator +=(Str right_arg) {
	copy(str, add(str, right_arg.str, str_size));
}

Str::operator  char* () const { return str; }
char& Str::operator [](int index) {
	return *(str + index);
}

std::istream& operator >> (std::istream& is, Str &s) {
	is>>s.str;
	s.str_size = len(s.str);;
	return is;
}
std::ostream& operator << (std::ostream& out, Str& s) {
	out << s.str;
	return out;
}





//functions
int len(const char* str)
{
	int i = 0;
	while (*str)
	{
		str++; ++i;
	}
	return i;
}
void copy(char* str, const char* str_c) {
	int lenght = 0;
	for (; *str_c; ++lenght)
		str[lenght] = *str_c++;
	str[lenght] = '\0';
}

char* add(char* str, const char* str_c, int& lenght) {
	size_t size = len(str) + len(str_c)+ 1;
	char* buf = str;
	str = new char[size];
	copy(str, buf);
	lenght = size - 1 - len(str_c);
	for (int i = lenght; *str_c; i++)
		str[i] = *str_c++;
	str[size-1] = '\0';
	lenght = size-1;
	return str;
}

int str_comp(const char* first, const char* last) {

	if (first == last)return 0;
	else {
		if(len(first)<len(last)){
		for (int i = 0; i < len(first); ++i) {
			if (first[i] < last[i])return -1;
			if (first[i] > last[i]) return 1;
		}
		return 1;
		}
		else
		{
			for (int i = 0; i < len(last); ++i) {
				if (first[i] < last[i])return -1;
				if (first[i] > last[i]) return 1;
			}
			return -1;
		}
	}
	
}