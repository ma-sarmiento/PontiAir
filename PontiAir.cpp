#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct pasajero{
    string nombre;
    string apellido;
    bool ocupada=false;
    int edad;
    char sexo;
    int numSillaP=0;
    long precioSilla=0;
};

struct avion{
    int numVuelo=-1;
    char tamAvion;
    long gananciaTotal=0;
    int asientoGeneral=0;
    int asientoPref=0;
    pasajero pasajeros[40];
};

void comprar(avion aviones[]);
long cotizar(int numSilla, char tamAvion, int edad);
void calcularPasajeros(avion aviones[]);
void calcularGanancia(avion aviones[]);
void generarArchivo(avion aviones[]);

int main (){
    avion aviones[15];
    bool repetirM=true;
    int opcion;
    do{
        cout<<"Bienvenidos a PontiAir"<<endl;
        cout<<"\nMenu"<<endl;
        cout<<"\n1. Comprar y cotizar Tiquetes"<<endl;
        cout<<"\n2. Calcular pasajeros"<<endl;
        cout<<"\n3. Generar Archivo"<<endl;
        cout<<"\nDigite una opcion: "<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                comprar(aviones);
                break;
            case 2:
                calcularPasajeros(aviones);
                break;
            case 3:
                calcularGanancia(aviones);
                generarArchivo(aviones);
                break;
            default:
                repetirM=false;
                break;
        }
    }while(repetirM);
}