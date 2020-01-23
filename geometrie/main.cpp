#include <iostream>
#include "source.h"

using namespace std;

int main()
{
    Point p1(0, 10);
    Point p2(5,0);

    Point p3;

    Triangle t1(p1, p2, p3);

    if (t1.isRectangle())
        cout << "rectangle" << endl;
    else
        cout << "Non rectangle !" << endl;


    cout << "perim : " << t1.perimetre() << endl;

    string s = t1.toString();
    cout << t1 << endl;


}

