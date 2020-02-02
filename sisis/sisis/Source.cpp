#include <iostream>
#include <corecrt_math_defines.h>
#include <cmath>

using namespace std;

const float pi = 3.14;


void idealLPF(int tap, float lambda)
{
	int n;
	float m, h[100];

	cout << "Koefisien filter LPF dengan frekuensi cut off " << lambda << " adalah : " << endl;
	for (n = 0; n < tap; n++)
	{
		m = n - (float)(tap - 1) / 2.0;
		if (m == 0)
			h[n] = lambda / pi;
		else
			h[n] = sin(m * lambda) / (m / pi);

		cout << "h[" << n << "] = " << h[n] << endl;

	}
}

void idealHPF(int tap, float lambda)
{
	int n;
	float m, h[100];

	cout << "Koefisien filter LPF dengan frekuensi cut off " << lambda << " adalah : " << endl;
	for (n = 0; n < tap; n++)
	{
		m = n - (float)(tap - 1) / 2.0;
		if (m == 0)
			h[n] = 1 - (lambda / pi);
		else
			h[n] = -sin(m * lambda) / (m / pi);

		cout << "h[" << n << "] = " << h[n] << endl;

	}
}

void idealBPF(int tap, float lambda)
{
	int n;
	float lambda2 = 2 * lambda;
	float m, h[100];

	cout << "Koefisien filter LPF dengan frekuensi cut off " << lambda << " adalah : " << endl;
	for (n = 0; n < tap; n++)
	{
		m = n - (float)(tap - 1) / 2.0;
		if (m == 0)
			h[n] = (lambda2 - lambda) / pi;
		else
			h[n] = (1 / tap * pi) * (sin(m * lambda) - sin(m * lambda2));

		cout << "h[" << n << "] = " << h[n] << endl;

	}
}

void idealBSF(int tap, float lambda)
{
	int n;
	float lambda2 = 2 * lambda;
	float m, h[100];

	cout << "Koefisien filter LPF dengan frekuensi cut off " << lambda << " adalah : " << endl;
	for (n = 0; n < tap; n++)
	{
		m = n - (float)(tap - 1) / 2.0;
		if (m == 0)
			1 + ((lambda - lambda2) / 2);
		else
			h[n] = (1 / tap * pi)*(sin(m*lambda) - sin(m*lambda2));

		cout << "h[" << n << "] = " << h[n] << endl;

	}
}



void main()
{
	int tap, freqSamp, cutOff;
	float lambda;
	int pil;
	cout << "=================" << endl;
	cout << "Demo program FIR" << endl;
	cout << "=================" << endl;
	cout << "1. LPF\n2. HPF\n3. BPF\n4. BSF" << endl;
	cin >> pil;
	system("cls");
	cout << "Masukkan jumlah tap filter : " << endl;
	cin >> tap;
	cout << "Masukkan 1/2 frekuensi sampling : " << endl;
	cin >> freqSamp;
	cout << "Masukkan frekuensi cut-off filter : " << endl;
	cin >> lambda;

	//idealLPF(tap, lambda);
	switch (pil)
	{
	case 1:
		idealLPF(tap, lambda);
		break;
	case 2:
		idealHPF(tap, lambda);
		break;
	case 3:
		idealBPF(tap, lambda);
		break;
	case 4:
		idealBSF(tap, lambda);
		break;
	default:
		break;
	}
}