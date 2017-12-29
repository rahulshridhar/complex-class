#include "complex.h"

complex::complex()
{
    x = 0;
    y = 0;
    complex_number=NULL;
    set_string();
}

complex::complex(int r)
{
    x = r;
    y = 0;
    complex_number=NULL;
    set_string();
}

complex::complex(int r, int i)
{
    x = r;
    y = i;
    complex_number=NULL;
    set_string();
}

void complex::_copy(const complex& from)
{
    int l = strlen(from.complex_number) + 1;
    complex_number = new char[l];
    strcpy(complex_number, from.complex_number);
}

complex::complex(const complex& c2)
{
    x = c2.x;
    y = c2.y;
    if (complex_number != NULL) delete [] complex_number;
    _copy(c2);
}

complex::~complex()
{
    delete [] complex_number;   
}

void complex::setxy(int r, int i)
{
    x = r;
    y = i;
    if (complex_number != NULL) delete [] complex_number;
    set_string();
}

void complex::set_string() 
{
    int string_length = 0, real_digits = 0, imag_digits = 0;
    int real_number = x;
    int imag_number = y;
    do {
        real_number /= 10;
        string_length++;
    } while (real_number != 0);
    real_digits = string_length;

    do {
        imag_number /= 10;
        string_length++;
    } while (imag_number != 0);
    imag_digits = string_length - real_digits;
    
    if (real_number < 0) string_length++;
    string_length += 2;     // for 'j' & sign of imaginary part

    complex_number = new char[string_length];

    // Convert the real part to a char*
    char imag_string[imag_digits], real_string[real_digits];
    sprintf(real_string, "%d", x);

    strcat(complex_number, real_string);

    if (y == 0) return;
    if (y < 0) strcat(complex_number, "-");
    else strcat(complex_number, "+");

    strcat(complex_number, "j");
    
    // Convert the imaginary part to a char*
    int _y;
    if (y<0) _y = y * -1;
    else _y = y;
    sprintf(imag_string, "%d", _y);

    strcat(complex_number, imag_string);
}

// Overload the == operator for complex
bool complex::operator==(complex &c2)
{
    if (x == c2.x && y == c2.y) return true;
    else return false;
}

// Overload the != operator for complex
bool complex::operator!=(complex &c2)
{
    if (x != c2.x || y != c2.y) return true;
    else return false;
}

// Overload the = operator to complex
complex& complex::operator=(complex &c2)
{
    x = c2.x;
    y = c2.y;
    delete [] complex_number;
    _copy(c2);
    return (*this);
}

// Overload the << operator to complex
ostream& operator<<(std::ostream &out, const complex& comp)
{
    out << comp.complex_number;
    return out;
}


