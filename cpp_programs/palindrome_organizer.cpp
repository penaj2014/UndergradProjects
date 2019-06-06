/************************************************************************************************************************                    
Description:
This program will check if a string is a palidrone and allow us to replace sections of an original string by other chars.
*************************************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//prototypes
bool palindrome(const string & p);
string replace_all(const string & original_string, const string & old_substring, const string & new_substring);

//Precondition: takes a string of code.
//Postcondition: Returns bool type if the string is a Palandrome.
//Description: checks to see if the string's characters make the same string if assembled backwards.
bool palindrome(const string & p)
{
	int size = p.length();
	for (int i = 0; i < size; i++)
	{
		if (p[i] != p[size - i-1])
				return false;
	}
	return true;
}

//Precondition: Takes 3 strings into function.
//Postcondition: Returns a single string that.
//Description: Checks to see is a string is within another string. If it is then the "new" string is the replacement of the "old" string.
string replace_all(const string & original_string, const string & old_substring, const string & new_substring)
{
	string s = original_string;
	int sizeOld = old_substring.length() ;
	int sizeOrg = original_string.length() ;
	int j = 0, k = 0, l = 0;
	bool answer;
	for (int i = 0; i < sizeOrg; i++)
	{
		if (s[i] == old_substring[0])
		{
			k = i;
			l = k;
			while (s[k] == old_substring[j])
			{
				if (j == sizeOld)
				{
					answer = true;
				}
				cout << j << endl;
				
				cout << s[k] << endl << old_substring[j];
				j++;
				k++;
			}
		}
			if (answer == true)
			{
				j = 0;
				while (s[l] < s[k-1])
				{
					s[l] = old_substring[j];
					l++;
					j++;
				}
			}
			answer = false;
	}
	return s;
}

//main loop
int main()
{
	string original_string, old_substring, new_substring;
	char answer, choice;

	do {
		cout << endl << "Enter '1' to run palindrome or '2' to run replace_all: ";
		cin >> choice;

		if (choice == '1')
		{
			cout << "Please enter an original string: ";
			getline(cin, original_string);
			getline(cin, original_string);
			if (palindrome(original_string) == true)
				cout << "This IS a palindrome!";
			else
				cout << "This is NOT a palindrome :(";
		}

		else if (choice == '2')
		{
			cout << "Please enter an original string: ";
			getline(cin, original_string);
			getline(cin, original_string);
			cout << "Please enter an old string: ";
			getline(cin, old_substring);
			cout << "Please enter a new string: ";
			getline(cin, new_substring);
			cout << "Your new string is: "
				<< replace_all(original_string, old_substring, new_substring) << endl;
		}

		else
			cout << "That was not a correct entry." << endl;

		cout << endl << "Would you like to run the palindrome or replace_all function again?" << endl
			<< "Please enter Y or N: ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
		return 0;
}
