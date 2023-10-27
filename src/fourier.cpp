/*
 * Give any one dimensional trajectory should transfer to the array for correlation calculation.
 */
#include <fftw3.h>
#include <iostream>
#include <vector>

void fft(double* in, fftw_complex *out, int N){
        // N is for the length of the output
        std::cout<<"Fourier transform begin"<<std::endl;
        fftw_plan plan = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
        fftw_execute(plan);
        fftw_destroy_plan(plan);
        fftw_cleanup;
        std::cout<<"Fourier transform done"<<std::endl;
}


void ifft(fftw_complex* in, fftw_complex *out, int N){
        std::cout<<"Reverse Fourier begin"<<std::endl;
        fftw_plan plan = fftw_plan_dft_1d(N, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
        fftw_execute(plan);
        fftw_destroy_plan(plan);
        fftw_cleanup;
        std::cout<<"Reverse Fourier done" <<std::endl;
}
