#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <iostream>
#include <vector>

class Plan;

class Forme2D{ // class abstraite
    friend std::ostream & operator<<(std::ostream & out, const Plan & p);
    virtual void print() const = 0;
public:
    virtual void translater(float x, float y) = 0; // méthode virtuelle pure
    virtual float perimetre() const = 0;
    virtual float superficie() const = 0;

};


class Point : public Forme2D{
    friend std::ostream & operator<<(std::ostream & out, const Point & p);
    void print() const;
protected:
    float x, y;
public:
    Point();
    Point(float xx, float yy);

    float getX() const;
    float getY() const;

    bool operator==(const Point & p) const;
    bool operator!=(const Point & p) const;
    Point operator-() const;

    float distance(const Point & p) const;
    float distance() const;

    void translater(float x, float y);

    float perimetre() const { return 0;}   // Un point n'a pas de périmètre
    float superficie() const { return 0;}; // Un point n'a pas de superficie



};


class Triangle : public Forme2D{
    friend std::ostream & operator<<(std::ostream & out, const Triangle & t);
    void print() const;
protected:
    Point A, B, C;
public:
    Triangle(const Point &a, const Point &b, const Point &c);
    float perimetre() const;
    void translater(float x, float y);
    bool isRectangle() const;
    float superficie() const { return 0;};
    // C'est juste parce que le calcul de la superficie d'un triangle est compliqué
    // et Pour éviter que la classe triangle devienne une classe abstraite
    std::string toString() const;

};

class Carre : public Forme2D{
    friend std::ostream & operator<<(std::ostream & out, const Carre & c);
    void print() const;
protected:
    Point P1, P2;

public:
    Carre(float x1, float y1, float x2, float y2);
    Carre(Point p1, Point p2);

    float perimetre() const;
    float superficie() const ;
    void translater(float x, float y);
};

class Cercle : public Forme2D{
    friend std::ostream & operator<<(std::ostream & out, const Cercle & c);
    void print() const;
protected:
    float rayon;
    Point centre;

public:
    Cercle(float x, float y, float r);
    Cercle(const Point & c, float r);
    Cercle(const Point & c, const Point & p);

    bool appartient(const Point & p) const;
    void translater(float x, float y);
    float superficie() const;
    float perimetre() const;
};


class Plan{
    friend std::ostream & operator<<(std::ostream & out, const Plan & p);

protected:
    std::vector<Forme2D *> figures;
public:
    int existe(const Forme2D & f) const;
    bool addForme(Forme2D * f);
    void translater(float x, float y);
};


#endif // SOURCE_H_INCLUDED

