#ifndef complex_H
#define complex_H

#include "../util/util.h"

class complex {
    private:
        int x;  //Real part of complex number
        int y;  //Imaginary part of complex number
        char* complex_number; // Contains the complex number x + iy  

    public:
        complex();
        complex(int r);
        complex(int r, int i);
        ~complex();
        complex(const complex& c2); 
        void _copy(const complex& c2);
        void setxy(int r, int i);
        void set_string();
        bool operator==(complex &c2);
        bool operator!=(complex &c2);
        complex& operator=(complex &c2);
        friend ostream& operator<<(std::ostream &out, const complex& comp);

};


#endif
