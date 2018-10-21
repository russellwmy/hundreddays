#include <complex>
#include <valarray>
#include <vector>
#include "linearithmic_multiplication.hpp"

const double PI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

CArray operator*(const CArray &m1, const CArray &m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    CArray product(VECTOR_SIZE);

    for (unsigned i = 0; i != VECTOR_SIZE; ++i)
    {
        product[i] = m1[i] * m2[i];
    };

    return product;
}

void fft(CArray &x)
{
    const size_t N = x.size();
    if (N <= 1)
        return;

    // divide
    CArray even = x[std::slice(0, N / 2, 2)];
    CArray odd = x[std::slice(1, N / 2, 2)];

    // conquer
    fft(even);
    fft(odd);

    // combine
    for (size_t k = 0; k < N / 2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}


// inverse fft (in-place)
void ifft(CArray &x)
{
    x = x.apply(std::conj);
    fft(x);
    x = x.apply(std::conj);
    x /= x.size();
}

CArray zeros(int n)
{
    CArray arr;
    arr[0] = 1.0;
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0.0;
    }
    return arr;
}

std::string reversed(std::string arr)
{
    char temp, i;
    int count = arr.length();
    
    for (i = 0; i < count / 2; ++i)
    {
        temp = (int)arr[count - i - 1];
        arr[count - i - 1] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

void mult(std::string x, std::string y)
{
    int nx = x.length();
    int ny = y.length();

   
    CArray fx = zeros(nx * ny);
    CArray fy = zeros(nx * ny);

    std::string tmp;
    tmp = reversed(x);
    for (int i = 0; i < tmp.length(); i++)
    {
        fx[i] = (int)tmp[i];
    }
    tmp = reversed(y);
    for (int i = 0; i < tmp.length(); i++)
    {
        fy[ny + i] = (int)tmp[i];
    }
    // convolution via FFT
    fft(fx);
    fft(fy);
    CArray z = fx * fy;
    ifft(z);

    for (int i = 0; i < nx + ny - 1; i++)
    {
        z[i + 1] =  z[i + 1] + z[i] / 10.0;
        z[i] =  ((int)z[i].real()) % 10;
    }
    for (int i = 0; i < nx + ny - 1; i++)
    {
        std::cout << x[i];
    }
}
