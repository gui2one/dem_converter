#include "DemLoader.h"

std::vector<short> DemLoader::Load(std::string file_path)
{
    std::vector<short> heights;
    const int SRTM_SIZE = 1201;
    heights.reserve(SRTM_SIZE * SRTM_SIZE);
    std::ifstream file(file_path, std::ios::beg | std::ios::binary);
    if (!file)
    {
        std::cout << "Error opening file!" << std::endl;
        return std::vector<short>();
    }

    unsigned char buffer[2];
    for (int i = 0; i < SRTM_SIZE * SRTM_SIZE; ++i)
    {

        if (!file.read(reinterpret_cast<char *>(buffer), sizeof(buffer)))
        {
            std::cout << "Error reading file!" << std::endl;
            return std::vector<short>();
        }

        short val = (buffer[0] << 8) | buffer[1];
        heights.emplace_back(val);
    }

    return heights;

    // //Read single value from file at row,col
    // const int row = 0;
    // const int col = 0;
    // size_t offset = sizeof(buffer) * ((row * SRTM_SIZE) + col);
    // file.seekg(offset, std::ios::beg);
    // file.read(reinterpret_cast<char *>(buffer), sizeof(buffer));
    // short single_value = (buffer[0] << 8) | buffer[1];
    // std::cout << "values at " << row << "," << col << ":" << std::endl;
    // std::cout << "  heights array: " << heights[row][col] << ", file: " << single_value << std::endl;
}
