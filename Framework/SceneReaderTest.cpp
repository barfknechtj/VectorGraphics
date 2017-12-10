//
//  SceneReaderTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>

#include "XmlParse.hpp"
#include "Scene.hpp"
#include "SceneReader.hpp"
#include "TestHarness.h"
#include "XmlReader.hpp"
#include "BasicCanvas.hpp"
#include "WindowsBitmapFileProjector.hpp"
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "CodecLibrary.hpp"

const std::string TestXml = R"(
<Scene width="800" height="600">
    <Layer alias="sky">
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="true">
                <Point x="1" y="2" />
                <!-- Comment -->
                <Point x="3" y="4" />
                <Point x="5" y="6" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Comment -->
        <PlacedGraphic x="700" y="0">
            <VectorGraphic closed="false">
                <Point x="7" y="8" />
                <Point x="9" y="10" />
                <Point x="11" y="12" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
    <Layer alias="mountains">
        <PlacedGraphic x="250" y="250">
            <VectorGraphic closed="false">
                <Point x="13" y="14" />
                <Point x="15" y="19" />
                <Point x="17" y="18" />
                <!-- etc... -->
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
</Scene>)";

const std::string SceneXml = R"(
<Scene width="800" height="800">
    <Layer alias="bottom">
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="true">
                <Stroke tip="slash" size="7" color="FF0000" />
                <Point x="100" y="500" />
                <Point x="100" y="100" />
                <Point x="500" y="600" />
            </VectorGraphic>
        </PlacedGraphic>
        <PlacedGraphic x="400" y="300">
            <VectorGraphic closed="true">
                <Stroke tip="square" size="5" color="00FF00" />
                <Point x="0" y="0" />
                <Point x="0" y="100" />
                <Point x="100" y="100" />
                <Point x="100" y="0" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
    <Layer alias="top">
        <PlacedGraphic x="250" y="250">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="3" color="0000FF" />
                <Point x="0" y="0" />
                <Point x="0" y="100" />
                <Point x="100" y="100" />
                <Point x="100" y="0" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
</Scene>)";

const std::string houseSceneXml = R"(
<Scene width="1000" height="1000">
    <Layer alias="scenery">
        <!-- Sun -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="10" color="FF9224" />
                <Point x="900" y="1000" />
                <Point x="900" y="975"  />
                <Point x="915" y="935"  />
                <Point x="935" y="915"  />
                <Point x="975" y="900"  />
                <Point x="1000" y="900" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Ray1 -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="FFFF00" />
                <Point x="900" y="975"  />
                <Point x="850" y="975"  />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Ray2 -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="FFFF00" />
                <Point x="915" y="935"  />
                <Point x="860" y="915"  />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Ray3 -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="FFFF00" />
                <Point x="935" y="915"  />
                <Point x="910" y="865"  />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Ray4 -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="FFFF00" />
                <Point x="975" y="900"  />
                <Point x="975" y="850"  />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
    <Layer alias="house">
        <!-- Building -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
            <Stroke tip="square" size="2" color="0000FF" />
            <Point x="300" y="0" />
            <Point x="300" y="400" />
            <Point x="700" y="400" />
            <Point x="700" y="0" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Roof -->
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="0000FF" />
                <Point x="300" y="400" />
                <Point x="500" y="550" />
                <Point x="700" y="400" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Door -->
        <PlacedGraphic x="400" y="0">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="000000" />
                <Point x="0"   y="0" />
                <Point x="0"   y="150" />
                <Point x="100" y="150" />
                <Point x="100" y="0" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- Window -->
        <PlacedGraphic x="600" y="300">
            <VectorGraphic closed="true">
                <Stroke tip="square" size="5" color="FF0000" />
                <Point x="0"  y="0" />
                <Point x="0"  y="80" />
                <Point x="80" y="80" />
                <Point x="80" y="0" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- WindowBar1 -->
        <PlacedGraphic x="600" y="300">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="000000" />
                <Point x="40"  y="0" />
                <Point x="40"  y="80" />
            </VectorGraphic>
        </PlacedGraphic>
        <!-- WindowBar2 -->
        <PlacedGraphic x="600" y="300">
            <VectorGraphic closed="false">
                <Stroke tip="square" size="2" color="000000" />
                <Point x="0"  y="40" />
                <Point x="80"  y="40" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
</Scene>)";

using namespace BitmapGraphics;

TEST(ReadScene, SceneReader)
{
    std::stringstream xmlStream(TestXml);
    Xml::Reader reader;
    auto root = reader.loadXml(xmlStream);

    auto s = Framework::SceneReader::readScene(*root);
    
    CHECK_EQUAL(800, s.getWidth());
    CHECK_EQUAL(600, s.getHeight());
    
    int numberOfLayers = 0;
    for (auto pos = s.begin(); pos != s.end(); ++numberOfLayers, ++pos)
    {
        auto layer = (*pos);
        if (numberOfLayers == 0)
        {
            // verify sky layer
            CHECK_EQUAL("sky", layer.getAlias());
            Framework::Layer::PlacedGraphicIterator graphic;
            int iGraphic;
            for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
            {
                if (iGraphic == 0)
                {
                    CHECK_EQUAL(VG::Point(0, 0), (*graphic).getPlacementPoint());
                    auto vg = (*graphic).getGraphic();
                    CHECK_EQUAL(true, vg->isClosed());
                    CHECK_EQUAL(3, vg->getPointCount());
                    CHECK_EQUAL(VG::Point(1, 2), vg->getPoint(0));
                    CHECK_EQUAL(VG::Point(3, 4), vg->getPoint(1));
                    CHECK_EQUAL(VG::Point(5, 6), vg->getPoint(2));
                }
                else if (iGraphic == 1)
                {
                    CHECK_EQUAL(VG::Point(700, 0), (*graphic).getPlacementPoint());
                    auto vg = (*graphic).getGraphic();
                    CHECK_EQUAL(false, vg->isClosed());
                }
            }
            
            CHECK_EQUAL(2, iGraphic);
        }
        else if (numberOfLayers == 1)
        {
            // verify mountains layer
            CHECK_EQUAL("mountains", layer.getAlias());
            
            int numberOfGraphics = 0;
            for (auto graphic = layer.begin(); graphic != layer.end(); ++graphic)
            {
                ++numberOfGraphics;
            }
            
            CHECK_EQUAL(1, numberOfGraphics);
        }
    }
    
    // Expect 2 layers
    CHECK_EQUAL(2, numberOfLayers);
}

namespace
{
    class CodecLibrarySetup
    {
    public:
        CodecLibrarySetup()
        {
            myCodecLibrary.registerEncoder(std::make_shared<WindowsBitmapEncoder>());
            myCodecLibrary.registerDecoder(std::make_shared<WindowsBitmapDecoder>());
        }
        
        operator CodecLibrary&()
        {
            return myCodecLibrary;
        }
        
    private:
        CodecLibrary myCodecLibrary;
        
    };
}

TEST(toCanvas, SceneReader)
{
    std::stringstream xmlStream(SceneXml);
    Xml::Reader reader;
    
    // Parse the XML into a DOM
    auto root = reader.loadXml(xmlStream);
    
    // Construct a vector graphic Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*root);
    
    // Create an empty Canvas
    Color backgroundColor{100, 100, 100};
    HCanvas canvas = std::make_shared<BasicCanvas>(scene.getWidth(), scene.getHeight(), backgroundColor);
    
    // Draw the Scene onto the Canvas
    scene.draw(canvas);
    
    HBitmapIterator canvasIterator = canvas->createBitmapIterator();
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder {encoderPrototype.clone(canvasIterator)};
    
    /* Write out the canvas to a different file with its write() method
       Image will be flipped since Windows Bitmap file format draws
       from the last scanLine to the first scanLine */
    std::ofstream outputStream{"SceneXmlToCanvas.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
}

TEST(toBitmap, SceneReader)
{
    std::stringstream xmlStream(SceneXml);
    Xml::Reader reader;
    
    // Parse the XML into a DOM
    auto root = reader.loadXml(xmlStream);
    
    // Construct a vector graphic Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*root);
    
    // Create an empty Canvas
    Color backgroundColor{100, 100, 100};
    HCanvas canvas = std::make_shared<BasicCanvas>(scene.getWidth(), scene.getHeight(), backgroundColor);
    
    // Draw the Scene onto the Canvas
    scene.draw(canvas);
    
    /* Create a WindowsBitmapFileProjector and give it an output file name to create
       Also give it the CodecLibrary ("dependency injection"). */
    CodecLibrarySetup codecLibrary;
    HProjector projector = std::make_shared<WindowsBitmapFileProjector>("output_scene.bmp", codecLibrary);
    
    // Project the Canvas into the bitmap file
    projector->projectCanvas(canvas);
}

TEST(houseScene, SceneReader)
{
    std::stringstream xmlStream(houseSceneXml);
    Xml::Reader reader;
    
    // Parse the XML into a DOM
    auto root = reader.loadXml(xmlStream);
    
    // Construct a vector graphic Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*root);
    
    // Create an empty Canvas
    Color backgroundColor{192, 192, 192};
    HCanvas canvas = std::make_shared<BasicCanvas>(scene.getWidth(), scene.getHeight(), backgroundColor);
    
    // Draw the Scene onto the Canvas
    scene.draw(canvas);
    
    HBitmapIterator canvasIterator = canvas->createBitmapIterator();
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder {encoderPrototype.clone(canvasIterator)};
    
    /* Write out the canvas to a different file with its write() method
     Image will be flipped since Windows Bitmap file format draws
     from the last scanLine to the first scanLine */
    std::ofstream outputStream{"houseScene.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
}
