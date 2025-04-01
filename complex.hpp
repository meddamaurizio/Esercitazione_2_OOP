#pragma once

/* Complex Class */
template<typename T> requires std::floating_point <T>
class complex {
    
    T Re, Im;


    public:
    // costruttore default
    complex()
        : Re(0), Im(0)
    {}

    // costruttore 2 var
    complex (T a, T b)
        : Re(a), Im(b)
    { }

    // costruttore 1 var -convertitore
    complex (T a)
        : Re(a), Im(0)
    {}

    /// @brief Restituisce parte immaginaria
    /// @param  n/a
    /// @return <T> Re
    T real(void) const {
        return Re;
    }

    /// @brief Restituisce parte immaginaria
    /// @return <T> Im
    T imgn(void) const {
        return Im;
    }

    /// @brief Restituisce il complesso coniugato
    /// @param  n/a
    /// @return complex Re - i * Im
    complex conj(void) {
        return complex(Re, -Im);
    }

    complex& operator+=(const complex& other) {
        Re = Re + other.Re;
        Im = Im + other.Im;
        return *this;
	}

    complex& operator-=(const complex& other) {
        *this+= -other;
        return *this;
	}


    complex& operator*=(const complex& other) {
        // (a + ib)*(c + id) = (ac-bd) + i*(ad + bc)
        Re = Re * other.Re - Im * other.Im;
        Im = Re * other.Im + Im * other.Re;
        return *this;
	}

   
    complex operator-() const {
        return complex(-Re, -Im);
    }

    complex operator+(const complex& other) const {
        complex res = *this;
        res += other;
        return res;
    }

    complex operator-(const complex& other) const {
        complex res = *this;
        res -= other;
        return res;
    }

    complex operator*(const complex &other) const {
        complex res = *this;
        res *= other;
        return res;
    }

};


// OVERLOAD

// SOMMA CON <T>

template<typename T>
complex<T>
operator+(const T& t, const complex<T>& c)
{
    return c + t;
}

// prodotto

// OUTPUT
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& aib ) {
    // questo può non essere corretto in caso 
    // di iomanip sui segni.
    os << aib.real();
    if (aib.imgn()>0) { os << "+";}
    os << aib.imgn()<<"i";
    return os;
}
