#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

vector<float> sigmoid_d(const vector<float> &m1)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> output(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        output[i] = m1[i] * (1 - m1[i]);
    }

    return output;
}

vector<float> sigmoid(const vector<float> &m1)
{

    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> output(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        output[i] = 1 / (1 + exp(-m1[i]));
    }

    return output;
}

vector<float> operator+(const vector<float> &m1, const vector<float> &m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> sum(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        sum[i] = m1[i] + m2[i];
    };

    return sum;
}

vector<float> operator-(const vector<float> &m1, const vector<float> &m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> difference(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        difference[i] = m1[i] - m2[i];
    };

    return difference;
}

vector<float> operator*(const vector<float> &m1, const vector<float> &m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> product(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        product[i] = m1[i] * m2[i];
    };

    return product;
}

vector<float> transpose(float *m, const int C, const int R)
{
    vector<float> mT(C * R);

    for (unsigned n = 0; n != C * R; n++)
    {
        unsigned i = n / C;
        unsigned j = n % C;
        mT[n] = m[R * j + i];
    }

    return mT;
}

vector<float> dot(const vector<float> &m1, const vector<float> &m2, const int m1_rows, const int m1_columns, const int m2_columns)
{

    vector<float> output(m1_rows * m2_columns);

    for (int row = 0; row != m1_rows; ++row)
    {
        for (int col = 0; col != m2_columns; ++col)
        {
            output[row * m2_columns + col] = 0.f;
            for (int k = 0; k != m1_columns; ++k)
            {
                output[row * m2_columns + col] += m1[row * m1_columns + k] * m2[k * m2_columns + col];
            }
        }
    }

    return output;
}

void log(vector<float> w, vector<float> h, vector<float> y)
{

    for (int i = 0; i < w.size(); i++)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << w[i] << " ";
    }
    float c = 0;
    for (int i = 0; i < h.size(); i++)
    {
        if (h[i] == y[i])
            c++;
    }
    cout << c / h.size();
    cout << endl;
}