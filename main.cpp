#include <iostream>
#include <Utilisateur.hpp> 
#include <Banque.hpp>
#include <Compte.hpp> 
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <unistd.h>

#define totLen 100 

    //void initValeurs(float mensualite, float capital); 

    //float CalculerMensualite(calc *calcUN, float mensualite, float capital, float taux_annuel, int nbAn); 

    //void afficherMensualite(float mensualite);

    /*
    */

    void addUser(Utilisateur** user, std::string prevUser = ""); //objet utilisateur)

    Compte*  addAccount(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab, int idBanque = 0, float capital = 0, int nbAn = 0, float taux_annuel = 0, std::string nom = "");

    void afficherCompte(std::vector<Utilisateur*> &userTab);

    Utilisateur* chercherUtilisateur(std::vector<Utilisateur*> &userTab, std::string nom);

    void recupUtilisateur(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab);
int main()
{
    system("clear");

    std::vector<Utilisateur*> userTab; 

    Compte *Compte1 = nullptr; 
    
    Banque* CA = new Banque("credit agricole");
    Banque* CM = new Banque("credit mutuelle");
    Utilisateur *user1 = nullptr;
    Banque* LCL = new Banque("LCL");
    Banque* BNP = new Banque("BNP");

    std::vector<Banque*> BankTab = {CA, CM, LCL, BNP};

    recupUtilisateur(userTab, BankTab);

    while(1)
    {
        std::cout << "\n 1 : ajouter un utilisateur , 2 : creer un compte, 3 : afficher un compte, 4 : sortie\n" << std::endl; 
        
        std::cout << "\tchoix : ";

        int saisie = 0;

        while(!(std::cin >> saisie))
        {

            std::cout <<"\nentrez une saisie correcte !" <<std::endl;

            sleep(3);

            system("clear");

           std::cout << "\n 1 : ajouter un utilisateur , 2 : creer un compte, 3 : afficher un compte, 4 : sortie\n" << std::endl; 
        
            std::cout << "\tchoix : ";

            std::cin.clear(); // enlève l'état d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // vide le buffer
        }
        while(saisie == 0);
        
        std:: cout << std::endl;

        if(saisie == 1)
        {
            addUser(&user1);
            userTab.push_back(user1);
            
        }
        
        if(saisie == 2)
        {
            Compte1 = addAccount(userTab, BankTab);

            if(Compte1 == NULL)
            {
                std::cout << "erreur ajout"<<std::endl; 
            }
            
        }
        
        if(saisie == 3)
        {
            afficherCompte(userTab);
        }
        
        if(saisie == 4)
        {
            break;
        }

    }
        

    return 0; 
}

void addUser(Utilisateur** user1, std::string prevUser)
{ 

    if(prevUser.empty())
    {   
        
        std::cout << "entrez votre nom\n\t" << std::endl;
        
        std::cin >> prevUser; 

        system("clear");

        std::cout << "utilisateur ajouté ! : " << prevUser << "\n" << std::endl;
    }    
    
    *user1 = new Utilisateur(prevUser); //objet utilisateur

    //(*user1)->existe();
        
}



Compte* addAccount(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab, int idBanque, float capital, int nbAn, float taux_annuel, std::string nom)
{
    Utilisateur* currentUser = chercherUtilisateur(userTab, nom);

    if(currentUser == NULL)
    {
        return NULL;
    }


    Compte* compte = nullptr; 

    //Creation du compte    

    std::string banque; 

    if(idBanque == 0)
    {
        do
        {
            std::cout << "chez quel banque souhaitez vous devenir adhérent (CA = 1, CM = 2, LCL = 3, BNP = 4)\n" << std::endl;

            std::cin >> idBanque; 

        }while((idBanque <= 0) || (idBanque > 4)); 
            
        do
        {
            std::cout << "montant du capitale emprunte ? : \n" << std::endl;
            
            std::cin >>capital; 

        }while(capital <= 0);
        
        do
        {
            std::cout << "Nombre d'années ? (10, 15 ou 20 ans) : \n"; 
            
            std::cin >> nbAn; 
        }while(!((nbAn == 10) || (nbAn == 15) || (nbAn == 20)));
            
        do
        {
            std::cout << "Taux annuel (3 ou 4 %) ? : \n";
            
            std::cin >> taux_annuel;
            
        }while(!((taux_annuel == 3) || (taux_annuel == 4)));

        std::ofstream file("donnees.txt", std::ios::app);   

        file <<'\n';

        file << currentUser->getUserName(); 

        file << " " << idBanque;

        file << " " << capital; 

        file << " " << nbAn;

        file << " " << taux_annuel; 

        file.close();
        
    }
        
    compte = new Compte(idBanque, capital, nbAn, taux_annuel);
    

    //std::cout << "valeur idBanque" <<idBanque << std::endl;
    //enregistrement de l'objet compte auprès de l'objet banque correspondant 
    switch(idBanque)
    {
        case 1:
            BankTab[0]->ajouterCompte(compte); 
            break;
        case 2:
            BankTab[1]->ajouterCompte(compte);
            break;
        case 3:
            BankTab[2]->ajouterCompte(compte);
            break;
        case 4:
            BankTab[3]->ajouterCompte(compte);
            break;
        
        default:
            std::cout<<"erreur de saisie\n";
    }    

    currentUser->ajouterCompte(compte);

    return compte; 

}

void afficherCompte(std::vector<Utilisateur*> &userTab)
{
        Utilisateur* currentUser = chercherUtilisateur(userTab, "");

        if(currentUser == NULL)
        {
            std::cout <<"erreur recup utilisateur";
            return; 
        }
        //on affiche le compte de l'utilisateur qui a été trouvé 
        currentUser->ChoisirCompte();
}

Utilisateur* chercherUtilisateur(std::vector<Utilisateur*>& userTab, std::string utilisateur)
{
        Utilisateur* currentUser = NULL; 

        if(utilisateur.empty())
        {            
            std::cout << "entrez le nom de l'utilisateur : ";

            std::cin >> utilisateur; 

            std::cout << std::endl; 

            system("clear");
        }

        int tailleTab = 0;

        tailleTab = userTab.size(); 

        //std::cout << "taille de userTab : " << tailleTab << std::endl;

        if(!(tailleTab == 0))
        {
            //std::cout <<"passage dans la fonction" << std::endl; 

            //recherche par nom dans tous les objets Utilisateur 
            for(int i = 0; i < tailleTab; i++)
            {   
                //if(utilisateur == userTab[i]->m_nom)
                if(utilisateur == (userTab[i]->getUserName()))
                {
                    std::cout <<" 1 utilisateur récupéré : " << userTab[i]->getUserName() << "\n" << std::endl;

                    currentUser = userTab[i];

                    //pas de réponse retournée 
                    if(currentUser == NULL)
                        std::cout <<"attention, erreur de recup. de l'utilisateur ! \n";

                    return currentUser;
                }
                /*
                std::cout<< "utilisateurs :";
                
                for(int i = 0; i < tailleTab; i++)
                {
                    std::cout << userTab[i]->getUserName() << std::endl;
                }
                */
                //si réponse, on sort de la boucle 
            }
            system("clear");
            std::cout << "aucun utilisateur n'a ete trouve :/, ";

        }
        
        return NULL;
}

void recupUtilisateur(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab) //lit dans un fichier les utilisateurs déjà enregistrés
{ 

    Utilisateur* prevUser = nullptr; 

    std::string nom; 
    int banque;
    float capital = 0; 
    int annees = 0;
    float taux_annuel = 0; 

    std::ifstream file("donnees.txt");   

    while(file >> nom)
    {
        file >> banque; 

        file >> capital;

        file >> annees; 

        file >> taux_annuel;
        
        addUser(&prevUser, nom);

        userTab.push_back(prevUser);

        prevUser = nullptr; 

        Compte *Compte1 = addAccount(userTab, BankTab, banque, capital, annees, taux_annuel, nom);
        /*
        std::cout<<"Données récupérées :"<<std::endl;
        
        std::cout<<"nom : "<<nom;
        std::cout<<"\nbanque : "<<banque;
        std::cout<<"\ncapital : "<<capital;
        std::cout<<"\ndurée prêt : "<<annees;
        std::cout<<"\ntaux d'intérêt"<<taux_annuel<<std::endl;
        */
    }
           
        file.close();

}
   

