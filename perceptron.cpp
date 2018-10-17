#include <iostream>
#include <math.h>
#include <iomanip>
#include "perceptron.hpp"

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

void print(const vector<float> &m, int n_rows, int n_columns)
{

    for (int i = 0; i != n_rows; ++i)
    {
        for (int j = 0; j != n_columns; ++j)
        {
            cout << m[i * n_columns + j] << " ";
        }
        cout << '\n';
    }
    cout << endl;
}

void print_weight(const vector<float> w)
{

    for (int i = 0; i != w.size(); ++i)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << w[i] << " ";
    }
    cout << endl;
}

void learn(vector<float> X, vector<float> y, vector<float> W)
{
    for (unsigned i = 0; i != 5; ++i)
    {
        vector<float> pred = sigmoid(dot(X, W, 3, 5, 1));
        vector<float> pred_error = y - pred;
        vector<float> pred_delta = pred_error * sigmoid_d(pred);
        vector<float> W_delta = dot(transpose(&X[0], 3, 5), pred_delta, 3, 5, 1);
        W = W + W_delta;
        print_weight(W);
        if (i == 4)
        {
            print(pred, 5, 1);
        };
    };
}