#include <iostream>

#include <z/core.h>
#include <z/math.h>
//#include <z/file.h>


using namespace std;
using namespace z;

int main()
{
    //complex<double> value;
    //cout << math::remainder(10, 8) << endl;
    //cout << math::remainder(complex<long>(9,13), complex<long>(3, 0)) << endl;
    long total_micros = 0;

    core::timer time(true);

    for (int i=0; i<1000; i++)
    {
        time.reset();
        math::zeta(2);
        total_micros += time.micros();
    }
    cout << "Average time to calculate Zeta function:\n"
         << (double)(total_micros/1000) / 1000.0 << " milliseconds\n";
    //core::string<char> b ((double)(1.0/5000000000000000000000000.0));


    //math::i_pow(2, 10);

    //cout << a.str() << endl;
    //cout << b.str() << endl;

    //cout << core::value(core::string<char>("2E-4"));

    return 0;
}
