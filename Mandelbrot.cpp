/*
La fractale de Mandelbrot est un ensemble de nombre complexes définie par la suite complexe :
    |    z(0) appartient à l'ensembles des nombres complexes
    |    z(n+1) = z(n)^2 + c ; où c est une constante complexe
Sa particularité est que pour qu'un élément C appartienne à l'ensemble il faudrait que le module de z soit <= 2
après un certain nombre d'itérations
ie pour C appartenant  à l'ensemble de MB on a: |z(0)| <= 2 && |z(n)|<= 2 donc que la suite soit majorée par 2
*/

#include <iostream> //bibliothèque de gestion des entrées sorties

using namespace std ;//Rend les éléments de l'espace de nom std accessible directement 

bool in_mandelbrot_fractal(double realz, double imagz );// prototype de la fonction d'appartenance à la suite definissant la fractale

double next_real_term(double realz, double imagz, double realc);// ----//---- calcul du terme suivant de la suite 

double next_imaginary_term(double realz, double imagz, double imagc);

void print_terms(double realz0, double imagz0, double realc , double imagc, int iterations );// ----//----- affichage des termes et des analyses 

int main(int argc, char** args){
    double realz0 , imagz0 ;
    double realc , imagc ;
    unsigned  int iterations = 0 , i = 0 ;
   
    cout<<""<<endl;
    cout <<"\t_______________ELEMENTS DE LA FRACTALE DE MANDELBROT_______________"<< endl;
    // collecte du premier élément de l'ensemble z(0)
    cout << "\t \tEntrer le complexe z_0"<< endl;
    cout << "\tPartie reelle " << endl;
    cin >> realz0 ;
    cout << "\tPartie imaginaire"<< endl;
    cin >> imagz0;

    

    //collecte du terme constant C de la suite 
    cout << "\t \tEntrer le complexe c"<< endl;
    cout << "\tPartie reelle" << endl;
    cin >> realc ;
    cout << "\tPartie imaginaire" << endl;
    cin >> imagc;
    

    //defintion du nombre d'iteration
    cout <<" \tEntrer l'indice du dernier element de la suite a afficher(nombre d'iterations soustrait de 1)"<< endl;
    cin >> iterations ;
    cout<<""<<endl;
    //affichage des résultats
    print_terms(realz0,imagz0,realc,imagc,iterations);
    cout<<""<<endl;

    return 0;
}

// implementation de la fonction de verification d'appartenance à l'ensemble
bool in_mandelbrot_fractal(double realz, double imagz){
    return realz * realz + imagz * imagz <= 4.0f ;
}

// implemantation de la fonction de calcul du terme suivant
double next_real_term(double realz, double imagz, double realc){
    realz = realz * realz - imagz * imagz + realc;
    return realz ;
}

double next_imaginary_term(double realz, double imagz, double imagc){
    imagz = 2 * realz * imagz + imagc ;
    return imagz ;
}
// -----//----- affichage des resultats et analyses 
void print_terms(double realz0, double imagz0, double realc , double imagc, int iterations){
    double realz = realz0 ;
    double imagz = imagz0 ;
    unsigned i = 0 ;

    while (in_mandelbrot_fractal(realz,imagz) && i <= iterations ){
        cout << "Element>" << i << " = "<< realz<<" + ("<<imagz<<"i)"<< endl;
        realz = next_real_term(realz,imagz,realc);
        imagz = next_imaginary_term(realz,imagz,imagc);
        i++ ;
    }
    if (! in_mandelbrot_fractal(realz,imagz)){
        cout<<""<<endl;
        cout<< "La suite semble diverger a partir de l'element:>  "<< i << "\nDonc "<<  realc<<" + ("<<imagc<< "i) n'appartient pas a la fractale de Mandelbrot"<<endl; 
    }else{
        cout<<""<<endl;
        cout << "La suite semble toujours converger apres "<< iterations <<" iterations"<< "\nDonc "<<realc<<" + ("<<imagc <<"i) peut appartenir a la fractale de Mandelbrot"<<endl; 
    }

}
