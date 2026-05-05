#include <Compte.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#define Titres 0
#define valeursAff1 1

Compte::Compte(std::string banque, float capital, int nbAn,float taux_annuel) : m_banque(banque), m_capital(capital), m_nbAn(nbAn), m_tauxAnnuel(taux_annuel)
{ 
}

void Compte::initAffichage1()
{
    //titres 
    //tableauAffichage1.push_back("Banque");
    tableauAffichage1.push_back(std::vector<std::string>{"Banque","",""});
    tableauAffichage1.emplace(tableauAffichage1.begin() + 1, std::vector<std::string>{"Taux prêt","",""});
    //tableauAffichage1[2][Titres].push_back("Durée prêt");
    tableauAffichage1.emplace(tableauAffichage1.begin() + 2, std::vector<std::string>{"Durée prêt","",""});

    std::cout<<"nbLignes : "<<  tableauAffichage1.size()<<std::endl;
    /*
    tableauAffichage1[0][valeursAff1].push_back(m_banque);
    tableauAffichage1[1][valeursAff1].push_back(std::to_string(m_tauxAnnuel));
    tableauAffichage1[2][valeursAff1].push_back(std::to_string(m_nbAn));
    */

}

void Compte::initAffichage2()
{
    /*
    //titres 
    tableauAffichage1[Titres][0].push_back("Annee");
    tableauAffichage1[Titres][1].push_back("Somme à rembourser");
    tableauAffichage1[Titres][2].push_back("Interêts versés");
    
    for(int i = 0; i < nbAn; i++)
    {
        tableauAffichage1[i][0].push_back(std::to_string(i));
        tableauAffichage1[i][1].push_back(std::to_string(somme_restante[i]));
        tableauAffichage1[i][2].push_back(std::to_string(interet_Annuel[i])); 
    }
    */
}

void Compte::initAffichage3()
{
    /*
    tableauAffichage1[Titres][0].push_back("Capital");
    tableauAffichage1[Titres][1].push_back("Intérêts totaux du prêt");
    tableauAffichage1[Titres][2].push_back("total");
    
    tableauAffichage1[2][0].push_back(std::to_string(m_capital));
    tableauAffichage1[2][1].push_back(std::to_string(interetEuroTotal));
    tableauAffichage1[2][2].push_back(std::to_string(m_capital+interetEuroTotal));
    
    */
}

void Compte::calculerMensualite()
{

    somme_Annuelle = m_capital/m_nbAn;

    m_mensualite = somme_Annuelle/12;

    somme_restante[0] = somme_Annuelle; 

    for(int i = 0; i < m_nbAn; i++)
    {
        
        interet_Annuel[i] = somme_restante[i] * m_tauxAnnuel;

        if(i < m_nbAn)
            somme_restante[i+1] = somme_restante[i] - somme_Annuelle;

        interetEuroTotal += interet_Annuel[i];
    }
}

void Compte::afficherInterface()
{
    this->calculerMensualite();
    this->initAffichage1();

    std::cout << "ENTREZ :\n\t1 : Infos contrat\t2 : Prêt et Intérêts remboursés par année\t 3 : resultat final\n";  

    int saisie; 

    std::cin >> saisie;

    switch(saisie)
    {
        
        case 1:  
        this->afficherContrat();
        break;
        
        case 2: 
        this->afficherRemboursements();
        break;
        
        case 3:
        this->afficherValeursTotales();
        break;
        
        default: 
        std::cout<<"erreur de saisie"<<std::endl;
    }
}

void Compte::afficherPage(std::vector<std::vector<std::string>>& tableau)
{
    system("clear");

    for(int i = 0; i < tableau.size(); i++)
    {
        for(int j = 0; j < tableau[i].size(); j++)
        {
            for(int k = 0; k < (tableau[i][j].size()); k++){
                std::cout <<"_";
            }
        }
    }
    std::cout<<std::endl;
    
    for(int i = 0; i < tableau.size(); i++)
    {

        for(int j = 0; j < tableau[i].size(); j++)
        {
            std::cout<< tableau[i][j] <<"\t"; 
        }
    }
}

void Compte::afficherContrat()
{
    this->afficherPage(tableauAffichage1);

    std::cout<<"\n\n\n\t\t\t 'n' >> page suivante";
}

void Compte::afficherRemboursements()
{
    this->afficherPage(tableauAffichage2);

    std::cout<<"\n\n\n page précédente << 'p'\t\t\tpage suivante >> 'n'";
}

void Compte::afficherValeursTotales()
{
    this->afficherPage(tableauAffichage3);

    std::cout<<"\n\n\n page précédente << 'p'";
}


void Compte::initNumCompte(int nbCompte)
{
    this->UserAccID = nbCompte;
} 