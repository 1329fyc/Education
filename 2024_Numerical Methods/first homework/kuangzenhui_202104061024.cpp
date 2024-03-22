/***������ 202104061024***/
#include <iostream>
#include <vector>
using namespace std;

int main() {

	double Lagrange(vector<double>, vector<double>, double, double);
	int n;	//��Ͻ״�
	double num;	//ҪԤ����
	double temp;	
	vector<double> X;	//��ֵ��
	vector<double> Y;

	cin >> n >> num;
	while (cin >> temp) {
		X.push_back(temp);
		if (cin.get() == '\n') break;
	}
	while (cin >> temp) {
		Y.push_back(temp);
		if (cin.get() == '\n') break;
	}
	
	cout << "����Ԥ����Ϊ: " << Lagrange(X, Y, n, num) << endl;

	return 0;

}

double Lagrange(vector<double> X, vector<double> Y, double n, double num) {
	
	//cout << (sizeof(X) / sizeof(X[0])) << endl << (sizeof(Y) / sizeof(Y[0]));

	if (X.size() != Y.size()) {
		return -1;
	}
	if (X.size() <= n) {
		return -1;
	}
	
	vector<double> l;
	for (int i = 0; i <= n; ++i) {
		double temp1 = 1;
		for (int j = 0; j <= n; ++j) {
			if (j == i) continue;

			temp1 = temp1 * ((num - X[j]) / (X[j] - X[i]));
		}
		l.push_back(temp1);
	}

	double L = 0;
	for (int k = 0; k <= n; ++k) {
		L = L + l[k] * Y[k];
	}

	return L;

}
