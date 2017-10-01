//
//  IBitmapEncoder.h
//  Assignment2
//
//  Created by Jared Barfknecht on 9/4/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IBitmapEncoder_h
#define IBitmapEncoder_h

namespace BitmapGraphics
{
    class IBitmapEncoder;
    using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
    
    class IBitmapEncoder
    {
    public:
        virtual ~IBitmapEncoder() = default;
        virtual HBitmapEncoder clone(HBitmapIterator& hBitmapIter) = 0;
        virtual void encodeToStream(std::ostream& destinationStream) = 0;
        virtual std::string getMimeType() const = 0;
    };
}

#endif /* IBitmapEncoder_h */
