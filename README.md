# Flux_population_correlation
Explore the chemical reaction time and theory

## Population dynamics
From the beginning of two coarse-graining states (A, B) reaction kinetics for the continuum of population dynamics:

$$\dot{P_A}(t) = -k_{AB}P_A+k_{BA}P_B $$

$$\dot{P_B}(t) = k_{AB}P_A - k_{BA}P_B $$

here, P is the concentration, and $k_{AB}$ means the reaction rate from state A to B, and vice versa.
The phenomenological relaxation is:
$$\delta P_A(t)=P_A(t)-\langle P_A \rangle$$

A Heaviside function gives the microscopic population operator:

$$ H_B\lbrack Q(t)\rbrack= \Huge\lbrace \normalsize \matrix{ 1, & Q(t) \geq Q* \cr 0, & Q(t) < Q* }  $$

$Q*$ donates the coarse-graining state boundary, and hence microscopic fluctuations in the population are 

$$ \delta H_B(t)= H_B\lbrack Q(t) \rbrack -\langle H_B \rangle $$

Then microscopic fluctuation correlation is

$$ C_{HH}(t)=\langle \delta H_B(0) \delta H_B(t)\rangle$$

## Example
![alt text](https://github.com/Sanhei/Flux_population_correlation/blob/main/m_0.001_gamma_0.001.svg?raw=true)




## Usage
Based on C++, need to install fftw3 to do Fourier transform.
```
mkdir build & cd build
cmake ..
make -j4
cd src
./flux_correlation --filepath $your trajectory$ --timestep $your simulation timestep$
```
will generate a "corhh.txt" in the directory /build/src/.

## Correction term
For fourier transform, the unify could always use 

$$ C_{HH}'(t)=\frac{C_{HH}(t)}{C_{HH}(0)} $$
