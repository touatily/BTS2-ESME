#include <iostream>
#include "source.h"

using namespace std;

int main()
{
    Point p1(0, 10);
    Point p2(5,0);

    Point p3;

    Triangle t1(p1, p2, p3);

    Cercle c(p1, p2);

    Carre carr(p1, p2);

    Plan p;
    p.addForme(&p1);
    p.addForme(&t1);
    p.addForme(&c);
    p.addForme(&carr);
    p.addForme(&p1);
    p.addForme(&p2);
    p.addForme(&p3);

    cout << p;

    p.translater(1,1);
    cout << p;

}

