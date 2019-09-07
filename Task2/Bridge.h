#pragma once
#include <iostream>
using namespace std;

class Language abstract
{
private:
	string name;
public:
	Language(string name) : name(name) {}
	virtual double GetHourPrice() = 0;
	string GetName() { return name; }
};

class CPP : public Language
{
public:
	CPP() :Language("C++") {}
	double GetHourPrice() { return 8; }
};

class Java : public Language
{
public:
	Java() :Language("Java") {}
	double GetHourPrice() { return 10; }
};

class Programmer abstract
{
private:
	string name;
protected:
	Language* lang;
public:
	Programmer(string name, Language* lang) : name(name)
	{
		SetLanguage(lang);
	}
	void SetLanguage(Language* lang)
	{
		this->lang = lang;
	}
	virtual double CalcSalary(int hours) = 0;
};

class Office : public Programmer
{
private:
	double tax = 6;
public:
	Office(string name, Language* lang) :Programmer(name, lang) {}
	double CalcSalary(int hours)
	{
		return lang->GetHourPrice() * hours * (1 - (tax / 100));
	}
};

class Freelance : public Programmer
{
private:
	double regPrice = 10;
public:
	Freelance(string name, Language* lang) :Programmer(name, lang) {}
	double CalcSalary(int hours)
	{
		return lang->GetHourPrice() * hours - regPrice;
	}
};