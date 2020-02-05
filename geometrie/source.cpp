#include "source.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Point::Point(): x(0.0), y(0.0){
}

Point::Point(float xx, float yy): x(xx), y(yy){
}

ostream & operator<<(ostream & out, const Point & p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

bool Point::operator==(const Point & p){
    return (x == p.x) && (y == p.y);
}
bool Point::operator!=(const Point & p){
    return (x != p.x) || (y != p.y);
}
Point Point::operator-(){
    return Point(-x, -y);
}

float Point::distance(const Point & p) const{
    return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y)) ;
}
float Point::distance() const{
    return sqrt((x * x) + (y * y)) ;
}


void Point::translater(float x, float y){
    this->x += x;
    this->y += y;
}

float Point::getX() const{
    return x;
}
float Point::getY() const{
    return y;
}


Triangle::Triangle(const Point &a, const Point &b, const Point &c)
: A(a), B(b), C(c){
}

float Triangle::perimetre() const{
    float p = A.distance(B) + B.distance(C) + C.distance(A);
    return p;
}

void Triangle::translater(float x, float y){
    A.translater(x,y);
    B.translater(x,y);
    C.translater(x,y);
}


bool Triangle::isRectangle() const{

    float m = A.distance(B);
    float d1 = B.distance(C);
    float d2 = A.distance(C);

    cout << m << " " << d1 << " " << d2 << endl;
    float t;
    if( d1 > m ) {
        t = m;
        m = d1;
        d1 = t;
    }
    if( d2 > m ) {
        t = m;
        m = d2;
        d2 = t;
    }

    float diff = (m*m) - ((d1*d1) + (d2*d2));

    return (diff < 0.0001);
}
std::string Triangle::toString() const{

    std::ostringstream ss;
    ss << "Triangle : A(" << A.getX() << "," << A.getY() << ")"
    << "," << " B(" << B.getX() << "," << B.getY() << ")"
    << ", C(" << C.getX() << "," << C.getY() << ")";
    return  ss.str();
}

ostream & operator<<(ostream & out, const Triangle & t) {
    out << t.toString();
    return out;
}

Carre::Carre(float x1, float y1, float x2, float y2):
    P1(Point(x1, y1)), P2(Point(x2, y2)){
}
Carre::Carre(Point p1, Point p2):P1(p1), P2(p2){
}

float Carre::perimetre(){
    float d = P1.distance(P2);
    float c = sqrt(d*d / 2);
    return 4 * c;
}
float Carre::superficie(){
    float d = P1.distance(P2);
    return d*d / 2;
}

void Carre::translater(float x, float y){
    P1.translater(x, y);
    P2.translater(x, y);
}

// Cercle

Cercle::Cercle(float x, float y, float r)
:rayon(r), centre(Point(x, y)){
}
Cercle::Cercle(const Point& c, float r)
:rayon(r), centre(c){
}
Cercle::Cercle(const Point& c, const Point & p)
:rayon(c.distance(p)), centre(c){
}

bool Cercle::appartient(Point p) const{
    float d = p.distance(centre);
    return fabs(d - rayon) < 0.001;
}

void Cercle::translater(float x, float y){
    centre.translater(x, y);
}

float Cercle::superficie() const{
    return rayon * rayon * M_PI ;
}
float Cercle::perimetre() const {
    return 2 * rayon * M_PI;
}

std::ostream & operator<<(std::ostream & out, const Cercle & c){
    out << "Cercle : Centre " << c.centre << ", Rayon = " << c.rayon;
    return out;
}


