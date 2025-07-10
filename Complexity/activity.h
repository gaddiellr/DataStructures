// Funciones de sumatoria de 1 hasta n
// Gaddiel Lara Roldán A01704231
// 27/08/2022

#ifndef ACTIVITY_H
#define ACTIVITY_H

// función: sumatoria de 1 hasta n con un metodo iterativo
// parámetro: un entero positivo n
// salida: la sumatoria de 1 hasta n
unsigned int sumaIterativa ( unsigned int n ) {      
	int suma = 0 ;                                    //    O(1)
	for (int i = 1 ; i <= n ; i++ ) {                 //    O(n)
		suma += i ;
	}
	return suma ;                                     //    O(1)
}
// Complejidad: O(1)+O(n)+O(1) = O(n)+O(2)


// función: sumatoria de 1 hasta n con un metodo recursivo
// parámetro: un entero positivo n
// salida: la sumatoria de 1 hasta n
unsigned int sumaRecursiva ( unsigned int n ) {
	if ( n == 0 ) {                                   //    O(1)
		return 0 ;                         
	}
	else return n + sumaRecursiva ( n - 1 ) ;         //    O(1)
}
// Complejidad: O(1)+O(1) = O(2)


// función: sumatoria de 1 hasta n con un metodo matemático directo
// parámetro: un entero positivo n
// salida: la sumatoria de 1 hasta n
unsigned int sumaDirecta ( unsigned int n ) {        
	return n * ( n + 1 ) / 2 ;                        //    O(1)
}
// Complejidad: O(1)

#endif /* ACTIVITY_H */
