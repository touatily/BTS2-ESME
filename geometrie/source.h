#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <iostream>

class Point{
    friend std::ostream & operator<<(std::ostream & out, const Point & p);
protected:
    float x, y;
public:
    Point();
    Point(float xx, float yy);

    float getX() const;
    float getY() const;

    bool operator==(const Point & p);
    bool operator!=(const Point & p);
    Point operator-();

    float distance(const Point & p) const;
    float distance() const;

    void translater(float x, float y);

};


class Triangle{
    friend std::ostream & operator<<(std::ostream & out, const Triangle & t);
protected:
    Point A, B, C;
public:
    Triangle(const Point &a, const Point &b, const Point &c);
    float perimetre() const;
    void translater(float x, float y);
    bool isRectangle() const;
    std::string toString() const;
};

class Carre{
    friend std::ostream & operator<<(std::ostream & out, const Carre & c);
protected:
    Point P1, P2;

public:
    Carre(float x1, float y1, float x2, float y2);
    Carre(Point p1, Point p2);

    float perimetre();
    float superficie();
    void translater(float x, float y);

};

class Cercle{
    friend std::ostream & operator<<(std::ostream & out, const Cercle & c);
protected:
    float rayon;
    Point centre;

public:
    Cercle(float x, float y, float r);
    Cercle(const Point & c, float r);
    Cercle(const Point & c, const Point & p);

    bool appartient(Point p) const;
    void translater(float x, float y);
    float superficie() const;
    float perimetre() const;
};

#endif // SOURCE_H_INCLUDED

