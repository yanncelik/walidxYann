#include <iostream>

    struct calc{
        float calcul1;
        float calcul2;
        float calcul3;
    };

    void initValeurs(float mensualite, float capital); 

    float CalculerMensualite(calc *calcUN, float mensualite, float capital, float taux_annuel, int nbAn); 

    void afficherMensualite(float mensualite);
int main(){
    
    calc calcUN; 

    //decla variables 

    float mensualite, capital;
    
    float taux_annuel;

    int nbAn; 

    //getters 

    std::cout << "montant du capitale emprunte\n" << std::endl;
    
    std::cin >>capital; 

    std::cout << "Nombre d'années : \n"; 

    std::cin >> nbAn; 

    std::cout << "Taux annuel (ex : 5,5 pourcent)\n";

    std:: cin >> taux_annuel;

    mensualite = CalculerMensualite(&calcUN, mensualite, capital, taux_annuel, nbAn); 

    afficherMensualite(mensualite); 

    std::cout<< "calcul1 : " << calcUN.calcul1 << "calcul2 : " << calcUN.calcul2 << "calcul3 : " << calcUN.calcul3 << std::endl; 
    //calcul 

   

    return 0; 
}

float CalculerMensualite(calc *calcStruct, float mensualite, float capital, float taux_annuel, int nbAn){

    int nbMois;

    float taux_mensuel;

    taux_mensuel = (taux_annuel/100)/12;

    calcStruct->calcul1 = capital * taux_mensuel;

    calcStruct->calcul2 = (1 + taux_mensuel)*nbMois;

    calcStruct->calcul3 = calcStruct->calcul2 - 1;

    mensualite = calcStruct->calcul1 * (calcStruct->calcul2 / calcStruct->calcul3);

    return mensualite; 
}

void afficherMensualite(float mensualite){

    std::cout << "mensualite : " << mensualite <<std::endl; 

    getchar(); 

    getchar();
}