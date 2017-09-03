//
//  WindowsBitmapDecoder.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef WindowsBitmapDecoder_hpp
#define WindowsBitmapDecoder_hpp

#include <stdio.h>
#include <string>
#include <memory>
#include <fstream>
#include "BitmapIterator.hpp"
#include "WindowsBitmapHeader.hpp"
#include "Bitmap.hpp"


namespace BitmapGraphics
{
    class IBitmapDecoder
    {
    public:
        using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
        using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

        virtual ~IBitmapDecoder() = default;
        virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
        virtual HBitmapIterator createIterator() = 0;
        virtual void setMimeType(const std::string& mimeType) = 0;
        virtual std::string getMimeType() const = 0;
        virtual bool isSupported(std::istream& sourceStream) const = 0;
    };
    
    class WindowsBitmapDecoder : public IBitmapDecoder
    {
    private:
        using HBitmapHeader = std::shared_ptr<WindowsBitmapHeader>;
        using HBitmap = std::shared_ptr<Bitmap>;
        
        std::string myMimeType;
        HBitmap hBitmap;
    
    public:
        WindowsBitmapDecoder(HBitmap bitmap = nullptr);
        ~WindowsBitmapDecoder() = default;
        
        HBitmapDecoder clone(std::istream& sourceStream) override;
        HBitmapIterator createIterator() override;
        void setMimeType(const std::string& mimeType) override {myMimeType = mimeType;}
        std::string getMimeType() const override {return myMimeType;};
        bool isSupported(std::istream& sourceStream) const override;
    };
}


#endif /* WindowsBitmapDecoder_hpp */
