#include <iostream>

#include <z/core.h>
//#include <z/math.h>
//#include <z/file.h>


using namespace std;
using namespace z;

int main()
{
    //complex<double> value;
    //cout << math::remainder(10, 8) << endl;
    //cout << math::remainder(complex<long>(100,0), complex<long>(80, 0)) << endl;

    cout << core::value(core::string<char>("2E-4"));

    return 0;
}
