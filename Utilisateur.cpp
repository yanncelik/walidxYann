#include <Utilisateur.hpp>
#include <iostream>

Utilisateur::Utilisateur(std::string nom) : m_nom(nom); 

void Utilisateur::ajouterCompte(Compte* compte1)
{

}

void Utilisateur::afficherCompte(){

    int nbCompte = length(Comptes) - 1;

    int choixCompte = 0; 

    do
    {
        choixCompte = 0; 
        
        std::cout<<"vous possédez" << nbCompte <<"!, lequel souhaitez vous consulter ?\n";
        
        std::cin >> choixCompte; 
            
            std::cout << "erreur de saisie ! recommencez\n"; 

    }while(!((choixCompte > 0) && (choixCompte < nbCompte)));

    afficherMensualite(this->Compte[choixCompte]);
        
}