#include <iostream>
#include <Utilisateur.hpp> 
#include <Banque.hpp>
#include <Compte.hpp> 

    //void initValeurs(float mensualite, float capital); 

    //float CalculerMensualite(calc *calcUN, float mensualite, float capital, float taux_annuel, int nbAn); 

    //void afficherMensualite(float mensualite);

int main(){

    std::vector<Utilisateur> userTab; 

    Banque CA("credit agricole"), CM("credit mutuelle"), LCL("LCL"), BNP("BNP");//création des objets Banque 

    std::cout << "souhaitez ajouter un utilisateur ? : Y/N \n"; 

    char saisie = 'a'; 

    std::cin >> saisie; 

    if((saisie == y) || (saisie == Y))
    {
        std::cout << "entrez votre nom\n" << std::endl;
        
        std::cin >>nom; 
        
        Utilisateur user1(nom); //objet utilisateur

        userTab.pushback(user1);
        
    }

    //Creation du compte 
    
    std::cout <<"souhaitez vous creer un compte ? : Y/N\n";

    saisie = 'a';

    std::cin >> saisie; 

    if((saisie == y) || (saisie == Y))  
    {  
        float mensualite, capital;
        
        float taux_annuel;
        
        int nbAn;  
        
        std::string nom;
        std::string banque;
        
        std::cout << "chez quel banque souhaitez vous devenir adhérent (CA, CM, LCL, BNP)\n" << std::endl;
        
        std::cin >> banque; 
        
        std::cout << "montant du capitale emprunte ? : \n" << std::endl;
        
        std::cin >>capital; 
        
        std::cout << "Nombre d'années ? : \n"; 
        
        std::cin >> nbAn; 
        
        do
        {
            std::cout << "Taux annuel (3 ou 4 %) ? : \n";
            
            std:: cin >> taux_annuel;
        }while(!(taux_annuel == 3) || (taux_annuel == 4));
        
        compte Compte1(banque,capital, nbAn, taux_annuel);
        
        //CREATION DE L'OBJET UTILISATEUR INITIALISE (appel du constructeur)
        
        //mensualite = CalculerMensualite(&calcUN, mensualite, capital, taux_annuel, nbAn); 
        
        //afficherMensualite(mensualite); 
        
        //std::cout<< "calcul1 : " << calcUN.calcul1 << "calcul2 : " << calcUN.calcul2 << "calcul3 : " << calcUN.calcul3 << std::endl; 
        
        //calcul  
        
        Utilisateur.ajouterCompte(&compte1);
        
        //enregistrement de l'objet compte auprès de l'objet banque correspondant 
        switch(banque)
        {
            case "CA":
            CA.ajouterCompte(&Compte1);
            case "CM":
            CM.ajouterCompte(&Compte1);
            case "LCL":
            LCL.ajouterCompte(&Compte1);
            case "BNP":
            BNP.ajouterCompte(&Compte1);
            
            default:
            std::cout<<"erreur de saisie\n";
        }
    }
    
    std::cout<<"souhaitez vous afficher un compte ? "
    
    saisie = 'a';

    std::cin >> saisie; 

    if((saisie == y) || (saisie == Y))  
    {

        Utilisateur *currentUser = NULL; 

        std::string utilisateur; 

        std::cout << "entrez le nom de l'utilisateur";

        std::cin >> utilisateur; 

        for(int i = 0; i < (length(userTab) - 1), i++)
        {

            if(utilisateur == userTab[i]->m_nom)
            {
                currentUser = userTab[i];

                if(currentUser == NULL)
                    cout <<"attention, erreur de recup. de l'utilisateur ! \n";
        
                break; 
            }

            std::cout << "aucun utilisateur n'a ete trouve :/ ";
        }

        curentUser->afficherCompte();

    }

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