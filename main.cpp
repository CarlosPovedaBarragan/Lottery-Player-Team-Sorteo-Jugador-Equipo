//Librería.

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 

using namespace std;


/*Función para inscribir a los participantes del torneo*/
void Rellenar_Vector(vector<string>*Vectores) {

	int num;
	int pos = 1;
	string valor;

	cout << " Introducir numeros de participantes:" << endl; 
	cin >> num;

	for (int i = 0; i < num; i++) {  
		cout << endl;
		cout << pos << "-Participante:\n";
		cin >> valor;
		Vectores->push_back(valor); //Introducimos en el vector los nombres de los participantes
		pos++;
	}
}

/*Función para imprimir los vectores*/
void Imprimir_Vectores(vector <string> *Vectores) {
	cout << endl;
	int posicion = 1;
	for (vector<string>::iterator it = Vectores->begin(); it != Vectores->end(); ++it) {
		cout << posicion << "->" << *it;
		if (posicion != Vectores->size()) {
			cout << "\n";
			posicion++;
		}
	}
	cout << endl;
}

/*Función insertar los equipos en el vector equipos*/
void Num_Equipos(vector<string>*Equipos) {
	cout << endl;
	cout << "---------EQUIPOS------\n";
	Equipos->push_back("Real Madrid");
	Equipos->push_back("Valencia");
	Equipos->push_back("Celta");
	Equipos->push_back("Bayern");
	Equipos->push_back("Leverkusen");
	Equipos->push_back("Mallorca");
	Equipos->push_back("Roma");
	Equipos->push_back("Milan");
	Equipos->push_back("Wender");
	Equipos->push_back("Deportivo");
	Equipos->push_back("Getafe");
	Equipos->push_back("Villareal");
	Equipos->push_back("Napoli");
	Equipos->push_back("Arsenal");
	Equipos->push_back("M.City");
	Equipos->push_back("Juventus");
	Imprimir_Vectores(Equipos);
	cout << endl;
}


/*Función para rellenar el vector Numeros donde se han insertado numeros aleatorios donde no se van a repetir mismos numeros*/
void Rellenar_Numeros(vector<int>*Numeros, vector<string>&Participantes, vector<string>&Equipos) {

	int num;
	int pos = 0;
	srand(time(NULL));
	//Recorremos el vector de participantes para insertar los numeros aleatorios correspondiente a cada participantes. 
	for (int i = 0; i < Participantes.size(); ++i) 
	{
		num = rand() % Equipos.size(); //Generamos el numero aleatorio entre  0 y el numero de participantes que tenemos.
		if (i >= 1) { //Utilizamos el if para poder comenzar la insercción
			while (pos < i) //Utilizamos while porque vamos a recorrer todo el vector Numeros para que no se repitan los numeros aleatorios.  
			{
				if (num == Numeros->at(pos)) { //Si es igual generamos otro numero aleatorio.
					num = rand() % Equipos.size();
					pos = 0;
				}
				else {
					pos++;
				}
			}
		}
		Numeros->push_back(num); //Insertamos el numero 
		pos = 0;
	}
	
}
/*Funcion para imprimir el parejamiento del participante y el equipo que le corresponde*/
void Imprimir_Sorteo(vector<int>&Numeros, vector<string>&Participantes, vector<string>&Equipos) {

	for (int i = 0; i < Participantes.size(); ++i)
	{
		cout << Participantes.at(i) << " EQUIPO: " << Equipos.at(Numeros.at(i)) << endl;
		cout << endl;
	}
}


int main() {


	cout << "/////////////////////////" << endl;
	cout << "         SORTEO          " << endl;
	cout << "/////////////////////////" << endl;

	vector<string> Participantes;
	vector<string> Equipos;
	vector<int> Numeros;

	Rellenar_Vector(&Participantes);
	cout << "---------PARTICIPANTES---------\n";
	Imprimir_Vectores(&Participantes);
	Num_Equipos(&Equipos);
	cout << "-------COMIENZO_DEL TORNEO-------\n";
	Rellenar_Numeros(&Numeros, Participantes, Equipos);
	Imprimir_Sorteo(Numeros, Participantes, Equipos);
	system("Pause");
}