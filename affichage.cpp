#include <iostream>
#include <vector>
#include <string>

void afficherMensualite(std::vector<std::vector<std::string>>& data) {

    int lignes = data.size();
    
    for (int i = 0; i < lignes; i++) {

    int colonnes = data[i].size(); 

    for (int j = 0; j < colonnes; j++) {
        std::cout << "| " << data[i][j] << " ";
    }

    std::cout << "|" << std::endl;
}

}