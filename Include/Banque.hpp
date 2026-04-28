class Banque
{

    private:
        std::string m_nom; 

        std::vector<Compte> Comptes; 
    public:

        Banque::Banque(std::string nom): m_nom(nom);

        Compte Banque::ajouterCompte()
        {
            Comptes.pusback(Compte); 
        }
} 