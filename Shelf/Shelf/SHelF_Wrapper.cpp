#include <iostream>
#include <string>
#include "SHelF_Wrapper.h"
#include "Tables.h"

using namespace std;

int Lib_Major = 0;
int Lib_Minor = 0;
int Lib_Patch = 0;
string Lib_Version = to_string(Lib_Major) + '.' + to_string(Lib_Minor) + '.' + to_string(Lib_Patch);

void SHelF_Ping(void) {
	cout << "SHelF Library Version: " + Lib_Version << endl;
}