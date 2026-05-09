#include <vector>
#include <iostream>
#include <Compte.hpp>

class Banque
{

    private:
        std::string m_nom; 

        std::vector<Compte*> comptes; 

        int u_numCompte;
    public:

        Banque(std::string nom): m_nom(nom), u_numCompte(0){}

        void ajouterCompte(Compte* compte1);
        
};

