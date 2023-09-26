#include <sstream>

#include "Fraction.h"

using namespace std;

int main(int argc, char* argv[])
{
	Fraction f;
	stringstream ss;
	ss << "1/2";
	ss >> f;
    return 0;
}
