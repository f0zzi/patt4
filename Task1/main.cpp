#include <iostream>
#include "Proxy.h"
using namespace std;

int main()
{
	Door* door = new Door;
	SecureProxy proxy(door);
	door->ShowStatus();
	proxy.Open("login", "pass");
	door->ShowStatus();
	proxy.Open("login", "password");
	door->ShowStatus();
	system("pause");
	return 0;
}