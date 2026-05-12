#include <Compte.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#define Titres 0
#define valeursAff1 1

Compte::Compte(int banque, float capital, int nbAn,float taux_annuel) : m_banque(banque), m_capital(capital), m_nbAn(nbAn), m_tauxAnnuel(taux_annuel)
{ 

    std::string groupe2 = "Walid et Yann";
    
    std::string banqueToString = getBankToString(banque);

    calculerMensualite();

    this->ajouterResultatCSV(groupe2, (double)capital, banqueToString, (double)taux_annuel, nbAn, (double)(this->interetEuroTotal));
}

void Compte::initAffichage1() //test
{
    //titres 
    //tableauAffichage1.push_back("Banque");
    tableauAffichage1.push_back(std::vector<std::string>{"Banque","",""});
    tableauAffichage1.emplace(tableauAffichage1.begin() + 1, std::vector<std::string>{"Taux pret","",""});
    //tableauAffichage1[2][Titres].push_back("Durée prêt");
    tableauAffichage1.emplace(tableauAffichage1.begin() + 2, std::vector<std::string>{"Duree pret","",""});

    //std::cout<<"nbLignes : "<<  tableauAffichage1.size()<<std::endl;
    
    tableauAffichage1[0][1] = std::to_string(m_banque);
    tableauAffichage1[1][1] = std::to_string(m_tauxAnnuel);
    tableauAffichage1[2][1] = std::to_string(m_nbAn);
    

}

void Compte::initAffichage2()
{

    //titres 
    tableauAffichage2.push_back(std::vector<std::string>{"Annee"});
    tableauAffichage2.emplace(tableauAffichage2.begin() + 1, std::vector<std::string>{"Somme a rembourser"});
    tableauAffichage2.emplace(tableauAffichage2.begin() + 2, std::vector<std::string>{"Interets verses"});
    
    for(int i = 0; i < m_nbAn; i++)
    {
        tableauAffichage2[0].push_back(std::to_string(i));
        tableauAffichage2[1].push_back(std::to_string(somme_restante[i]));
        tableauAffichage2[2].push_back(std::to_string(interet_Annuel[i])); 
    }

}

void Compte::initAffichage3()
{
    
    tableauAffichage3.push_back(std::vector<std::string>{"Capital", "", ""});
    tableauAffichage3.emplace(tableauAffichage3.begin() + 1, std::vector<std::string>{"Interets totaux du pret", "", ""});
    tableauAffichage3.emplace(tableauAffichage3.begin() + 2, std::vector<std::string>{"Remboursement total", "", ""});
    
    tableauAffichage3[0].push_back(std::to_string(m_capital));
    tableauAffichage3[1].push_back(std::to_string(interetEuroTotal));
    tableauAffichage3[2].push_back(std::to_string(m_capital+interetEuroTotal));
}

void Compte::calculerMensualite()
{
    //std::cout << "calculer mensualite est appelee" << std::endl; 

    somme_Annuelle = m_capital/m_nbAn;

    m_mensualite = somme_Annuelle/12;

    somme_restante[0] = m_capital; 

    for(int i = 0; i < m_nbAn; i++)
    {
        
        interet_Annuel[i] = somme_restante[i] * (m_tauxAnnuel / 100);

        if(i < (m_nbAn - 1))
            somme_restante[i+1] = somme_restante[i] - somme_Annuelle;

        interetEuroTotal += interet_Annuel[i];
    }

    //this->afficherDonnees();
}

void Compte::afficherInterface()
{
    this->calculerMensualite();

    this->initAffichage1();
    this->initAffichage2();
    this->initAffichage3();

    std::cout << "ENTREZ :\n\t1 : Infos contrat\t2 : Prêt et Intérêts remboursés par année\t 3 : resultat final\n" << std::endl;  

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

    /*                              VERSION AFFICHAGE EN LIGNE 
    std::vector <int> taillesMax;
    
    int tailleMax = 0; 

    int tailleTot = 0;

    int i = 0;

    for(int j = 0; j < tableau[0].size(); j++) // i lignes 
    {
        tailleMax = 0; 

        for(int i = 0; i < tableau.size(); i++) //j colonnes 
        {

            if(tableau[i][j].size() > tailleMax) //recup. l'élément le plus grande de la colonne 
                tailleMax = tableau[i][j].size(); 
        }

        tailleTot += tailleMax; //somme des éléments les + grands de chaque colonne 
        taillesMax.push_back(tailleMax); 
        tailleMax = 0;
    }
    tailleTot += (((tableau[0].size()) - 1) * 9); //nbElemLigne0 * 9 = '_' entre les éléments

    for(int k = 0; k < tailleTot; k++) //affichage de la bordure sup 
    {
        std::cout<<"_";
    }
    */
    std::vector<int> taillesMax;

    int tailleMax = 0;
    int tailleTot = 0;

    // maintenant on calcule la taille max par COLONNE affichée
    for(int i = 0; i < tableau.size(); i++)
    {
        tailleMax = 0;

        for(int j = 0; j < tableau[i].size(); j++)
        {
            if(tableau[i][j].size() > tailleMax)
                tailleMax = tableau[i][j].size();
        }

        tailleTot += tailleMax;
        taillesMax.push_back(tailleMax);
    }

    tailleTot += ((tableau.size() - 1) * 9);

    for(int k = 0; k < tailleTot; k++)
    {
        std::cout << "_";
    }

    std::cout << std::endl; //saut de ligne pour afficher le contenu 
    /*
    for(int a = 0; a < taillesMax.size(); a++)
    {
        std::cout << "tailleMax de " << a << " : " << taillesMax[a];
        
        std::cout <<"tailleElement" << tableau[0][a].size();
    }
    */
    
    std::cout << std::endl; 
    /*
    for(i = 0; i < tableau.size(); i++) //i lignes 
    {
        for(int j = 0; j < tableau[i].size(); j++) //j colonnes 
        {
            std::cout<< tableau[i][j];
            
            int tailleElement = tableau[i][j].size(); 
            
            for(int k = 0; k < (taillesMax[j] - tailleElement); k++) //on réduit l'écart entre les grands et petits éléments
            {
                std::cout <<" ";
            }     
            
            if(tableau[i][j].size() > 0)
            std::cout<< "|   ";
        }
        std::cout << std::endl;
    }
    */

    for(int j = 0; j < tableau[0].size(); j++) // colonnes
    {
        for(int i = 0; i < tableau.size(); i++) // lignes
        {

            std::cout << tableau[i][j];

            int tailleElement = tableau[i][j].size();

            for(int k = 0; k < (taillesMax[i] - tailleElement); k++)
            {
                std::cout << " ";
            }

            if(tableau[i][j].size() > 0)
                std::cout << "|   ";
        }

        std::cout << std::endl;
    }
}

void Compte::afficherContrat()
{
    this->afficherPage(this->tableauAffichage1);

    std::cout<<"\n\n\n\t\t\t 'n' >> page suivante\t";

    std::cout <<"\n\n  'x' : sortie ";

    char saisie = '0';

    do 
    {
        std::cin >> saisie; 
    }while(!((saisie == 'n') || (saisie == 'x')));

    system("clear");

    if(saisie == 'n')
        this->afficherRemboursements();
}

void Compte::afficherRemboursements()
{
    char saisie; 

    this->afficherPage(this->tableauAffichage2);

    std::cout<<"\n\n\n page précédente << 'p'\t\t\tpage suivante >> 'n'";

    std::cout <<"\n\n  'x' : sortie ";

        do 
    {
        std::cin >> saisie; 
    }while(!((saisie == 'n') || (saisie == 'p') || (saisie == 'x')));

    system("clear");

    if(saisie == 'n')
        this->afficherValeursTotales();

    if(saisie == 'p')
        this->afficherContrat();
}

void Compte::afficherValeursTotales()
{

    char saisie; 

    this->afficherPage(this->tableauAffichage3);

    std::cout<<"\n\n\n page précédente << 'p'";

    std::cout <<"\n\n  'x' : sortie ";

    do 
    {
        std::cin >> saisie; 
    }while(!((saisie == 'p') || (saisie == 'x')));

    system("clear");

    if(saisie == 'p')
        this->afficherRemboursements();
}


void Compte::initNumCompte(int nbCompte)
{
    this->UserAccID = nbCompte;
} 

void Compte::afficherDonnees()
{
    std::cout <<"affichage des donnees : " <<std::endl;
    
    std::cout <<"capital : " << m_capital << std::endl; 
    
    std::cout <<"mensualites : " << m_mensualite << std::endl; 
    
    std::cout <<"nbAn : " << m_nbAn << std::endl; 
    
    std::cout <<"somme annuelle : " << somme_Annuelle << std::endl;
    
}

void Compte::ajouterResultatCSV(std::string groupe,
                        double capital,
                        std::string banque,
                        double taux,
                        int duree,
                        double resultat) 
{

    std::ifstream testFile("banques.csv");
    bool fichierExiste = testFile.good();
    testFile.close();

    std::ofstream file("banques.csv", std::ios::app);

    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return;
    }

    if (!fichierExiste) {
        file << "GROUPE;CAPITAL;BANQUE;TAUX;DUREE;RESULTAT\n";
    }

    file << groupe << ";"
         << std::fixed << std::setprecision(2)
         << capital << ";"
         << banque << ";"
         << taux << ";"
         << duree << ";"
         << resultat << "\n";

    file.close();
}

std::string Compte::getBankToString(int banque)
{
    //(CA = 1, CM = 2, LCL = 3, BNP = 4)
    std::string tempBanque; 

    switch(banque)
    {
        case 1:
            tempBanque = "CA";
            break; 

        case 2:
            tempBanque = "CM";
            break; 

        case 3:
            tempBanque = "LCL";
            break; 

        case 4:
            tempBanque = "BNP";
            break; 
    }

    return tempBanque; 
}