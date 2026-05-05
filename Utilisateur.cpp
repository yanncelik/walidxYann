#include <Utilisateur.hpp>
#include <iostream>
#include <vector>

 

void Utilisateur::ajouterCompte(Compte* compte1)
{

    int nbComptes = 0; 
    //partage le contrôle de l'objet compte à son utilisateur 
    this->comptes.push_back(compte1);

    //défini le numéro de compte à partir de son ordre de création 
    nbComptes = comptes.size();
    compte1->initNumCompte(nbComptes);
    this->u_numCompte = nbComptes; 
}


void Utilisateur::ChoisirCompte(){

    //choix du numéro de compte pour l'utilisateur 
    
    int choixCompte = 0; 

    int choixOk = 0; 
    do
    {
        choixCompte = 0; 
        
        std::cout<<"vous possédez " << this->u_numCompte <<" compte(s) !, lequel souhaitez vous consulter ?\n";
        
        std::cin >> choixCompte; 

        if(!((choixCompte > 0) && (choixCompte < ((this->u_numCompte)+1))))
        {
            std::cout << "erreur de saisie ! recommencez\n"; 
            choixOk = 0;
        }

        else{choixOk = 1;}

    }while(choixOk != 1);

    Compte* choix = this->comptes[choixCompte - 1]; //récupération du compte dans le tableau appartenant a la classe

    choix->afficherInterface();
        
}


std::string Utilisateur::getUserName()
{
    std::string nom = this->m_nom;

    return nom;
}

