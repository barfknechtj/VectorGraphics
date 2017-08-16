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

#endif /* VerifyEquality_h */
