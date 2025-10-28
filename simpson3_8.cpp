#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1 / (1 + x * x);
}

int main()
{
    double a = 0, b = 1;
    int n = 6;
    double h = (b - a) / n;
    cout << fixed << setprecision(6);

    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            double x = a + i * h;
            sum += 2* f(x);
        }
        else
        {
            double x = a + i * h;
            sum += 3 * f(x);
        }
    }

    double result = (3*h / 8) * sum;
    cout << "Approximate Integral = " << result << endl;

    return 0;
}
