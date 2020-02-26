#include <stdio.h>
#include <stdlib.h>

struct Tab{
    int *p;
    int M;
    int N;
};
typedef struct Tab Tab;

void init(Tab * t, int nb){
    t->p = (int *) calloc(nb, sizeof(int));
    t->M = nb;
    t->N = 0;
}

void destroy(Tab * t){
    free(t->p);
    t->p = NULL;
    t->M = 0;
    t->N = 0;
}

int add(Tab * t, int elem){
    if( (t->N == t->M) || (t->p == NULL) ) // tab saturé
        return -1;
    else{
        int i;

        for(i = t->N-1; (i >= 0) && (t->p[i] > elem); i--)
            t->p[i + 1] = t->p[i];
        t->p[i + 1] = elem;
        t->N ++;
        return 0;
    }
}

void print(const Tab * t){
    printf("Tableau de %d elements : %d sont utilises\n", t->M, t->N);
    int i;
    for (i = 0; i < t->N; i++)
        printf("%d ", t->p[i]);
    printf("\n");
}

int del(Tab * t, int ind){
    if((ind < 0) || (ind >= t->N))
        return -1;
    else{
        int i;
        for(i = ind+1; i < t->N; i++)
            t->p[i-1] = t->p[i];
        t->N--;
        return 0;
    }
}

unsigned int max1(int tab[], int size){
    int i, j = 0;
    for(i = 1; i < size; i++)
        if( tab[j] < tab[i] )
            j = i;
    return j;
}
unsigned int max2(int *tab, int size){
    int i, j = 0;
    for(i = 1; i < size; i++)
        if( *(tab+j) < *(tab+i) )
            j = i;
    return j;
}

int somme1(int tab[], int size){
    int i, s = 0;
    for(i = 0; i < size; i++)
        s += tab[i];
    return s;
}
int somme2(int tab[], int size){
    int i, s = 0;
    for(i = 0; i < size; s += tab[i], i++);
    return s;
}

int somme3(int tab[], int debut, int fin){
    if(fin < debut)
        return 0;
    else
        if(fin == debut)
            return tab[fin];
        else {  // cas général  !!
            int m = (debut + fin)/2;
            int s1 = somme3(tab, debut, m); // somme 1ere partie
            int s2 = somme3(tab, m+1, fin); // somme 2eme partie
            int s = s1 + s2;
            return s;
        }
}

int somme4(int * debut, int * fin){
    if(fin < debut)
        return 0;
    else
        if(fin == debut)
            return *fin;
            // fin[0]
        else {  // cas général  !!
            //printf("%d \n" , (fin - debut)/2);
            int *m = debut + (fin - debut)/2;
            int s1 = somme4(debut, m); // somme 1ere partie
            int s2 = somme4(m+1, fin); // somme 2eme partie
            int s = s1 + s2;
            return s;
        }
}

int main()
{

    Tab t;
    init(&t, 10);

    add(&t, 0);
    add(&t, 10);
    add(&t, 5);
    add(&t, 30);
    add(&t, 23);

    print(&t);

    del(&t, 2);
    del(&t, 1);
    print(&t);
}

