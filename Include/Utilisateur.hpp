class Utilisateur
{

    private:    
        std::vector<std::vector<std::string>> data;

        std::vector<Compte*> comptes;

        std::string m_nom; 
    public: 

    Utilisateur::Utilisateur(float capital, int nbAn,float taux_annuel) : m_capital(capital), m_nbAn(nbAn), m_tauxAnnuel(taux_annuel) {}; 

    void Utilisateur::ajouterCompte(Compte compte1);

    void Utilisateur::afficherCompte();
}