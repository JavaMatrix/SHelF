#include "Shelf.h"
using namespace std;

namespace shelf {
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