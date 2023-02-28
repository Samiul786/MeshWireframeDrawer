#include <vector>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor magenta = TGAColor(255, 0, 255, 255);
const TGAColor rose = TGAColor(255, 0, 127, 255);
Model *model = NULL;
const int width  = 800;
const int height = 800;

// Write the line method here
// line (x0, y0, x1, y1, image, colour)

void line(int x0, int y0, int x1, int y1, TGAImage& image)
{
    /*for (float t = 0; t <= 1; t += 0.001) {
        float x = x0 + (x1 + x0) * t;
        float y = y0 + (y1 + y0) * t;
        image.set(x, y, rose);
    }*/

    for (float x = x0; x <= x1; x++)
    {
        float t = (x - x0)/(x1 - x0);
        float y = y0 * (1 - t) + (y1 * t);
        image.set(x, y, magenta);
    }
    
}

int main(int argc, char** argv) {
    
    TGAImage image(width, height, TGAImage::RGB);

    line(13, 20, 80, 40, image);
    line(20, 13, 40, 80, image);
    image.flip_vertically(); // we want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    delete model;
    return 0;
}

