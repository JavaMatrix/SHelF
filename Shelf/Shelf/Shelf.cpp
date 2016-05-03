/*
 * Shelf - Super HELpful Functions library
 * Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * Contains functions to help with fundamental C++ tasks.
 *
 * Shelf.cpp - contains definitions for .
 */

#include "Shelf.h"
#include "ConsoleIO.h"
#include "Table.h"
using namespace std;


namespace shelf {
	namespace lib
	{
		//SHelF uses a Semantic versioning system as specified here: http://semver.org/spec/v2.0.0.html
		int major = 1;
		int minor = 0;
		int patch = 1;
		string get_version()
		{
			return to_string(major) + '.' + to_string(minor) + '.' + to_string(patch);
		}
		void steve() {
			ConsoleIO::WriteLine("Steven, I don't know you were in this library!");
		}
	}

	void ping(void) {
		cout << "SHelF Library Version: " + lib::get_version() << endl;
		cout << "SHelF on GitHub: http://github.com/javamatrix/SHelF" << endl<<endl;
	}

	string to_string(int num) {
		return std::to_string((long long) num);
	}

	string to_string(double num) {
		return std::to_string((long double) num);
	}

	string to_string(unsigned int num) {
		return std::to_string((long long) num);
	}
}
