// This script is used to define matrix and vectors for the GN algorithm

#ifndef CPPGN_TYPES
#define CPPGN_TYPES

#include <Eigen/Dense>
#include <functional>

namespace cpp_GN {
    
    /** Default precision */
    typedef float Scalar;
    
    /** Shortcut for scalar */
    typedef Scalar S;
    
    /** Default matrix type */
    typedef Eigen::Matrix< Scalar, Eigen::Dynamic, Eigen::Dynamic > Matrix;
    
    /** Default vector type */
    typedef Eigen::Matrix< Scalar, Eigen::Dynamic, 1 > Vector;
    
    /** Function prototype */
    typedef std::function< Matrix(const Matrix &x) > F;

    /** Compution result info */
    enum ResultInfo {
        SUCCESS,
        ERROR
    };

    /** Dimensions of function inputs and outputs */
    struct Dims {
        int x_rows;
        int x_cols;
        int y_rows;
        int y_cols;

        inline Dims(int x_rows_, int x_cols_, int y_rows_, int y_cols_)
            :x_rows(x_rows_), x_cols(x_cols_), y_rows(y_rows_), y_cols(y_cols_)
        {}
    };
}

#endif