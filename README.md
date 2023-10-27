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
\[
f(x) = 
\begin{cases}
    x^2 & \text{if } x > 0 \\
    0 & \text{if } x = 0 \\
    -x^2 & \text{if } x < 0
\end{cases}
\]
