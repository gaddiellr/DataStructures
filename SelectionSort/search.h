#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

template <class T>
void binarySearch(vector<T> &r,vector<T> &v,vector<int> &f,vector<int> &l,string menor,string mayor) {
    int index = -1;
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = low + ((high - low) / 2);
		if (v[mid].substr(f[mid],l[mid])>=menor&&v[mid].substr(f[mid],l[mid])<=mayor) {
            index = mid;
			break;
		}
		else if (menor < v[mid].substr(f[mid],l[mid])) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	while (v[index].substr(f[index],l[index])>=menor){
        r.insert(r.begin(),v[index]);
        index--;
	}
	index+=r.size()+1;
    while (v[index].substr(f[index],l[index])<=mayor){
        r.push_back(v[index]);
        index++;
    }
}
