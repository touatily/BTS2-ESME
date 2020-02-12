#include <iostream>
#include "source.h"

using namespace std;

int main()
{
    Planete p("Terre", 5.972, 149.6, 365.2563, 940, 788, 25, 0 );

    Satellite s1("Lune", 6.7, 9.9);
    Satellite s2("Lune1", 6.7, 15);
    Satellite s3("Lune2", 6.7, 6);

    p.addSatellite(&s1);
    p.addSatellite(&s2);
    p.addSatellite(&s3);

    cout << p << endl;
}

