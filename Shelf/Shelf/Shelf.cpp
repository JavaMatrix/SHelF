#include "Shelf.h"
#include "ConsoleIO.h"
#include "Table.h"
using namespace std;


namespace shelf {
	namespace lib
	{
		int major = 1;
		int minor = 0;
		int patch = 0;
		string get_version()
		{
			return to_string(major) + '.' + to_string(minor) + '.' + to_string(patch);
		}
	}

	void ping(void) {
		cout << "SHelF Library Version: " + lib::get_version() << endl;
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