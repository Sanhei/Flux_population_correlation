/*
 * This is followed idea of Microscopic population dynamics, in a suitably
 * corse-grained system.
 */

#include <iostream>
#include <cmath>
#include "heaviside.cpp"
#include "fourier.cpp"
#include <vector>
#include <fftw3.h>
#define REAL 0
#define IMAG 1

class Fluctuation_Correlation
{
public:
        Fluctuation_Correlation(std::vector<double>& traj)
                : traj_(traj)
        {}
        double* population_fluctuation();
        double* correlation(double* population);


private:
        std::vector<double> traj_;

};

double* Fluctuation_Correlation::population_fluctuation()
{
        double* arr = traj_.data();
        for(size_t i=0; i<traj_.size(); i++)
        {
                // Transfer to heaviside function, in our model, boundary is 0
                arr[i] = heaviside(traj_[i], 0);
                // Population calculation
                // δH(t) = H(q(t))-<H>, <H> is equilibrium population, which is 0.5
                arr[i] -= 0.5;
        }
        return arr;
}

double* Fluctuation_Correlation::correlation(double* population)
{
        // Fourier transfer population
        // Here we only use one array, in order to save memory
        fftw_complex* Cor;
        Cor = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*traj_.size());
        fft(population, Cor, traj_.size());
        std::cout<<"Correlation calculation begin"<<std::endl;
        for(size_t i = 0; i<traj_.size(); i++)
        {
                Cor[i][REAL] = (Cor[i][REAL]*Cor[i][REAL]  +Cor[i][IMAG]*Cor[i][IMAG])/traj_.size();
                Cor[i][IMAG] = (-Cor[i][REAL]*Cor[i][IMAG] + Cor[i][IMAG]*Cor[i][REAL])/traj_.size();
        }
        ifft(Cor, Cor, traj_.size());
        double* correlation = new double[traj_.size()];
        for(size_t i=0; i<traj_.size(); i++)
        {
                correlation[i] = Cor[i][REAL]/(double)(traj_.size()*0.25);
        }
        std::cout<<"Correlation calculation ends"<<std::endl;
        fftw_free(Cor);
        return correlation;
}
