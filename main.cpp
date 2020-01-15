#include <iostream>
#include "declarations.h"

using namespace std;
using namespace soup;

int main()
{
    Potatoe p = Potatoe(0.3, 10);
    cout << p.getCalories() << endl;
    Carrot c = Carrot(0.25, 30);
    cout << c.getCalories() << endl;
    Soup s = Soup();
    s.add(&p);
    s.add(&c);
    cout << s.getCalories() << endl;


    //delete pdt;
    //delete c;

    /*  Partie 1
    Carrot c = Carrot(0.25, 30);
    cout << c << endl;

    Potatoe pdt1 = Potatoe(0.3, 10);
    Potatoe pdt2 = Potatoe(0.3);
    Potatoe pdt3 = Potatoe(0.75);

    cout << pdt1 << endl;
    cout << pdt2 << endl;
    cout << pdt3 << endl;
    */
    return 0;
}
