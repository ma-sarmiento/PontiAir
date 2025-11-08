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
void comprar(avion aviones[]){
	char tamAvionC;
	int numVueloC;
	int numSillaC;
	int agregar=1;
	int agregarP=1;
	do{
		cout<<"Digite el tipo de avion en mayusculas, para salir digite otra letra: ";
		cin>>tamAvionC;
		switch(tamAvionC){
			case 'P':
			agregarP=1;
			cout<<"Ingrese el numero de vuelo (1 a 5): ";
			cin>>numVueloC;
			while(numVueloC < 1 || numVueloC > 5){
				cout<<"Ingrese el numero de vuelo (1 a 5): ";
				cin>>numVueloC;
			}
			aviones[numVueloC-1].tamAvion = 'P';
			aviones[numVueloC-1].numVuelo = numVueloC;
			do{
				cout<<"Ingrese la silla que desea de 1 a 16: ";
				cin>>numSillaC;
				while(numSillaC>16 || aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
					if(aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
						cout<<"La silla esta ocupada, escoja otra: ";
					}
					cin>>numSillaC;
				}
				aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada=true;
				aviones[numVueloC-1].pasajeros[numSillaC-1].numSillaP = numSillaC;
				if(numSillaC>=1 && numSillaC<=8){
					aviones[numVueloC-1].asientoPref+=1;
				}else if(numSillaC>=9 && numSillaC<=16){
					aviones[numVueloC-1].asientoGeneral+=1;
				}
				cout<<"Nombre: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].nombre;
				cout<<"Apellido: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].apellido;
				cout<<"Edad: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].edad;
				cout<<"Sexo (M para masculino, F para femenino en mayusculas): ";
				do{
					cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].sexo;
				}while(aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!='M' && aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!= 'F');
				aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla=cotizar(numSillaC, 'P', aviones[numVueloC-1].pasajeros[numSillaC-1].edad);
				cout<<"El precio de la sillas es: "<<aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla<<endl;
				cout<<endl;
				//cotizacion del asiento por cada tipo de avion
				cout<<"- COTIZAZIONES - "<<endl;
				cout<<"El precio de la silla en el avion pequenio es de: "<<aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla<<endl;
				cout<<"El precio de la silla en el avion mediano es de: "<<cotizar(numSillaC, 'M', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				cout<<"El precio de la silla en el avion grande es de: "<<cotizar(numSillaC, 'G', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				cout<<"Si desea ingresar una persona mas a este numero de vuelo digite 1"<<endl;
				cin>>agregarP;
			}while(agregarP==1);
			break;
			case 'M':
			agregarP=1;
			cout<<"Ingrese el numero de vuelo (6 a 10): ";
			cin>>numVueloC;
			while(numVueloC < 6 || numVueloC > 10){
				cout<<"Ingrese el numero de vuelo (6 a 10): ";
				cin>>numVueloC;
			}
			aviones[numVueloC-1].tamAvion = 'M';
			aviones[numVueloC-1].numVuelo = numVueloC;
			do{
				cout<<"Ingrese la silla que desea de 1 a 28: ";
				cin>>numSillaC;
				while(numSillaC>28 || aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
					if(aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
						cout<<"La silla esta ocupada, escoja otra: ";
					}
					cin>>numSillaC;
				}
				aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada=true;
				aviones[numVueloC-1].pasajeros[numSillaC-1].numSillaP = numSillaC;
				if(numSillaC>=1 && numSillaC<=8){
					aviones[numVueloC-1].asientoPref+=1;
				}else if(numSillaC>=9 && numSillaC<=28){
					aviones[numVueloC-1].asientoGeneral+=1;
				}
				cout<<"Nombre: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].nombre;
				cout<<"Apellido: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].apellido;
				cout<<"Edad: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].edad;
				cout<<"Sexo (M para masculino, F para femenino en mayusculas): ";
				do{
					cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].sexo;
				}while(aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!='M' && aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!= 'F');
				aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla=cotizar(numSillaC, 'M', aviones[numVueloC-1].pasajeros[numSillaC-1].edad);
				cout<<"El precio de la sillas es: "<<aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla<<endl;
				cout<<endl;
				//cotizaciones de los precios de la silla en cada tipo de avion
				cout<<"- COTIZAZIONES - "<<endl;
				if(numSillaC<=16){
					cout<<"El precio de la silla en el avion pequenio es de: "<<cotizar(numSillaC, 'P', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				}else if(numSillaC>16){
					cout<<"Esta silla no existe en el avion pequenio"<<endl;
				}
				cout<<"El precio de la silla en el avion mediano es de: "<<aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla<<endl;
				cout<<"El precio de la silla en el avion grande es de: "<<cotizar(numSillaC, 'G', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				cout<<"Si desea ingresar una persona mas a este numero de vuelo digite 1"<<endl;
				cin>>agregarP;
			}while(agregarP==1);
			break;
			case 'G':
			agregarP=1;
			cout<<"Ingrese el numero de vuelo (11 a 15): ";
			cin>>numVueloC;
			while(numVueloC < 11 || numVueloC > 15){
				cout<<"Ingrese el numero de vuelo (11 a 15): ";
				cin>>numVueloC;
			}
			aviones[numVueloC-1].tamAvion = 'G';
			aviones[numVueloC-1].numVuelo = numVueloC;
			do{
				cout<<"Ingrese la silla que desea de 1 a 40: ";
				cin>>numSillaC;
				while(numSillaC>40|| aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
					if(aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada == true){
						cout<<"La silla esta ocupada, escoja otra: ";
					}
					cin>>numSillaC;
				}
				aviones[numVueloC-1].pasajeros[numSillaC-1].ocupada=true;
				aviones[numVueloC-1].pasajeros[numSillaC-1].numSillaP = numSillaC;
				if(numSillaC>=1 && numSillaC<=8){
					aviones[numVueloC-1].asientoPref+=1;
				}else if(numSillaC>=9 && numSillaC<=40){
					aviones[numVueloC-1].asientoGeneral+=1;
				}
				cout<<"Nombre: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].nombre;
				cout<<"Apellido: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].apellido;
				cout<<"Edad: ";
				cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].edad;
				cout<<"Sexo (M para masculino, F para femenino es mayusculas): ";
				do{
					cin>>aviones[numVueloC-1].pasajeros[numSillaC-1].sexo;
				}while(aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!='M' && aviones[numVueloC-1].pasajeros[numSillaC-1].sexo!= 'F');
				aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla=cotizar(numSillaC, 'G', aviones[numVueloC-1].pasajeros[numSillaC-1].edad);
				cout<<"El precio de la sillas es: "<<aviones[numVueloC-1].pasajeros[numSillaC-1].precioSilla<<endl;
				cout<<endl;
				//Cotizaciones del asiento por cada tipo de avion
				cout<<"- COTIZAZIONES - "<<endl;
				if(numSillaC<=16){
					cout<<"El precio de la silla en el avion pequenio es de: "<<cotizar(numSillaC, 'P', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				}else if(numSillaC>16){
					cout<<"Esta silla no existe en el avion pequenio"<<endl;
				}
				if(numSillaC<=28){
					cout<<"El precio de la silla en el avion mediano es de: "<<cotizar(numSillaC, 'M', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				}else if(numSillaC>28){
					cout<<"Esta silla no existe en el avion mediano"<<endl;
				}
				cout<<"El precio de la silla en el avion grande es de: "<<cotizar(numSillaC, 'G', aviones[numVueloC-1].pasajeros[numSillaC-1].edad)<<endl;
				cout<<"Si desea ingresar una persona mas a este numero de vuelo digite 1"<<endl;
				cin>>agregarP;
			}while(agregarP==1);
			break;
			default:
			agregar=0;
			break;
		}
	}while(agregar==1);
}
long cotizar(int numSilla, char tamAvion, int edad){
	long precio=0;
	switch(tamAvion){
		case 'P':
			if(numSilla>=1 && numSilla<=8){
				precio=120000;
				if(edad>=1 && edad<=5){
					precio= 120000 - (120000*0.08);
				}
				else if(edad>60){
					precio= 120000 - (120000*0.05);
				}
			}else if(numSilla>=9 && numSilla<=16){
				precio=30000;
				if(edad>=1 && edad<=5){
					precio= 30000 - (30000*0.15);
				}
				else if(edad>60){
					precio= 30000 - (30000*0.1);
				}
			}
			return precio;
			break;
		case 'M':
			if (numSilla>=1 && numSilla<=8){
				precio=150000;
				if(edad>=1 && edad <=5){
					precio=150000 - (150000 * 0.08);
				}
				else if (edad>60){
					precio=150000 - (150000 * 0.05);
				}
			}
			else if(numSilla>=9 && numSilla <=28){
				precio=35000;
				if(edad>=1 && edad <=8){
					precio= 35000 - (35000*0.15);
				}else if(edad>60){
					precio=35000 - (35000*0.1);
				}
			}
			return precio;
			break;
		case 'G':
			if (numSilla>=1 && numSilla<=8){
				precio=200000;
				if(edad>=1 && edad <=5){
					precio=200000 - (200000 * 0.08);
				}
				else if (edad>60){
					precio=200000 - (200000 * 0.05);
				}
			}
			else if(numSilla>=9 && numSilla <=40){
				precio=40000;
				if(edad>=1 && edad <=5){
					precio= 40000 - (40000*0.15);
				}else if(edad>60){
					precio=40000 - (40000*0.1);
				}
			}
			return precio;
			break;
	}
}
void calcularPasajeros(avion aviones[]){
	int numeroVuelo;
	bool repetir=true;
	int contM = 0;
	int contF = 0;
	int contEdad = 0;
	int opcion;
	int min, max;
	cout<<"Calcular numero de pasajeros: "<<endl;
	cout<<"Digite el numero de vuelo: "<<endl;
	cin>>numeroVuelo;
	do{
		cout<<"\n1. Sexo"<<endl;
		cout<<"\n2. Rango de edad"<<endl;
		cout<<"\n3. Salir"<<endl;
		cout<<"\nDigite una opcion para hacer el calculo: ";
		cin>>opcion;
		switch(opcion){
		case 1:
		if(aviones[numeroVuelo-1].tamAvion=='P'){
			for (int k=0; k<16; k++){
				if (aviones[numeroVuelo-1].pasajeros[k].sexo == 'M'){
					contM=contM + 1;
				}
				if(aviones[numeroVuelo-1].pasajeros[k].sexo == 'F'){
					contF= contF + 1;
				}
			}
			cout<<setw(15) << "Nombre";
   			cout<<setw(15) << "Apellido";
    		cout<<setw(15) << "Sexo"<<endl;
			for (int k=0; k<16; k++){
				if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
				cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].sexo<<endl;
				}
			}
		}
		if(aviones[numeroVuelo-1].tamAvion=='M'){
			for (int k=0; k<28; k++){
				if (aviones[numeroVuelo-1].pasajeros[k].sexo == 'M'){
					contM=contM + 1;
				}
				if(aviones[numeroVuelo-1].pasajeros[k].sexo == 'F'){
					contF= contF + 1;
				}
			}
			cout<<setw(15) << "Nombre";
   			cout<<setw(15) << "Apellido";
    		cout<<setw(15) << "Sexo"<<endl;
			for (int k=0; k<28; k++){
				if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
				cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].sexo<<endl;
				}
			}
		}
		if(aviones[numeroVuelo-1].tamAvion=='G'){
			for (int k=0; k<40; k++){
				if (aviones[numeroVuelo-1].pasajeros[k].sexo == 'M'){
					contM=contM + 1;
				}
				if(aviones[numeroVuelo-1].pasajeros[k].sexo == 'F'){
					contF= contF + 1;
				}
			}
			cout<<setw(15) << "Nombre";
   			cout<<setw(15) << "Apellido";
    		cout<<setw(15) << "Sexo"<<endl;
			for (int k=0; k<40; k++){
				if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
				cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            	cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].sexo<<endl;
				}
			}
		}
		cout<<"Los pasajeros hombres en total son: "<<contM<<endl;
		cout<<"Los pasajeros mujeres en total son: "<<contF<<endl;
		break;
		case 2:
		cout<<"Digite el rango de edad (min - max): "<<endl;
			cin>>min>>max;
			if(aviones[numeroVuelo-1].tamAvion=='P'){
				for(int k=0; k<16; k++){
					if (aviones[numeroVuelo-1].pasajeros[k].edad >=min && aviones[numeroVuelo-1].pasajeros[k].edad<=max){
					contEdad = contEdad + 1;
					}
				}
				cout<<setw(15) << "Nombre";
   				cout<<setw(15) << "Apellido";
    			cout<<setw(15) << "Edad"<<endl;
				for (int k=0; k<16; k++){
					if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
					cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            		cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            		cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].edad<<endl;
					}
				}
			}
			if(aviones[numeroVuelo-1].tamAvion=='M'){
				for(int k=0; k<28; k++){
					if (aviones[numeroVuelo-1].pasajeros[k].edad >=min && aviones[numeroVuelo-1].pasajeros[k].edad<=max){
					contEdad = contEdad + 1;
					}
				}
				cout<<setw(15) << "Nombre";
   				cout<<setw(15) << "Apellido";
    			cout<<setw(15) << "Edad"<<endl;
				for (int k=0; k<28; k++){
					if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
						cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            			cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            			cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].edad<<endl;
					}
				}
			}
			if(aviones[numeroVuelo-1].tamAvion=='G'){
				for(int k=0; k<40; k++){
					if (aviones[numeroVuelo-1].pasajeros[k].edad >=min && aviones[numeroVuelo-1].pasajeros[k].edad<=max){
					contEdad = contEdad + 1;
					}
				}
				cout<<setw(15) << "Nombre";
   				cout<<setw(15) << "Apellido";
    			cout<<setw(15) << "Edad"<<endl;
				for (int k=0; k<40; k++){
					if(aviones[numeroVuelo-1].pasajeros[k].ocupada){
						cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].nombre;
            			cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].apellido;
            			cout<<setw(15) << aviones[numeroVuelo - 1].pasajeros[k].edad<<endl;
					}
				}
			}
			cout<<"Los pasajeros entre este rango de edad son: "<<contEdad;
		break;
		case 3:
		repetir = false;
		break;
		}
	}while(repetir);
}
void calcularGanancia(avion aviones[]){
	for(int i=0; i<15; i++){
		if(aviones[i].tamAvion=='P'){
			for(int j=0; j<16; j++){
			aviones[i].gananciaTotal+=aviones[i].pasajeros[j].precioSilla;
			}
		}
		if(aviones[i].tamAvion=='M'){
			for(int j=0; j<28; j++){
			aviones[i].gananciaTotal+=aviones[i].pasajeros[j].precioSilla;
			}
		}
		if(aviones[i].tamAvion=='G'){
			for(int j=0; j<40; j++){
			aviones[i].gananciaTotal+=aviones[i].pasajeros[j].precioSilla;
			}
		}
	}
}
void generarArchivo(avion aviones[]){
	avion aux;
	for (int k=0; k<14; k++){
		for (int j=k; j<15; j++){
			if (aviones[k].gananciaTotal > aviones[j].gananciaTotal){
				aux=aviones[k];
				aviones[k]=aviones[j];
				aviones[j]=aux;
			}
		}
	}
	ofstream archivo;
	archivo.open("reporte.txt");
	for(int i=0; i<15; i++){
		if(aviones[i].gananciaTotal!=0){
			if(aviones[i].tamAvion=='P'){
				archivo<<aviones[i].tamAvion<<endl;
				archivo<<aviones[i].numVuelo<<endl;
				for(int j=0; j<16; j++){
					if(aviones[i].pasajeros[j].numSillaP!=0){
						archivo<<aviones[i].pasajeros[j].numSillaP<<endl;
						archivo<<aviones[i].pasajeros[j].nombre<<" "<<aviones[i].pasajeros[j].apellido<<" "<<aviones[i].pasajeros[j].edad<<" "<<aviones[i].pasajeros[j].sexo<<endl;
						archivo<<"#"<<endl;
					}
				}
				archivo<<aviones[i].gananciaTotal<<endl;
				//Asientos preferenciales vendidos en el avion
				if(aviones[i].asientoPref!=0){
					archivo<<"Asientos preferenciales vendidos: "<<aviones[i].asientoPref<<endl;
				}
				//Asientos generales vendidos en el avion
				if(aviones[i].asientoGeneral!=0){
					archivo<<"Asientos generales vendidos: "<<aviones[i].asientoGeneral<<endl;
				}
			archivo<<"#"<<endl;
			}
			if(aviones[i].tamAvion=='M'){
				archivo<<aviones[i].tamAvion<<endl;
				archivo<<aviones[i].numVuelo<<endl;
				for(int j=0; j<28; j++){
					if(aviones[i].pasajeros[j].numSillaP!=0){
						archivo<<aviones[i].pasajeros[j].numSillaP<<endl;
						archivo<<aviones[i].pasajeros[j].nombre<<" "<<aviones[i].pasajeros[j].apellido<<" "<<aviones[i].pasajeros[j].edad<<" "<<aviones[i].pasajeros[j].sexo<<endl;
					}
				}
				archivo<<aviones[i].gananciaTotal<<endl;
				if(aviones[i].asientoPref!=0){
					archivo<<"Asientos preferenciales vendidos: "<<aviones[i].asientoPref<<endl;
				}
				if(aviones[i].asientoGeneral!=0){
					archivo<<"Asientos generales vendidos: "<<aviones[i].asientoGeneral<<endl;
				}
			archivo<<"#"<<endl;
			}
			if(aviones[i].tamAvion=='G'){
				archivo<<aviones[i].tamAvion<<endl;
				archivo<<aviones[i].numVuelo<<endl;
				for(int j=0; j<40; j++){
					if(aviones[i].pasajeros[j].numSillaP!=0){
						archivo<<aviones[i].pasajeros[j].numSillaP<<endl;
						archivo<<aviones[i].pasajeros[j].nombre<<" "<<aviones[i].pasajeros[j].apellido<<" "<<aviones[i].pasajeros[j].edad<<" "<<aviones[i].pasajeros[j].sexo<<endl;
					}
				}
				archivo<<aviones[i].gananciaTotal<<endl;
				if(aviones[i].asientoPref!=0){
					archivo<<"Asientos preferenciales vendidos: "<<aviones[i].asientoPref<<endl;
				}
				if(aviones[i].asientoGeneral!=0){
					archivo<<"Asientos generales vendidos: "<<aviones[i].asientoGeneral<<endl;
				}
			archivo<<"#"<<endl;
			}
		}
	}
	archivo.close();
}