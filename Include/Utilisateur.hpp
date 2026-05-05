#include <vector>
#include <iostream>
#include <Compte.hpp>

class Utilisateur
{

    private:    
        std::vector<std::vector<std::string>> data;

        std::vector<Compte*> comptes;

        std::string m_nom; 

        int u_numCompte; 

    public: 

        Utilisateur(std::string nom) : m_nom(nom){}

        void ajouterCompte(Compte *compte1);

        void ChoisirCompte();

        std::string getUserName();

};