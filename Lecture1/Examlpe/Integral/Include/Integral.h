

int eteration_count = 10000000000000000; // количество итераций
int a = 0;						 // лева€ граница интегрировани€
int b = 1;						 // права€ граница интегрировани€

/*
линейна€ функци€ дл€ интеграции
*/
double liner(double x){
	return x;
}

/*
 ¬ычисл€ем интеграл функциии func  на отрезке [a,b] c числом разбиений n
*/
double integrate(const double a, const double b, const int n){
	double step = (b - a) / n;

	double result = (liner(a) + liner(b))*step / 2;
	for (int i = 0; i < n; ++i){
		result += liner(a + i* step)*step;
	}

	return result;
}




