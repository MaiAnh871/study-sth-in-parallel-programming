#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    double itime, ftime, exec_time;
    itime = omp_get_wtime();

    for (long i = 0; i < 1000000; i++)
    {
        long m, k = 100;
        for (int j = 0; j < 100; j++)
        {
            m = k * j;
        }
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\nTime taken (without #pragma) is %f seconds\n\n", exec_time);

    return 0;
}
