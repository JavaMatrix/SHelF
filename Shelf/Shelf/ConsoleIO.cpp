/*
 * Shelf - Super HELpful Functions library
 * Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * Contains functions to help with fundamental C++ tasks.
 *
 * ConsoleIO.cpp - contains definitions for the ConsoleIO class.
 */

#include "ConsoleIO.h"

using namespace std;

namespace shelf {
	void ConsoleIO::Write(string value) {
		cout << value;
	}

	void ConsoleIO::WriteLine(string value) {
		Write(value);
		cout << endl;
	}

	int ConsoleIO::GetNextInt(string prompt, int def) {
		Write(prompt);
		char buffer[100];
		cin.getline(buffer, 100);

		char *temp;
		int retval = strtol(buffer, &temp, 0);

		if (*temp != '\0') {
			return def;
		}

		return retval;
	}

	long ConsoleIO::GetNextLong(string prompt, long def) {
		Write(prompt);
		char buffer[100];
		cin.getline(buffer, 100);

		char *temp;
		int retval = strtol(buffer, &temp, 0);

		if (*temp != '\0') {
			return def;
		}

		return retval;
	}

	double ConsoleIO::GetNextDouble(string prompt, double def) {
		Write(prompt);
		char buffer[100];
		cin.getline(buffer, 100);

		char* temp;
		double retval = strtod(buffer, &temp);

		if (*temp != '\0') {
			return def;
		}

		return retval;
	}

	float ConsoleIO::GetNextFloat(string prompt, float def) {
		Write(prompt);
		char buffer[100];
		cin.getline(buffer, 100);

		char* temp;
		float retval = (float) strtod(buffer, &temp);

		if (*temp != '\0') {
			return def;
		}

		return retval;
	}

	string ConsoleIO::GetNextString(string prompt, int maxLength) {
		return string(GetNextCString(prompt, maxLength));
	}

	char* ConsoleIO::GetNextCString(string prompt, int maxLength) {
		Write(prompt);

		// Add one for the null terminator.
		char* buffer = new char[maxLength + 1];
		cin.getline(buffer, maxLength + 1);

		return buffer;
	}

	string ConsoleIO::GetNextStringMasked(string prompt, string mask, int maxLength) {
		Write(prompt);

		string retVal = "";
		char ch = _getch();
		while (ch != 13) { // Stop at a carriage return.
			if (ch == 8)  { // Backspace
				retVal.pop_back();
			}
			else {
				retVal.push_back(ch);
				cout << mask;
				ch = _getch();
			}
		}
		WriteLine();
		return retVal;
	}

	char ConsoleIO::GetNextChar(string prompt, char* choices, int numChoices) {
		// Loop until valid input, or 10 times.
		for (int i = 0; i < 10; i++) {
			Write(prompt);

			char* buffer = new char[200];
			cin.getline(buffer, 200);
			char choice = tolower(buffer[0]);

			if (in(choice, choices, numChoices)) {
				return choice;
			}

			WriteLine("Invalid choice.");
		}
		// Just return the first choice as the default.
		return choices[0];
	}

	void ConsoleIO::Wait() {
		Write("Press any key to continue...");
		_getch();
	}

		int ConsoleIO::GetNextPositiveInt(string prompt, string warn, string reprompt) {
		int retVal = GetNextInt(prompt, -1);
		while (retVal < 0) {
			WriteLine(warn);
			retVal = GetNextInt(reprompt, -1);
		}
		return retVal;
	}
	
	double ConsoleIO::GetNextPositiveDouble(string prompt, string warn, string reprompt) {
		double retVal = GetNextDouble(prompt, -1);
		while (retVal < 0) {
			WriteLine(warn);
			retVal = GetNextDouble(reprompt, -1);
		}
		return retVal;
	}

	bool ConsoleIO::in(char choice, char* validChoices, int numChoices) {
		for (int i = 0; i < numChoices; i++) {
			if (validChoices[i] == choice) {
				return true;
			}
		}
		return false;
	}
}