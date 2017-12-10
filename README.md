# VectorGraphics
Framework for encoding/decoding VectorGraphics and image processing in Bitmaps

# Unit Testing
Performed using CppUnitLite framework. Unit tests have the suffix 'Test' in the filename.

# Environment
Xcode Version 8.3.3
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.7.0

# Example
Bitmaps can be created from an xml-like notation. 

```xml
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
</Scene>

...more
```

See: https://github.com/barfknechtj/VectorGraphics/tree/master/OutputPics/houseScene_small_size.png
