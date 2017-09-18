//
//  IProjector.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IProjector_hpp
#define IProjector_hpp

#include <stdio.h>

namespace BitmapGraphics
{
    class IProjector
    {
    public:
        virtual ~IProjector() = default;
        
        virtual void projectCanvas(HCanvas const& canvas) = 0;
    };
    
    using HProjector = std::shared_ptr<IProjector>;
}

#endif /* IProjector_hpp */
