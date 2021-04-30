#include <iostream>
#include "DemLoader.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "no hgt file given as first argument\n";
        return -1;
    }

    DemLoader loader;
    auto heights = loader.Load(argv[1]);
    std::cout << "num samples : " << heights.size() << "\n";
    std::cout << "DEM Converter v0.0.1 alpha" << std::endl;
    return 0;
}