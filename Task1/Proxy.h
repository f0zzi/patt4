#pragma once
#include <iostream>
#include <map>
using namespace std;

enum States { CLOSED = 0, OPENED };

typedef string LOGIN;
typedef string PASSWORD;

__interface IDoor
{
	void Close() = 0;
	void Open();
};

class Door : public IDoor
{
private:
	bool state = CLOSED;
public:
	Door() {}
	bool GetStatus() { return state; }
	void ShowStatus()
	{
		cout << "Door is " << (GetStatus() ? "opened." : "closed.") << endl;
	}
	void Open() { state = OPENED; }
	void Close() { state = CLOSED; }
};

class SecureProxy
{
private:
	Door* door;
	map<LOGIN, PASSWORD> users{ {"login","password"} };
public:
	SecureProxy(Door* door) :door(door) {}
	void Close()
	{
		door->Close();
	}
	bool GetAuthorisation(LOGIN login, PASSWORD psw)
	{
		auto user = users.find(login);
		if (user != users.end())
			return psw == user->second;
		else
			return false;
	}
	void Open(LOGIN login, PASSWORD psw)
	{
		if (GetAuthorisation(login, psw))
			door->Open();
		else
			cout << "Authorisation failed." << endl;
	}
};