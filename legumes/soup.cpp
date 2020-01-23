#include "declarations.h"
#include <iostream>

soup::Vegetable::Vegetable():poids(0){}
soup::Vegetable::Vegetable(float p):poids(p){}

void soup::Vegetable::print(std::ostream & out) const {
    out << "Vegetable: [" << poids << " kg]";
}

soup::Vegetable::~Vegetable(){}

std::ostream & soup::operator<<(std::ostream & out, const soup::Vegetable& v){
    v.print(out);
    return out;
}

float soup::Vegetable::getPeelingWeight(){
    return soup::Vegetable::epluchure * poids;
}

float soup::Vegetable::epluchure = 0.10;

void soup::Vegetable::setPeelingWeight(float e){
    soup::Vegetable::epluchure = e;
}


soup::Carrot::Carrot(): Vegetable(0), longueur(0){}

soup::Carrot::Carrot(float p, float l):Vegetable(p), longueur(l) {}

float soup::Carrot::getPoids() const{
    return poids;
}
float soup::Carrot::getLongueur() const{
    return longueur;
}

void soup::Carrot::print(std::ostream & out) const{
    out << "Carrotte: [" << poids << " kg - " << longueur << " cm]";
}

unsigned int soup::Carrot::getCalories() const {
    return (unsigned int) (poids * 400);
}

std::ostream & soup::operator<<(std::ostream & out, const soup::Carrot& c){
    c.print(out);
    return out;
}



soup::Potatoe::Potatoe(): Vegetable(0), germes(0){}

soup::Potatoe::Potatoe(float p, unsigned int g):Vegetable(p), germes(g) {}

soup::Potatoe::Potatoe(float p):Vegetable(p), germes((int)(p * 10)) {}

float soup::Potatoe::getPoids() const{
    return poids;
}
unsigned int soup::Potatoe::getGermes() const{
    return germes;
}

void soup::Potatoe::print(std::ostream & out) const{
    out << "Patate: [" << poids << " kg - " << germes << " yeux]";
}

std::ostream & soup::operator<<(std::ostream & out, const soup::Potatoe& p){
    p.print(out);
    return out;
}
float soup::Potatoe::getPeelingWeight(){
    //return 0.10 * poids + 0.01 * germes;

    float r = this->Vegetable::getPeelingWeight();
    return r + 0.01 * germes;
}

unsigned int soup::Potatoe::getCalories() const{
    return (unsigned int)(poids * 800 - germes * 5);
}


void soup::Soup::add(Vegetable * v){
    legumes.push_back(v);
}

std::ostream & soup::operator<<(std::ostream & out, const soup::Soup & s){
    out << " == Ma soupe au legumes == " << std::endl;
    for(unsigned int i=0; i < s.legumes.size(); i++)
        out << *(s.legumes[i]) << std::endl;
    return out;
}

soup::Soup::~Soup(){
    for (unsigned int i = 0; i < legumes.size(); i++)
        delete legumes[i];
}

float soup::Soup::getPeelingWeight() const{
    float r = 0;

    for(unsigned int i = 0; i < legumes.size(); i++)
        r += legumes[i]->getPeelingWeight();

    return r;
}

unsigned int soup::Soup::getCalories() const{
    unsigned int r = 0;
    for(unsigned int i = 0; i < legumes.size(); i++)
        r += legumes[i]->getCalories();
    return r;
}
