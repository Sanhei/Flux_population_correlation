/* According to the chemical coordination, there is a
 * Chemical boundary (normally the barrier top), if the
 * it is over the boundary, then it is 1, otherwise it 
 * is 0
 * H(q)=1, q>q*
 *     =0, q<q*
 */
double heaviside(double q, double qb)
{
        if(q>=qb)
                return 1;
        else
                return 0;
}
