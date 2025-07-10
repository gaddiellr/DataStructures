// =================================================================
//
// Author: Gaddiel Lara Roldán A01704231
// Date: 02/12/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(/**/int argc, char *argv[]/**/){
    int m,n,num,contador,suma;
	string nombre,palabra,descripcion;
    map<string, int> diccionario;
    vector <string> lista;
	ifstream archivoIn;
	ofstream archivoOut;

	archivoIn.open(argv[1]/*"input1.txt"*/);
	archivoOut.open(argv[2]/*"mysolution1.txt"*/);
	archivoIn >> m >> n;
	for(int i=0;i<m;i++){
		archivoIn >> nombre;
		archivoIn >> num;
		diccionario.insert(pair<string, int>(nombre, num));
	}
	suma=0;
	contador=0;
	while(true){
		archivoIn >> palabra;
		if(palabra=="."){
			for(auto x:lista){
				if(diccionario.count(x)==1){
					auto y=diccionario.find(x);
					if(y!=diccionario.end()){
						suma=suma+y->second;
					}
				}
			}
			contador++;
			archivoOut<<suma<<endl;
			suma=0;
			lista.erase(lista.begin(), lista.end());
			descripcion="";
			if(contador==n){
				break;
			}
		}
		if(palabra!="."){
			descripcion+=palabra+" ";
			lista.push_back(palabra);
		}
	}
	return 0;
}
