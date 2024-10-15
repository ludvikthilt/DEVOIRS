/*
Maison du bandit
situation pb: Il vous est demandé de calculer les coordonnées de la demeure d'un brigand ayant 
sévit à trois endroit distinct donc vous connaissez les coordonnées de geolocalisation
solution : 
- triangulation de delaunay : methode traçant des zone triangulaire a linterieure d'une zone
elle mm triangulaire contenant les points (extrement complexe)
- centroide : (approximative) mais simple (probable que la zone à plus forte pondération de 
la méthode de delaunay contiennent le centroide ou qu'elle n'en soit pas éloigné)
    
*/

#include <iostream>//bibliothèque de gestion des entrées sorties


using namespace std;//Rend les éléments de l'espace de nom std accessible directement 



void localisation(float x1, float x2, float x3, float y1, float y2, float y3 ); //prototype de la fonction de calcul de la localisation


int main(int argc, char** args){
    float x1, x2, x3 , y1, y2, y3;
    // collecte des coordonées des points
    cout<<""<<endl;
    cout << "_______________LOCALISATION_______________"<<endl;
    cout << "\tEntrer les coordonnées des points"<< endl;
    cout << "\tpoint 1"<< endl;
    cout << "\t x"<< endl;
    cin >> x1 ;
    cout << "\t y"<<endl;
    cin >> y1;
    cout << "\tpoint 2"<< endl;
    cout << "\t x"<< endl;
    cin >> x2 ;
    cout << "\t y"<<endl;
    cin >> y2;
    cout << "\tpoint 3"<< endl;
    cout << "\t x"<< endl;
    cin >> x3 ;
    cout << "\t y"<<endl;
    cin >> y3;
    cout<<""<<endl;

    // affichage des résultats 
    localisation(x1,x2,x3,y1,y2,y3);
   

}

// implémentation de la fonction de calcul de la localisation
void localisation (float x1, float x2, float x3, float y1, float y2, float y3){
    
    float centre_x = (x1 + x2 + x3)/3;
    float centre_y = (y1 + y2 + y3)/3;

     cout <<"la position estimee du bandit a pour coordonnee"<< "\tx :>"<< centre_x<< "\ty :>"<< centre_y << endl;
     cout<<""<<endl;
    
}



