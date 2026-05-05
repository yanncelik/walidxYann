#include <iostream>
#include <Utilisateur.hpp> 
#include <Banque.hpp>
#include <Compte.hpp> 
#include <vector>
#include <cstdio>
#include <cstring>

    //void initValeurs(float mensualite, float capital); 

    //float CalculerMensualite(calc *calcUN, float mensualite, float capital, float taux_annuel, int nbAn); 

    //void afficherMensualite(float mensualite);

    /*
    */
    void addUser(Utilisateur* user);

    void addUser(Utilisateur** user, std::string nom); //objet utilisateur)

    Compte* addAccount(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab);

    void afficherCompte(std::vector<Utilisateur*> &userTab);

    Utilisateur* chercherUtilisateur(std::vector<Utilisateur*> &userTab);

    void recupUtilisateur(std::vector<Utilisateur*> &userTab);
int main(){

    std::vector<Utilisateur*> userTab; 

    Utilisateur *user1 = nullptr;
    Compte *Compte1 = nullptr; 

    Banque* CA = new Banque("credit agricole");
    Banque* CM = new Banque("credit mutuelle");
    Banque* LCL = new Banque("LCL");
    Banque* BNP = new Banque("BNP");

    std::vector<Banque*> BankTab = {CA, CM, LCL, BNP};

    while(1)
    {

        std::cout << "ajouter un utilisateur ? : 1, creer un compte : 2, afficher un compte : 3, sortie : 4 \n"; 
        
        int saisie = 0;
        
        std::cin >> saisie; 
        
        if(saisie == 1)
        {
            addUser(user1);
            userTab.push_back(user1);
        }
        
        if(saisie == 2)
        {
            Compte1 = addAccount(userTab, BankTab);
            
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

void addUser(Utilisateur* user1)
{

    std::string nom; 

    std::cout << "entrez votre nom\n" << std::endl;
    
    std::cin >> nom; 
    
    user1 = new Utilisateur(nom); //objet utilisateur
        
}

Compte* addAccount(std::vector<Utilisateur*> &userTab, std::vector<Banque*> &BankTab)
{
    Utilisateur* currentUser = chercherUtilisateur(userTab);

    Compte* compte = nullptr; 

    //Creation du compte 

    float capital;
    
    float taux_annuel;
    
    int nbAn;  
    
    std::string nom;
    std::string banque; 
    int idBanque = 0;
    
    std::cout << "chez quel banque souhaitez vous devenir adhérent (CA = 1, CM = 2, LCL = 3, BNP = 4)\n" << std::endl;
    
    std::cin >> idBanque; 
    
    std::cout << "montant du capitale emprunte ? : \n" << std::endl;
    
    std::cin >>capital; 
    
    std::cout << "Nombre d'années ? (10, 15 ou 20 ans) : \n"; 
    
    std::cin >> nbAn; 
    
    do
    {
        std::cout << "Taux annuel (3 ou 4 %) ? : \n";
        
        std::cin >> taux_annuel;

    }while(!(taux_annuel == 3) || (taux_annuel == 4));
    
    compte = new Compte(banque,capital, nbAn, taux_annuel);

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
        Utilisateur* currentUser = chercherUtilisateur(userTab);

        //on affiche le compte de l'utilisateur qui a été trouvé 
        currentUser->ChoisirCompte();
}

Utilisateur* chercherUtilisateur(std::vector<Utilisateur*>& userTab)
{
        Utilisateur* currentUser = NULL; 

        std::string utilisateur; 

        std::cout << "entrez le nom de l'utilisateur : \n\n";

        std::cin >> utilisateur; 

        int tailleTab = 0;

        tailleTab = userTab.size(); 

              //recherche par nom dans tous les objets Utilisateur 
        for(int i = 0; i < tailleTab; i++)
        {
          
            //if(utilisateur == userTab[i]->m_nom)
            if(utilisateur == (userTab[i]->getUserName()))
            {
                currentUser = userTab[i];

                //pas de réponse retournée 
                if(currentUser == NULL)
                    std::cout <<"attention, erreur de recup. de l'utilisateur ! \n";
                
                //si réponse, on sort de la boucle 
                break; 
            }

            std::cout << "aucun utilisateur n'a ete trouve :/ ";
        }

        return currentUser; 
}

void recupUtilisateur(std::vector<Utilisateur*> &userTab) //lit dans un fichier les utilisateurs déjà enregistrés
{
    Utilisateur* prevUser = nullptr; 

    char* utilisateur; 
    
    FILE* test =  fopen("donnees.txt","r");

    if(test !=NULL)
    {    
        while(fscanf(test, "%s", utilisateur)==1)
        {
            int len = (int)strlen(utilisateur);
            std::string userToStr(utilisateur, len);
            addUser(&prevUser, userToStr); //ajoute les utilisateurs trouvés au programme 
            userTab.push_back(prevUser); 
            prevUser = nullptr; //on récupère prevUser pour initialiser un autre objet
        }
        
    }
}
   
void addUser(Utilisateur** prevUser, std::string nom) 
{
    *prevUser = new Utilisateur(nom);
}
