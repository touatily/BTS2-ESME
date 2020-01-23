#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED

#include<iostream>
#include<vector>

namespace soup {

    class Vegetable{

        friend std::ostream & operator<<(std::ostream & out, const Vegetable& v);
        virtual void print(std::ostream & out) const;

        static float epluchure;

    protected:
        float poids;


    public:

        Vegetable();
        Vegetable(float p);
        virtual float getPeelingWeight();
        static void setPeelingWeight(float e);
        virtual unsigned int getCalories() const = 0;

        virtual ~Vegetable();
    };



    class Carrot : public Vegetable{
        // par défaut c'est privé !
        float longueur;
        void print(std::ostream & out) const;

        friend std::ostream & operator<<(std::ostream & out, const Carrot& c);
    public:

        Carrot();
        Carrot(float p, float l);
        float getPoids() const;
        float getLongueur() const;
        unsigned int getCalories() const;
    };





    class Potatoe: public Vegetable{
        // par défaut c'est privé !
        unsigned int germes;
        void print(std::ostream & out) const;

        friend std::ostream & operator<<(std::ostream & out, const Potatoe& p);
    public:

        Potatoe();
        Potatoe(float p, unsigned int g);
        Potatoe(float p);
        float getPoids() const;
        unsigned int getGermes() const;

        float getPeelingWeight();
        unsigned int getCalories() const;
    };


    class Soup{
        std::vector<Vegetable *> legumes;
        friend std::ostream & operator<<(std::ostream & out, const Soup & s);
    public:
        void add(Vegetable * v);
        float getPeelingWeight() const;

        unsigned int getCalories() const;

        ~Soup();  // faire attention

    };


}

#endif // DECLARATIONS_H_INCLUDED
