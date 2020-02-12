#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct etudiant{
    char nom[100];
    char prenom [100];
    unsigned int age;
    unsigned int annee;
};
typedef struct etudiant etudiant;

void lire_ligne(char * ch){
    int i = 0;
    char c;

    c = getchar();
    while(c != '\n'){
        ch[i] = c;
        i++;
        c = getchar();
    }
    ch[i] = '\0';

}

void saisie1(etudiant *e){
    printf("Saisir nom : ");
    scanf("%s", e->nom);
    printf("Saisir prénom : ");
    scanf("%s", e->prenom);
    printf("Saisir age : ");
    scanf("%d", &e->age);
    printf("Saisir année d'étude : ");
    scanf("%d", &e->annee);
}


etudiant saisie2(){
    etudiant e;

    printf("Saisir nom : ");
    scanf("%s", e.nom);
    printf("Saisir prenom : ");
    scanf("%s", e.prenom);
    printf("Saisir age : ");
    scanf("%d", &e.age);
    printf("Saisir annee d'etude : ");
    scanf("%d", &e.annee);

    return e;
}

etudiant * saisie3(){
    etudiant * e = (etudiant *) malloc(sizeof(etudiant));

    printf("Saisir nom : ");
    scanf("%s", e->nom);
    printf("Saisir prenom : ");
    scanf("%s", e->prenom);
    printf("Saisir age : ");
    scanf("%d", &e->age);
    printf("Saisir annee d'etude : ");
    scanf("%d", &e->annee);

    return e;
}


void affichage(const etudiant *e){
    printf("Etudiant %s %s, de %d ans en annee %d \n", e->prenom, e->nom, e->age, e->annee);
}


struct duree{
    int heure;
    int minute;
    int seconde;
};
typedef struct duree duree;

duree convert(int ss){
    duree d;
    d.heure = ss / 3600;
    d.seconde = ss % 60;
    d.minute = (ss - d.heure * 3600) / 60;

    return d;
}

int convertSeconde(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}
int convertSeconde2(const duree * d){
    return d->heure * 3600 + d->minute * 60 + d->seconde;
}
int convertSeconde3(duree d){
    return d.heure * 3600 + d.minute * 60 + d.seconde;
}

void ceasar(char * ch, int k){
    int i;

    for(i = 0; i < strlen(ch); i++){
        if(ch[i] >= 'a' && ch[i] <= 'z')
            ch[i] = (ch[i] - 'a' + k) % 26 + 'a';
        else
            if(ch[i] >= 'A' && ch[i] <= 'Z')
                ch[i] = (ch[i] - 'A' + k) % 26 + 'A';
    }
}

int main()
{

    char ch[100] = "Bonjour tout le monde !";
    ceasar(ch, 3);

    printf("ch = '%s' \n", ch);

    ceasar(ch, -3);
    printf("ch = '%s' \n", ch);

    return 0;
}

