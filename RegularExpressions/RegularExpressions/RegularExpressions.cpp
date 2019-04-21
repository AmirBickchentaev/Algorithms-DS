// RegularExpressions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<regex>
using namespace std;

void printMatches(string str,regex reg) 
{
	smatch matches;
	cout << boolalpha;
	while (regex_search(str,matches,reg))
	{
		cout << "Is there's a match " << matches.ready() << "\n";
		cout << "Are there's a match " << matches.empty() << "\n";
		cout << "How many matches " << matches.size() << "\n";
		cout << matches.str(1) << "\n";
		str = matches.suffix().str();
		cout << "\n";

	}
}
void printMatches2(string generalString,regex regularExpression)
{
	sregex_iterator currentMatch(generalString.begin(), generalString.end(), regularExpression);
	sregex_iterator lastMatch;
	while (currentMatch != lastMatch)
	{
		smatch match = *currentMatch;
		cout << match.str() << "\n";
		currentMatch++;
	}
	cout << "\n";
}


int main()
{
	string str = "The ape was at apexes";
	smatch matches;
	regex rex("(ape[\D]*)");
	printMatches2(str, rex);

	string str1 = "I picked a  picklesious";
	regex reg1("(pick[\\S ]+)");
	printMatches2(str1, reg1);


	string str2 = "Cat mat nat bat dat";
	regex reg2("([Cmbd]at)");
	printMatches2(str2, reg2);


	regex reg3("([^C-Zc-z]at)");
	printMatches2(str2, reg3);

	regex reg4("([^C-Zc-z]at)");
	printMatches2(str2, reg4);
	string orgs = " F.B.I. C.I.A. I.R.S";
	regex orgsReg("(.\..\..\. )");

	printMatches2(orgs, orgsReg);
	string owlFood = regex_replace(str2,reg3,"bui");
	string str8 = "This is a\n multiline with string\n"
		"that has a many lines";
	regex reg8 ("\n");
	string noLBString = regex_replace(str8, reg8, " ");
	cout << noLBString;


	string str9 = "12 123 1234 12345 132456";
	regex reg9("([\\d]{3,6})");
	printMatches2(str9, reg9);

	string str10 = "937-591-5873";
	regex reg10("\\w{3}-\\w{3}-\\w{4}");
	printMatches2(str10, reg10);

	string str11 = "Satoshi Nakamoto";
	regex reg11("\\w{2,20}\\w{2,20}");
	printMatches2(str11, reg11);
	
	string str12 = "panasonic-5670@yandex.ru panasonic-5671@yandex.ru";
	regex reg12("([\\w]{3,15}-[\\d]{3,5}@[\\w]{3,10}\.[\\w]{2,5})");
	printMatches2(str12, reg12);


 }

