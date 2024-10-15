/*
La suite de fibonacci est une suite où le n-ième terme est égal à :
La somme des 2 éléments précédents 
cad  n = (n - 1) + (n - 2)
*/



#include <iostream>//bibliothèque de gestion des entrées sorties 

using namespace std ;//Rend les éléments de l'espace de nom std accessible directement 

unsigned int fibonacci ( unsigned int n ) ;//prototype de la fonction pour calculer un n-ième éléments de la suite de fibonacci

void print_terms(unsigned int index_of_the_last_element, unsigned int element_of_the_sequence);//affichage des éléments de la suite
    
int main(int argc, char** args){
    unsigned int element_of_the_sequence = 0 ; //element de la suite 
    unsigned int index_of_the_last_element = 0; //nombre d'itérations de la suite 
    
    cout<<""<<endl;
    cout << "\t______________CALCUL DES TERMES DE LA SUITE DE FIBONNACCI_______________" <<endl ; //collecte des informations
    cout << "\tEntrer l'indice du dernier terme de la suite a afficher(nombre d'iteration soustrait de 1)" << endl ;
    cin >> index_of_the_last_element ;
    cout <<"\tElements de la suite"<< endl;
    cout<<""<<endl;
    //affichage des éléments de la suite
    print_terms( index_of_the_last_element, element_of_the_sequence);
    cout<<""<<endl;
}
// implémentation de la fonction de calcul d'un n-ième élément
unsigned int fibonacci ( unsigned int n ){
    if ( n == 0 || n == 1 ){
        return 1 ;
    }else{
        unsigned int result( fibonacci( n - 1 ) + fibonacci( n - 2 )) ;
        return result ;
    }
}
// impementation de l'affichage des éléments 
void print_terms(unsigned int index_of_the_last_element, unsigned int element_of_the_sequence){
    for (unsigned int i = 0 ; i <= index_of_the_last_element ; i++ ){
        element_of_the_sequence = fibonacci(i) ; 
        cout << "\t \t___ " << element_of_the_sequence << " ___"<< endl;
    }
}