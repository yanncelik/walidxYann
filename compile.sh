#!/bin/bash

OUTPUT="main"

# Compilation avec chemin vers Include
g++ -std=c++17 main.cpp -IInclude -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "Compilation réussie ✔"
    echo "Exécution :"
    ./$OUTPUT
else
    echo "Erreur de compilation ❌"
fi
