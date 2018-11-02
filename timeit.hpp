#include <chrono>
#include <utility>
using namespace std;

typedef chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) chrono::duration_cast<chrono::nanoseconds>(a).count()
#define timeNow() chrono::high_resolution_clock::now()

template <typename F, typename... Args>
double measure(F func, Args &&... args)
{
    TimeVar t1 = timeNow();
    func(forward<Args>(args)...);
    return duration(timeNow() - t1);
}