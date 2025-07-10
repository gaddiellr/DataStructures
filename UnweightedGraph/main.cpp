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
#include "ugraph.h"

using namespace std;

int main(/**/int argc, char *argv[]/**/){
    int nC, nQ, NMP;
    string puerto1, puerto2, puertoInicio;
    UListGraph<string> graph(0);
	ifstream archivoIn;
	ofstream archivoOut;
	archivoIn.open(argv[1]/*"input2.txt"*/);
	archivoOut.open(argv[2]/*"mysolution2.txt"*/);
	archivoIn >> nC;
	for (int i = 0; i < nC; i++) {
		archivoIn >> puerto1 >> puerto2;
		graph.addEdge(puerto1, puerto2);
	}
	archivoIn >> nQ;
	for (int i = 0; i < nQ; i++) {
		archivoIn >> puertoInicio >> NMP;
		archivoOut << "Case " << i + 1 << ": " << consulta(puertoInicio, graph, NMP)<< " ports not reachable from port " << puertoInicio << " with NMP = "<< NMP << "." << endl;
	}
	return 0;
}
