#ifndef CPPGN_GAUSS_NEWTON
#define CPPGN_GAUSS_NEWTON

#include "types.h"

namespace cpp_GN {
    
    /*  Performs one step of non-linear least squares optimization using the Gauss-Newton algorithm.
     *
     *  The Gauss-Newton method is an approximation to the Newton method for the special case of 
     *  non-linear least squares. Newton's method, in case of optimization, is given by
     *
     *  x_n+1 = xn - grad(f(xn))*H(f(xn))
     *
     *  Evaluating the Hessain matrix,H, at the residual is computationally expensive. Instead we turn 
	 *  the Gauss-Newton algorithm.
     *
     *  The Gauss-Newton avoids direct calculation of the Hessian matrix and instead approximates
     *  the Hessian matrix.
     *
     *  \parameter  f Function object evaluating the residuals at x.
     *              Input: variables given as vector of size Nx1.
     *              Output: function values given as vector of size Mx1.
     *  \parameter  d First order partial derivatives of f at x.
     *              Input: variables given as vector of size Nx1.
     *              Output: all partial derivates of f at x given as matrix of size MxN.
     *  \parameter x Variables of function f given as vector of size Nx1 vector. Will be updated in case of success.
     *  \return Status indicating success or failure due to ill-conditioned input.
     */
	 
    ResultInfo gaussNewton(const F &f, const F &d, Matrix &x) {
        Matrix j = d(x);
        
        // Make sure we have more functions than variables.
        assert(j.rows() >= j.cols());
        
        Matrix jt = j.transpose();
        Matrix y = f(x);

        auto llt = (jt * j).ldlt();
        if (llt.info() != Eigen::Success) {
            return ERROR;
        }

        Matrix s = llt.solve(jt * y * Scalar(-1));        
        x = x + s;

        return SUCCESS;
    }
}

#endif