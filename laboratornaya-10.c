#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define ERR_NOT_DEFINE 0xAAAA

int Task1();
double fa(double x);
double fb(double x);

int Task2();
double sin_n(double x, int N);
double sin_eps(double x, double eps);

int main()
{
	setlocale(LC_CTYPE, ".UTF-8");

	//Task1();
	Task2();

	return 0;
}

int Task1()
{
	double x, a, b;
	int num;

	printf("Введите значение x = ");
	scanf("%lf", &x);

	printf("\nМЕНЮ\n");
	printf("1 - значение функции\n");
	printf("2 - произведение\n");
	printf("3 - разность квадратов\n");
	printf("4 - удвоенная сумма\n");

	printf("\nВыберите действе 1, 2, 3 или 4\n");
	scanf("%d", &num);

	switch(num)
	{
		case 1:
			printf("fa(x) = %f \nfb(x) = %f", fa(x), fb(x));
			break;
		case 2:
			printf("\n%lf * %lf = %lf", fa(x), fb(x), fa(x) * fb(x));
			break;
		case 3:
			printf("\n%lf^2 - %lf^2 = %lf", fa(x), fb(x), fa(x) * fa(x) - fb(x) * fb(x));
			break;
		case 4:
			printf("\n2 * (%lf + %lf) = %lf", fa(x), fb(x), 2 * (fa(x) + fb(x)));
			break;
	}
}

double fa(double x)
{
	double a;

	if (x <= 3)
	{
		a = x * x - 3 * x + 9;
	}
	else
	{
		a = 1 / (x * x * x + 3);
	}
	return a;
}
double fb(double x)
{
	double b;
	
	b = 1 * exp(sin(x * x));

	return b;
}

int Task2()
{
	double x, eps;
	printf("Введите значение x в радианах\nx = ");
	scanf("%lf", &x);

	printf("\nВведите точность eps = ");
	scanf("%lf", &eps);
	
	double std_sin = sin(x);
	double eps_sin = sin_eps(x, eps);

	printf("\nСтандартная функция sin(x) = %lf", std_sin);
	printf("\nЧерез ряд с точностью eps = %lf", eps_sin);

	printf("\n  N |     sin_N   | отклонение\n\n");
	for (int n = 1; n <= 15; n++)
	{
		double s_n = sin_n(x, n);
		double diff = std_sin - s_n;
		printf(" %2d |   %7.3f   | %10.3le\n", n, s_n, diff);
	}
}

double sin_n(double x, int N)
{
	double sum = 0;
	double t = x;

	for (int k = 1; k <= N; k++)
	{
		sum += t;
		t *= -1 * x * x / ((2 * k) * (2 * k + 1));
	}
	return sum;
}

double sin_eps(double x, double eps)
{
	double sum = 0;
	double t = x;
	int k = 1;

	while (fabs(t) > eps)
	{
		sum += t;
		t *= -1 * x * x / ((2 * k) * (2 * k + 1));
		k++;
	}
	return sum;
}
