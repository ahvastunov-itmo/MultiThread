

int eteration_count = 10000000000000000; // ���������� ��������
int a = 0;						 // ����� ������� ��������������
int b = 1;						 // ������ ������� ��������������

/*
�������� ������� ��� ����������
*/
double liner(double x){
	return x;
}

/*
 ��������� �������� �������� func  �� ������� [a,b] c ������ ��������� n
*/
double integrate(const double a, const double b, const int n){
	double step = (b - a) / n;

	double result = (liner(a) + liner(b))*step / 2;
	for (int i = 0; i < n; ++i){
		result += liner(a + i* step)*step;
	}

	return result;
}




