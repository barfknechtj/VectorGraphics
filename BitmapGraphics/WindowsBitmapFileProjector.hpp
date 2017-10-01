//
//  WindowsBitmapFileProjector.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef WindowsBitmapFileProjector_hpp
#define WindowsBitmapFileProjector_hpp

#include <stdio.h>
#include <string>
#include "CodecLibrary.hpp"
#include "ICanvas.hpp"
#include "IProjector.hpp"

namespace BitmapGraphics
{
    class WindowsBitmapFileProjector : public IProjector
    {
    public:
        WindowsBitmapFileProjector(const std::string& filename,
                                   CodecLibrary& codecLibrary);
        ~WindowsBitmapFileProjector() = default;
        
        WindowsBitmapFileProjector(const WindowsBitmapFileProjector& src) = default;
        WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector& src) = default;
        WindowsBitmapFileProjector(WindowsBitmapFileProjector&& src) = default;
        WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&& src) = default;
        
        virtual void projectCanvas(HCanvas const& canvas);
        
    private:
        std::string myFilename;
        CodecLibrary myCodecLibrary;
    };
}

#endif /* WindowsBitmapFileProjector_hpp */
