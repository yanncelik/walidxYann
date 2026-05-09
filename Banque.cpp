#include <iostream>
#include <Banque.hpp>
#include <vector>

void Banque::ajouterCompte(Compte* compte1)
{
    //partage le contrôle de l'objet compte à son utilisateur 
    this->comptes.push_back(compte1);

    //défini le numéro de compte à partir de son ordre de création 
    int nbComptes = (this->comptes.size()); 
    this->u_numCompte = nbComptes; 
}
