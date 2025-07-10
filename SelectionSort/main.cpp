// =================================================================
//
// File: main.cpp
// Author: Gaddiel Lara Roldán
// Date: 09/10/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include "sort.h"
#include "search.h"
using namespace std;

int main() {
    int columna=0;
    string menor;
    string mayor;
    string linea;
    int startIp=0;
    int endIp=0;
    vector<string> vLinea;
	vector<int> vStartIp;
	vector<int> vEndIp;
    vector<string> vSearchResult;
	ifstream archivoLeer("bitacora.txt");
	while (getline(archivoLeer,linea)) {
        for (int i=0;i<linea.length();i++){
            if (columna<3){
                startIp++;
            }
            if (linea[i]==' '){
                columna++;
            }
            if (columna<4){
                endIp++;
            }
        }
        vLinea.push_back(linea);
        vStartIp.push_back(startIp);
        vEndIp.push_back(endIp);
        columna=0;
        startIp=0;
        endIp=0;
	}
	selectionSort(vLinea,vStartIp,vEndIp);
	ofstream archivoEscribir("ordenamiento.txt");
    for (auto i=vLinea.begin();i!=vLinea.end();i++){
        archivoEscribir<<*i<<endl;
    }
    cout<<"Ingresar IP de inicio de búsqueda"<<endl;
    cin>>menor;
    cout<<"Ingresar IP de fin de búsqueda"<<endl;
    cin>>mayor;
    while(mayor<=menor){
        cout<<"ERROR... Ingresar IP de fin mayor que IP de inicio"<<endl;
        cin>>mayor;
    }
    binarySearch(vSearchResult,vLinea,vStartIp,vEndIp,menor,mayor);
    if (vSearchResult.size()==0){
        cout<<"Sin resultados"<<endl;
    }
    else{
        cout<<endl<<"Resultados:"<<endl;
        for (auto i=vSearchResult.begin();i!=vSearchResult.end();i++){
            cout<<*i<<endl;
        }
    }
	return 0;
}
