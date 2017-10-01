//
//  VerifyEquality.h
//  Assignment2
//
//  Created by Jared Barfknecht on 8/15/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef VerifyEquality_h
#define VerifyEquality_h

#include <stdexcept>

template<typename T>
void verifyEquality(const T& lhs, const T& rhs, const char* message)
{
    if (lhs != rhs) throw std::runtime_error(message);
}

template<typename T1, typename T2>
void verifyEquality(const T1& lhs, const T2& rhs, const char* message)
{
    if (lhs != rhs) throw std::runtime_error(message);
}

#endif /* VerifyEquality_h */
