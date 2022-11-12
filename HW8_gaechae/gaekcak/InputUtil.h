#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace  std;
class InputUtil
{
public:
	inline static void InputValue(int&i);
	inline static void InputValue(string&i);
	inline static void InputValue(char*i);
	inline static void InputValue(float&i);
	inline static void InputValue(double&i);
};

inline static void InputValue(int&i)
{
	cin >> i;
	cin.ignore();

}


inline static void InputValue(string&i)
{
	getline(cin, i);

}


inline static void InputValue(char*i)
{
	cin >> i;
	cin.ignore();
}


inline static void InputValue(float&i)
{

	cin >> i;
	cin.ignore();

}



inline static void InputValue(double&i)
{
	cin >> i;
	cin.ignore();

}