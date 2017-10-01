//
//  ranged_number.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/25/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef ranged_number_hpp
#define ranged_number_hpp

#include <algorithm>
#include <stdio.h>

namespace BitmapGraphics
{
    // inlcuding clamp implementation in namespace, for compilers < C++17
    template<typename T>
    inline const T clamp(const T& val, const T& lo, const T& hi)
    {
        T temp = val > lo ? val : lo;
        return temp < hi ? temp : hi;
    }
    
    // number class that clamps on loLimit and hiLimit
    template<class Number_t, Number_t loLimit, Number_t hiLimit>
    class ranged_number
    {
    public:
        ranged_number(const Number_t& src = 0)
            : myLoLimit(loLimit), myHiLimit(hiLimit), myVal(src) {}
        ~ranged_number() = default;
        
        operator Number_t() const {return myVal;}
        void operator=(const Number_t& src) {myVal = clamp(src, myLoLimit, myHiLimit);}
        
        void operator++() {myVal = clamp(++myVal, myLoLimit, myHiLimit);}
        Number_t operator++(int)
        {
            Number_t temp = myVal;
            myVal = clamp(++myVal, myLoLimit, myHiLimit);
            return temp;
        }
        
        void operator--() {myVal = clamp(--myVal, myLoLimit, myHiLimit);}
        Number_t operator--(int)
        {
            Number_t temp = myVal;
            myVal = clamp(--myVal, myLoLimit, myHiLimit);
            return temp;
        }
        
        ranged_number<Number_t, loLimit, hiLimit>& operator+=(const Number_t& rhs)
        {
            myVal += rhs;
            myVal = clamp(myVal, myLoLimit, myHiLimit);
            return *this;
        }
        
        ranged_number<Number_t, loLimit, hiLimit>& operator-=(const Number_t& rhs)
        {
            myVal -= rhs;
            myVal = clamp(myVal, myLoLimit, myHiLimit);
            return *this;
        }
        
    private:
        Number_t myLoLimit;
        Number_t myHiLimit;
        Number_t myVal;
    };
    
}

#endif /* ranged_number_hpp */
