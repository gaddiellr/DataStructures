#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

template <class T>
void selectionSort(vector<T> &v, vector<int> &f, vector<int> &l) {
    int pos;
	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[j].substr(f[j],l[j]) > v[pos].substr(f[pos],l[pos])){
				pos = j;
			}
		}
		if (pos != i){
            T aux;
			aux=v[i];
			v[i]=v[pos];
			v[pos]=aux;
		}
	}
}
