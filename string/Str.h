#pragma once
#include <iostream>

//functions
void copy(char*, const char*);
char* add(char*, const char*, int&);
int len(const char*);
int str_comp(const char*f, const char*l);



class Str {
private:
	char* str;
	int str_size;
public:
//constructors
	Str();
	Str(const char);
	Str(const char*);
	/*~Str();*/

//methods
	int size();
	void display();
	void erase(int index);
	void erase(int index1, int index2);
	char* upit();

//operators
	friend Str operator+(Str,Str);
	void operator +=(Str);
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::ostream& operator << (std::ostream& is, Str& s);
	char& operator [](int index);
	operator  char* () const;

};
