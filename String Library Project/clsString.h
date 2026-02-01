#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class clsString
{
private:
	string _value;

public:

	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		_value = value;
	}

	void SetStringValue(string value)
	{
		_value = value;

	};

	string GetStringValue()
	{
		return _value;
	};
	__declspec(property(get = GetStringValue , put = SetStringValue)) string Value;

	static short Length(string s1)
	{
		return s1.length();
	}
	short Length()
	{
		return _value.length();
	}

	static short CountWords(string S1)
	{
		string Delim = " ";
		short Pos = 0;
		short counter = 0;
		string sWord;

		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, Pos);
			if (sWord != " ")
			{
				counter++;
			}

			S1.erase(0, Pos + Delim.length());
		}
		if (S1 != " ")
		{
			counter++;
		}
		return counter;
	}
	short CountWords()
	{
		return  CountWords(_value);
	};

  static  string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}
	void UpperAllString()
	{
		_value = UpperAllString(_value);
    }  

	 static string Lower(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}
	 string Lower()
	 {
		 return Lower(_value);
	 }

static string UpperFirstLetterOfEachWord(string S1)
	 {
		 bool IsFirstLetter = true;

		 for (int i = 0; i < S1.length(); i++)
		 {

			 if (S1[i] != ' ' && IsFirstLetter)
			 {
				 S1[i] = toupper(S1[i]);
			 }

			 IsFirstLetter = (S1[i] == ' ' ? true : false);
		 }
		 return S1;
	 } 
string UpperFirstLetterOfEachWord()
	 {
		 return UpperFirstLetterOfEachWord(_value);
	 }
static string LowerFirstLetterOfEachWord(string S1)
	 {
		 bool IsFirstLetter = true;

		 for (int i = 0; i < S1.length(); i++)
		 {

			 if (S1[i] != ' ' && IsFirstLetter)
			 {
				 S1[i] = tolower(S1[i]);
			 }

			 IsFirstLetter = (S1[i] == ' ' ? true : false);
		 }
		 return S1;
	 }
string LowerFirstLetterOfEachWord()
{
	return LowerFirstLetterOfEachWord(_value);
}

static string RemovePunctuations(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}

string RemovePunctuations()
{
	return RemovePunctuations(_value);

}

static string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{

		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - 1);
		}

	}
	return "";
}
string TrimLeft()
{
	return TrimLeft(_value);
}

static string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{

		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}

	}
	return "";
}
string TrimRight()
{
	return TrimRight(_value);
}

static string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));
}
string Trim()
{
	return Trim(_value);
}


static char InvertLetterCase(char C1)
{
	return  isupper(C1) ? tolower(C1) : toupper(C1);

}
string InvertAllLetterCase(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}
void InvertAllLetterCase()
{
	_value = InvertAllLetterCase(_value);
}

static short CountSpecificLetter(string S1, char Letter, bool matchCase = true)
{
	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (matchCase)
		{
			if (S1[i] == Letter)
				Count++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Count++;
		}
	}
	return Count;
}
short CountSpecificLetter( char Letter, bool matchCase = true)
{
	return CountSpecificLetter(_value, Letter, matchCase);
}

enum enwahtToCount { SmallLetters = 0, Capitalletters = 1, all = 3 };

static short CountLetters(string S1, enwahtToCount WahtTocount = enwahtToCount::all)
{
	if (WahtTocount == enwahtToCount::all)
	{
		return S1.length();
	}



	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (WahtTocount == enwahtToCount::Capitalletters && isupper(S1[i]))
			Count++;

		if (WahtTocount == enwahtToCount::SmallLetters && islower(S1[i]))
			Count++;


	}

	return Count;

}

static short CountCapitalLetter(string S1)
{
	short CountCapitalLetter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			CountCapitalLetter++;
		}

	}

	return CountCapitalLetter;
}
short CountCapitalLetter()
{
	return CountCapitalLetter(_value);
}
static short CountSmallLetter(string S1)
{
	short CountSmallLetter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			CountSmallLetter++;
		}

	}

	return CountSmallLetter;
}
short CountSmallLetter()
{
	return CountSmallLetter(_value);
}

static bool IsVowel(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));

}

static short CountVowels(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{

		if (IsVowel(S1[i]))
		{
			Counter++;
		}

	}
	return Counter;
}
short CountVowels()
{
	return CountVowels(_value);

}


static vector <string> Split(string S1, string Delim)
{
	vector<string> vstring;

	short Pos = 0;
	string sWord;

	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != " ")
		{
			vstring.push_back(sWord);
		}

		S1.erase(0, Pos + Delim.length());
	}
	if (S1 != " ")
	{
		vstring.push_back(S1);
	}

	return vstring;
}
vector <string> Split ( string Delim)
{
	return Split(_value, Delim);
}


static string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

static string JoinString(string arrString[], short Length, string Delim)
{
	string S1 = "";
	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + arrString[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

static string ReverseWordsInString(string S1)
{
	vector<string> vString;
	string S2 = "";

	vString = Split(S1, " ");

	// declare iterator
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);  //remove last space.

	return S2;
}
void ReverseWords()
{
	_value = ReverseWordsInString(_value);
}

static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	vector<string> vString = Split(S1, " ");
	for (string& s : vString)

		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRepalceTo;
			}
		}
		else
		{
			if (Lower(s) == Lower(StringToReplace))
			{
				s = sRepalceTo;
			}
		}

	return JoinString(vString, " ");
}
string ReplaceWord(string StringToReplace, string sRepalceTo)
{
	return ReplaceWord(_value, StringToReplace, sRepalceTo);
}


};

