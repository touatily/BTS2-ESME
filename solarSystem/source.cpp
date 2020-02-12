#include "source.h"
#include<iostream>
#include <bits/stdc++.h>



using namespace std;

Planete::Planete(): nom("Sans nom"), masse(0), distance(0), periode(0),
    orbite(0), volume(0), temperature(0), position(0) {}

Planete::Planete(std::string n, float m, float d, float p, float o, float v, float t, float pos)
    :nom(n), masse(m), distance(d), periode(p),
    orbite(o), volume(v), temperature(t), position(pos){}

void Planete::addSatellite(Satellite * s){
    this->sat.push_back(s);

    sort(sat.begin(), sat.end(), Planete::compareSat);
}
bool Planete::existeSat(std::string n) const {
    /*
    for(unsigned int i=0; i < sat.size(); i++)
        if(sat[i]->nom == n)
            return true;
    return false;
    */
    std::vector<Satellite*>::const_iterator it;
    for(it = sat.begin(); it != sat.end(); ++it)
        if( (*it)->getNom() == n )
            return true;

    return false;
}

bool Planete::compareSat(const Satellite * s1, const Satellite * s2){
    return s1->getDistance() <= s2->getDistance();
}


std::ostream & operator<<(std::ostream & out, const Planete & p){
    out << "Planete : " << p.nom << endl;
    out << "\tPosition : " << p.position << endl;
    out << "\tPeriode orbitale : " << p.periode << endl;
    if (p.sat.size() > 0) {

        out << "\tListe Satellites : " << endl;
        for(unsigned int i = 0; i < p.sat.size(); i++)
            out << "\t\t" << *p.sat[i] << endl;
    }

    return out;
}


Satellite::Satellite():
    nom("Sans nom"), periode(0), distance(0){}

Satellite::Satellite(std::string n, float p, float d):
    nom(n),periode(p), distance(d){}

std::ostream & operator<<(std::ostream & out, const Satellite & s){
    out << "Satellite " << s.nom << ": Distance ( " << s.distance <<
    " ), Periode Orbitale ( " << s.periode << " )";
    return out;
}


Comete::Comete():nom("Sans nom"), periode(0){}
Comete::Comete(std::string n, float p) : nom(n), periode(p){}

Etoile::Etoile():nom("Sans nom"), masse(0), temperature(0), vitesse(0){}
Etoile::Etoile(std::string n, float m, float t, float v):
    nom(n), masse(m), temperature(t), vitesse(t){}

