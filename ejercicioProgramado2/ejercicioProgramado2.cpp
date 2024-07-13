#pragma once

#ifndef __METODOS__
#define __METODOS__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CD {
public:
    string nombreGrupo;
    string fechaEdicion;
    string firmaDiscografica;
    int duracionCD;

    CD(string nombreGrupo, string fechaEdicion, string firmaDiscografica, int duracionCD)
        : nombreGrupo(nombreGrupo), fechaEdicion(fechaEdicion), firmaDiscografica(firmaDiscografica), duracionCD(duracionCD) {}

    bool operator<(const CD& otroCD) const {
        if (this->nombreGrupo == otroCD.nombreGrupo) {
            return this->fechaEdicion < otroCD.fechaEdicion;
        }
        return this->nombreGrupo < otroCD.nombreGrupo;
    }

    void mostrar() const {
        cout << "Nombre del grupo o interprete: " << nombreGrupo << endl;
        cout << "Fecha de edicion: " << fechaEdicion << endl;
        cout << "Firma discografica: " << firmaDiscografica << endl;
        cout << "Duracion del CD: " << duracionCD << " minutos" << endl;
    }
};

void ingresarDatosCD(vector<CD>& coleccion) {
    string nombreGrupo, fechaEdicion, firmaDiscografica;
    int duracionCD;
    int cantidadCDs; // Variable para almacenar la cantidad de CDs a ingresar

    cout << "Ingrese la cantidad de CDs a ingresar: ";
    cin >> cantidadCDs;
    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < cantidadCDs; ++i) {
        cout << "Ingrese los datos del CD: " << i + 1 << ":\n";
        cout << "\nNombre del grupo o interprete: ";
        getline(cin, nombreGrupo);
        cout << "\nFecha de edicion (YYYY-MM-DD): ";
        getline(cin, fechaEdicion);
        cout << "\nFirma discografica: ";
        getline(cin, firmaDiscografica);
        cout << "\nDuracion del CD (en minutos): ";
        cin >> duracionCD;
        cout << "\n ";
        cout << "------------------------------ \n";
        cin.ignore();  // Para limpiar el buffer de entrada

        coleccion.emplace_back(nombreGrupo, fechaEdicion, firmaDiscografica, duracionCD);
    }
}

void mostrarColeccion(const vector<CD>& coleccion) {
    for (const auto& cd : coleccion) {
        cd.mostrar();
        cout << "-----------------------" << endl;
    }
}

int main() {
    vector<CD> coleccion;

    ingresarDatosCD(coleccion);

    sort(coleccion.begin(), coleccion.end());

    cout << "\nColeccion ordenada:\n";
    mostrarColeccion(coleccion);

    return 0;
}

#endif // !__METODOS__
