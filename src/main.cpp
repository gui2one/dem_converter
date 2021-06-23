
#include <vector>
#include "DemLoader.h"
#include "stb_image_write.h"
int main(int argc, char *argv[])
{
    std::string file_path;
    if (argc < 2)
    {
        std::cout << "no hgt file given as first argument\n";
        file_path = "C:/gui2one/CODE/DEM_files/K11/N42W118.hgt";
        // return -1;
    }
    else
    {
        file_path = std::string(argv[1]);
    }

    DemLoader loader;
    auto heights = loader.Load(file_path);
    std::vector<unsigned char> pixels;
    pixels.reserve(1201 * 1201);
    for (size_t i = 0; i < 1201 * 1201; i++)
    {
        unsigned char value = (unsigned char)(((float)heights[i] / SHRT_MAX) * 255);
        pixels.emplace_back(value);
    }
    stbi_write_png("aaa.png", 1201, 1201, 1, pixels.data(), 0);

    std::cout << "num samples : " << heights.size() << "\n";
    std::cout << "DEM Converter v0.0.1 alpha" << std::endl;
    return 0;
}