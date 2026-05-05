#ifndef COMP
#define COMP

#include <vector>
#include <iostream>


class Compte
{

    private:
        std::string m_banque;   //nom de la banque 

        float m_capital;    //capital emprunté à la banque 

        float m_mensualite; //valeur à rembourser tous les mois 

        int m_nbAn; //nombre d'années pour le remboursement 

        int UserAccID;  //identifiant du compte de l'utilisateur 

        float m_tauxAnnuel; //taux d'intérêt choisi pour le contrat 

        float somme_Annuelle = 0;

        float* somme_restante = (float*) malloc(20 * sizeof(float));

        float* interet_Annuel = (float*) malloc(20 * sizeof(float)); //valeur des intérêts remboursée chaque année

        float interetEuroTotal; //sommme des intérêts touchés par la banque à la fin du prêt 

        std::vector<std::vector<std::string>> tableauAffichage1; 

        std::vector<std::vector<std::string>> tableauAffichage2; 

        std::vector<std::vector<std::string>> tableauAffichage3; 

    public: 

        Compte(std::string banque, float capital, int nbAn,float taux_annuel);

        void initAffichage1(); 

        void initAffichage2(); 

        void initAffichage3();

        void calculerMensualite();

        void afficherInterface(); 

        void initNumCompte(int nbCompte);

        void afficherPage(std::vector<std::vector<std::string>>& tableau);

        void afficherContrat();

        void afficherRemboursements();

        void afficherValeursTotales();

};

#endif 