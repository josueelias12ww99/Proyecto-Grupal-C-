#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#include <stdio.h> 
#include "complemento.cpp"

using namespace std;

Traductor palabras[100];


void agregarPalabras();
string ingresarCodigo();
string traducirCodigo(string);

int menu() {
	system("Color 80");
	system("cls");
	int a; 
	cout << "************************************" << endl;
	cout << "---------Menu----------" <<endl;
	cout<<"1. Ingresar palabra"<<endl;
	cout<<"2. Ver diccionario"<<endl;
	cout<<"3. Buscar Palabra"<<endl;
	cout<<"4. Actualizar Palabra"<<endl;
	cout<<"5. Eliminar Palabra"<<endl;
	cout<<"6. Traducir Codigo"<<endl;
	cout<<"7. Salir"<<endl;
	cout << "************************************" << endl;
	cout<<"Ingrese el numero de opcion: ";
	cin>>a;
	return a;
}

//Agregar
void agregar (ofstream &pa) {
		int contador=0, cantidad_pala=0;
	cout<<"Ingrese cantidad de Palabras: ";	
	cin>>cantidad_pala;
	contador=1;
	for (int i=0; i<cantidad_pala;i++){
		system("cls");
		cout<<"Palabra No. "<<contador<<".  "<<"CANTIDAD TOTAL No. "<<cantidad_pala<<"."<<endl;	
		contador++;
		cout<<"------------------------------------------\n"<<endl;
	system("cls");
	
	string pala;
	string tradu;
	string funcio;
	
	pa.open("Traductor.txt", ios::out|ios::app);
	if(pa.fail()) {
		cout<<"No se puede abrir el archivo"<<endl;
		exit(1);
	}
	
	cin.ignore();
	fflush(stdin);
	cout<<"Ingrese la Palabra: ";
	getline(cin,pala);
		fflush(stdin);
	cout<<"Ingrese Traduccion: ";
	getline(cin,tradu);
		fflush(stdin);
	cout<<"Ingrese Funcionalidad: ";
	getline(cin,funcio);
	pa<<pala<<" "<<tradu<<" "<<funcio<<" \n"<<endl;
	}
	pa.close();
}

//Leer
void verPalabras(ifstream &lec) {
	system("cls");
	string pala;
	string tradu;
	string funcio,funcio2;
	string texto;
	lec.open("Traductor.txt", ios::in);
	
	
		cout<<"        Palabras Registradas      \n<<"<<endl;
		lec>>pala;
		while (!lec.eof()) {
			lec>>tradu;
			lec>>funcio;
			cout << "************************************************" << endl;
			cout<<"Palabra: "<<pala<<endl;
			cout<<"Traduccion: "<<tradu<<endl;
			cout<<"Funcionalidad: "<<funcio;
			getline(lec,funcio2);
			cout<<funcio2<<endl;
	
			lec>>pala;
		}
		lec.close(); 
		
	system("pause");
}

//Buscar
void buscarPalabras(ifstream &lec) {
	system("cls");
	lec.open("Traductor.txt", ios::in);
	cout<<"          Buscar Palabra          "<<endl<<endl;
	string pala, palabusca;
	string tradu;
	string funcio, funcio2;
	bool encontrada = false;
		fflush(stdin);
	cout<<"Escriba la palabra que desee buscar: ";
	cin>>palabusca;
	lec>>pala;
	while(!lec.eof() &&  !encontrada) {
		lec>>tradu;
		lec>>funcio;
		
		if(pala == palabusca) {
		cout << "************************************************" << endl;
		cout<<"Palabra: "<<pala<<endl;
		cout<<"Traduccion: "<<tradu<<endl;
		cout<<"Funcionalidad: "<<funcio;
		getline(lec,funcio2);
			cout<<funcio2<<endl;;
		encontrada = true; 
		}
		lec>>pala;
	}
	lec.close();
	
	if(!encontrada)
		cout<<"Palabra no encontrada"<<endl;
	system("pause");
}

//Modificar
void modificafuncio(ifstream & Lec)
{
	system("cls");
		
		cout<<"         Modificar Palabra         "<<endl;
		cout<<endl;
	string pala;
	string tradu;
	string funcio,funcio2;
	string palabusca;
	string pala2,tradu2,funci2,fun2;
	int opc;
	Lec.open("Traductor.txt",ios::in );
	ofstream modi("modific.txt",ios::out);
	
	if(Lec.is_open())
	{
		cout<<"Ingrese la palabra que quiere actualizar: ";
		cin>>palabusca;
		Lec>>pala;
				while(pala != palabusca && !Lec.eof())
				{
				Lec>>tradu;
			Lec>>funcio;
				if(pala != palabusca)
				{
					getline(Lec,funcio2);
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;
						}
					Lec>>pala;
					if(Lec.eof()){
							cout<<"No se encontro palabra buscada"<<endl;
							modi.close();
								remove("modific.txt");
							system("pause");
							int main();
								main();
					}	
				}
		while(!Lec.eof())
		{	
			if(pala == palabusca){
			Lec>>tradu;
			Lec>>funcio;
				cout<<endl;
				
				
				
				cout<<"Ingrese la nueva palabra: ";
				cin>>pala2;
				
				
				cout<<""<<endl;
				
				cout<<"Ingrese la nueva traduccion: ";
				cin>>tradu2;
				fflush(stdin);
				
				cout<<""<<endl;
				
				cout<<"Ingrese la nueva funcionalidad: ";
				getline(cin,funci2);
	
					modi<<pala2<<" "<<tradu2<<" "<<funci2<<" "<<endl;	
			 cout<<endl;
			 	system("cls");
			
			
			 
			
			} 
		Lec>>pala;
			Lec>>tradu;
			Lec>>funcio;
			 	getline(Lec,funcio2);
			 	if(!Lec.eof()){
				 
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;	
						}
				
		}
		Lec.close();
		modi.close();
		
	}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
}
	
	remove("Traductor.txt");
	rename("modific.txt","Traductor.txt");	
cout<<"            Se actulizado la palabra           "<<endl;	

			system("pause");	
	
}

//Eliminar
void eliminar(ifstream & Lec){
	system("cls");
		
		cout<<"           Eliminar Palabra           "<<endl;
		cout<<endl;
	string pala;
	string tradu;
	string funcio,funcio2;
	string palabusca;
	string pala2,tradu2,funci2;
	int ni;
	Lec.open("Traductor.txt",ios::in );
	ofstream modi("modific.txt",ios::out);
	
		if(Lec.is_open()){
		cout<<"Ingrese la palabra que desee eliminar: ";
		cin>>palabusca;
		Lec>>pala;
			while(pala != palabusca && !Lec.eof()){ 
				Lec>>tradu;
				Lec>>funcio;
				if(pala != palabusca){
					getline(Lec,funcio2);
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;
						} 
						Lec>>pala;
					if(Lec.eof()){
							cout<<"No se encontro la palabra"<<endl;
							modi.close();
								remove("modific.txt");
							system("pause");
							int main();
								main();
					}
			}
			
		while(!Lec.eof()){	
			if(pala == palabusca){
			Lec>>tradu;
			Lec>>funcio;
				cout<<endl;
				cout<<"Esta a punto de borrar palabra,"<<palabusca<<endl;
			 
				cout<<"1. Precione 1 si desea borrar la palabra "<<palabusca<<endl;
				cout<<"2. Precione 2 si no desea borrar la plabra "<<palabusca<<endl<<endl;	
				cin>>ni;
				cout<<endl;
	
				if (ni!=1){
					cout<<"No se eliminara la siguiente palabra: "<<palabusca<<endl;
						modi.close();
								remove("modific.txt");
								
						system("pause");
						int main();
						main();
				}
			}
			
			Lec>>pala;
			Lec>>tradu;
			Lec>>funcio;
			 	getline(Lec,funcio2);
			 	if(!Lec.eof()){
				 
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;	
						}
				
		}
		Lec.close();
		modi.close();
		
		}else{
	cout<<"ERROR no se pudo encontrar el archivo."<<endl;
		}
	
	remove("Traductor.txt");
	rename("modific.txt","Traductor.txt");	
cout<<"La palabra "<<palabusca<<" se ha eliminando"<<endl;	

			system("pause");	
	
}

int main() {
	ofstream Palabra;
	ifstream lec;
	int sh;
	
	do {
		sh = menu();
		switch(sh){
			case 1:
				system("cls");
				agregar(Palabra);
				system("cls");
				break;
			
			case 2:
				system("cls");
				verPalabras(lec);
				system("cls");
				break;	
			
			case 3:
				system("cls");
				buscarPalabras(lec);
				system("cls");
				break;
			
			case 4:
				system("cls");
				modificafuncio(lec);
				system("cls");
				break;	
			
			case 5:
				system("cls");
				eliminar(lec);
				system("cls");
				break;
			
			case 6:
				agregarPalabras();
				string traduccion = traducirCodigo(ingresarCodigo());
				break;		
			
		}
		
		
		
	} while(sh !=7);
	return 0;
	system("pause");
	
}

void agregarPalabras(){

	ifstream archivo_entrada("Traductor.txt");;
    string linea, palabra1, palabra2;
    int contador = 0;
    bool bandera;

    while(getline(archivo_entrada, linea)) {
	
    	string str(linea);
        istringstream isstream(str);
        bandera = true;

    	while(!isstream.eof()){
    		
        	string tempStr;
        	isstream >> tempStr;
        	
        	if(bandera) {
				palabra1 = tempStr;
        	}
			else {
				palabra2 = tempStr;	
			}
			
			if(!bandera) break;
			bandera = false;    	
    	}

    	palabras[contador] = Traductor(palabra1, palabra2);
    	contador++;
    }

}

string ingresarCodigo(){

	string codigo, linea;
	
	cout<<""<<endl;
	cout<<"Ingrese el codigo que desea traducir"<<endl<<endl;
	cout<<"Escriba \"fin\" y luego presione enter"<<endl<<endl;
	
	while(true){
		getline(cin, linea);
		
		if(linea != "fin") codigo += linea + "\n";
        else break;
	}
	
	cout<<""<<endl<<endl;
	cout<<"Traduccion del Codigo:"<<endl;
	
	return codigo;
}

string traducirCodigo(string codigo){
	
	string str(codigo);
	istringstream isstream(str);
    string llaveInicio = "", llaveFin = "";
    
	while(!isstream.eof()){
		string tempStr;
		isstream >> tempStr;
		/*cout<<tempStr<<endl;*/
		if(tempStr != "{" && tempStr != "}"){
			for(int i = 0; i<100; i++){
				if(tempStr == palabras[i].getPalabra()){
					if(tempStr == "if"){
						llaveInicio = "inicio si";
						llaveFin = "fin si\n";
					}else if(tempStr == "else"){
						llaveInicio = "inicio entonces";
						llaveFin = "fin entonces\n";
					}else if(tempStr == "while"){
						llaveInicio = "inicio mientras";
						llaveFin = "fin mientras\n";
					}else if(tempStr == "for"){
						llaveInicio = "inicio para";
						llaveFin = "fin para\n";
					}  
					string::size_type pos = codigo.find(tempStr, 0);
					if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), palabras[i].getTraduccion());	
				}
			}
		}else if(tempStr == "{" && llaveInicio != ""){
			string::size_type pos = codigo.find(tempStr, 0);
			if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), llaveInicio);
			llaveInicio = "";
		}else if(tempStr == "}" && llaveFin != ""){
			string::size_type pos = codigo.find(tempStr, 0);
			if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), llaveFin);
			llaveFin = "";
		}else if(tempStr == "{"){
			string::size_type pos = codigo.find(tempStr, 0);
			if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), "_");
		}
	}
	string::size_type pos = codigo.find("_", 0);
	if (pos < string::npos) codigo.replace(pos, string("=_").length(), "{");
	
	cout<<codigo;
}
