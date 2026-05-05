#!/bin/bash

OUTPUT="main"

# Liste des fichiers sources
SRC="main.cpp Compte.cpp Banque.cpp Utilisateur.cpp"

# Compilation
g++ -std=c++17 $SRC -IInclude -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "Compilation réussie ✔"
    echo "Exécution :"
    ./$OUTPUT
else
    echo "Erreur de compilation ❌"
fi