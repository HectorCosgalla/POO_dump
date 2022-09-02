#include <stdio.h>

struct racional {
private:
	int numerador;
	int denominador;
public:
	void imprimir();
	void asignar(int n, int d);
	racional sumarRacionales(racional b);
	racional restarRacionales(racional b);
	racional multiplicarRacionales(racional b);
	racional dividirRacionales(racional b);
	void simplificarRacional();
};

racional racional::sumarRacionales(racional b){
	racional q;
	q.numerador = (numerador * b.denominador) + (denominador * b.numerador);
	q.denominador = denominador * b.denominador;
	q.simplificarRacional();
	return q;
}

racional racional::restarRacionales(racional b){
	racional q;
	q.numerador = (numerador * b.denominador) - (denominador * b.numerador);
	q.denominador = denominador * b.denominador;
	q.simplificarRacional();
	return q;
}

racional racional::multiplicarRacionales(racional b){
	racional q;
	q.numerador = numerador * b.numerador;
	q.denominador = denominador * b.denominador;
	q.simplificarRacional();
	return q;
}

racional racional::dividirRacionales(racional b){
	racional q;
	q.numerador = numerador * b.denominador;
	q.denominador = denominador * b.numerador;
	q.simplificarRacional();
	return q;
}

void racional::simplificarRacional(){
	int numerosPrimos[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	if (numerador == denominador){
		numerador /= denominador;
		denominador /= denominador;
	}else{
		for (int i = 0; i < 25; i++){
			while (numerador%numerosPrimos[i] == 0 && denominador%numerosPrimos[i] == 0){
				numerador /= numerosPrimos[i];
				denominador /= numerosPrimos[i];
			}
		}
	}
	return;
}

void racional::imprimir() {
	printf("%d/",numerador);
	printf("%d\n",denominador);
};

void racional::asignar(int n, int d) {
	numerador= n;
	denominador=d;
};

int main() {
	racional r, x, suma, resta, multiplicacion, division;
	r.asignar(1,2);
	x.asignar(1,4);
	suma = r.sumarRacionales(x);
	suma.imprimir();
	resta = r.restarRacionales(x);
	resta.imprimir();
	multiplicacion = r.multiplicarRacionales(x);
	multiplicacion.imprimir();
	division = r.dividirRacionales(x);
	division.imprimir();
} ///:~
