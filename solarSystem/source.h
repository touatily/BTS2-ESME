#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include<string>
#include<iostream>
#include <vector>

class Satellite;

class Planete{
    std::string nom;
    float masse;
    float distance;
    float periode;
    float orbite;
    float volume;
    float temperature;
    float position;

    std::vector<Satellite *> sat;

    friend std::ostream & operator<<(std::ostream & out, const Planete & p);

    static bool compareSat(const Satellite  * s1, const Satellite * s2);


public:
    Planete();
    Planete(std::string n, float m, float d, float p, float o, float v, float t, float pos = 0);

    void addSatellite(Satellite * s);
    bool existeSat(std::string n) const;
};


class Satellite{
    std::string nom;
    float periode;
    float distance; // de la planète

    friend std::ostream & operator<<(std::ostream & out, const Satellite & s);

public:
    Satellite();
    Satellite(std::string n, float p, float d);
    std::string getNom() const {return nom;};
    float getDistance() const {return distance;}

};


class Comete{
    std::string nom;
    float periode;
public:
    Comete();
    Comete(std::string n, float p);
};


class Etoile{
    std::string nom;
    float masse;
    float temperature;
    float vitesse;

public:
    Etoile();
    Etoile(std::string n, float m, float t, float v);
};

#endif // SOURCE_H_INCLUDED

