//
//  IBitmapDecoder.h
//  Assignment2
//
//  Created by Jared Barfknecht on 9/4/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IBitmapDecoder_h
#define IBitmapDecoder_h

namespace BitmapGraphics
{
    class IBitmapDecoder;
    using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
    
    class IBitmapDecoder
    {
    public:        
        virtual ~IBitmapDecoder() = default;
        virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
        virtual HBitmapIterator createIterator() = 0;
        virtual void setMimeType(const std::string& mimeType) = 0;
        virtual std::string getMimeType() const = 0;
        virtual bool isSupported(std::istream& sourceStream) const = 0;
    };
}


#endif /* IBitmapDecoder_h */
