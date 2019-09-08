#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Word
{
public:
	string EN;
	string RU;
};

class CollectionWord
{
protected:
	vector<Word> words;
public:
	int GetSize() const { return words.size(); }
	void AddWord(Word w)
	{
		words.push_back(w);
	}
	void DeleteWord(string s)
	{
		for (size_t i = 0; i < words.size(); i++)
		{
			if (words[i].EN == s || words[i].RU == s)
				words.erase(words.begin() + i);
			else
				cerr << "No such word in dictionary." << endl;
		}
	}
	Word* Indexator(string s)
	{
		for (size_t i = 0; i < words.size(); i++)
		{
			if (words[i].EN == s || words[i].RU == s)
				return &words[i];
		}
		throw "Word not found.";
	}
	Word* Indexator(size_t index)
	{
		if (index < words.size())
			return &words[index];
		else
			throw "Word not found.";
	}
};

class Translate
{
private:
	CollectionWord* words;
public:
	void SetLib(CollectionWord* words) { this->words = words; }
	string EnToRu(string w) const
	{
		try
		{
			return words->Indexator(w)->RU;
		}
		catch (const char* ex)
		{
			return ex;
		}
	}
	string RuToEn(string w) const
	{
		try
		{
			return words->Indexator(w)->EN;
		}
		catch (const char* ex)
		{
			return ex;
		}
	}
};

class Parser
{
public:
	Word Parse(string EN, string RU)
	{
		return { EN, RU };
	}
};

class FileWork
{
public:
	CollectionWord Load(string FileName)
	{
		ifstream in(FileName);
		if (!in.is_open())
			throw "Error opening file for reading.";
		else
		{
			CollectionWord words;
			string EN, RU;
			while (!(in.peek() == EOF))
			{
				in >> EN >> RU;
				if (EN.size() > 0 && RU.size() > 0)
					words.AddWord({ EN, RU });
				EN = RU = "";
			}
			in.close();
			return words;
		}
	}
	bool Write(string FileName, CollectionWord& words)
	{
		ofstream out(FileName);
		if (out.is_open())
		{
			for (int i = 0; i < words.GetSize(); i++)
			{
				if (words.Indexator(i)->EN.size() > 0 && words.Indexator(i)->RU.size() > 0)
					out << words.Indexator(i)->EN << " " << words.Indexator(i)->RU << endl;
			}
			out.close();
			return true;
		}
		else
			cerr << "Error opening file for writing." << endl;
		return false;
	}
};

class FacadeFileBase
{
private:
	FileWork fileSystem;
	Translate translateSystem;
	CollectionWord words;
public:
	FacadeFileBase()
	{
		SetLib(&words);
	}
	void AddNewWord(string EN, string RU)
	{
		words.AddWord({ EN,RU });
	}
	void DeleteWord(string a)
	{
		words.DeleteWord(a);
	}
	bool WriteToBase()
	{
		string fileName;
		cout << "Enter filename to write your dictionary: ";
		cin >> fileName;
		return fileSystem.Write(fileName, words);
	}
	void ReadFromBase()
	{
		string fileName;
		cout << "Enter filename to read your dictionary: ";
		cin >> fileName;
		words = fileSystem.Load(fileName);
	}
	void SetLib(CollectionWord* words)
	{
		translateSystem.SetLib(words);
	}
	string GetTranslation()
	{
		string word, translation;
		cout << "Enter word to translate: ";
		cin >> word;
		translation = translateSystem.EnToRu(word);
		if (translation == word)
			return translateSystem.RuToEn(word);
		else
			return translation;
	}
};