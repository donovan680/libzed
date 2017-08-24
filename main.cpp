#include <iostream>

//#define Z_USE_DOUBLE

#include <z/core.h>
#include <z/math.h>
//#include <z/file.h>


using namespace std;
using namespace z;

int main()
{
    //complex<zFloat> value;
    //cout << math::remainder(10, 8) << endl;
    //cout << math::remainder(complex<long>(9,13), complex<long>(3, 0)) << endl;
    long total_micros = 0;

    core::timer time(true);

    int i = 1;
    for (i=1; i<=1000; i++)
    {
        time.reset();
        math::zeta(2);
        total_micros += time.micros();

        //if (i % 10)
            //cout << ".";
    }
    cout << endl;
    cout << "Average time to calculate Zeta function:\n"
         << ((zFloat)total_micros/(zFloat)i) / 1000.0 << " milliseconds\n";
    core::string<char> z (math::zeta(2));
    cout << z.str() << endl;

    //math::i_pow(2, 10);

    //cout << a.str() << endl;
    //cout << b.str() << endl;

    //cout << core::value(core::string<char>("2E-4"));

    return 0;
}
