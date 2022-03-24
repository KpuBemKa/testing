#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void showVector(std::vector<std::vector<int>> vector)
{
    for (std::vector<int> v : vector)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int convert(std::string num)
{
    int len = num.size();
    int base = 1;
    int temp = 0;
    
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            temp += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            temp += (num[i] - 55) * base;
            base = base * 16;
        }
    }

    return temp;
}

void formula1(std::vector<std::vector<int>> matrix)
{
    int count = 0;

    for (int a = 1; a < matrix.size() - 1; a++)
        for (int b = 1; b < matrix.size() - 1; b++)
            for (int c = 1; c < matrix.size() - 1; c++)
                    if (matrix[a][b] != matrix[matrix[c][a]][matrix[c][b]])
                        count++;

    if (count == 0)
        std::cout << "\033[1;32m[ OK ] Matricea are proprietatile formulei #1 (+)\n";
    else
        std::cout << "\033[1;32m[\033[1;31mFAILED\033[1;32m] Matricea nu are proprietatile formulei #1 (+)\n";
}

int main()
{
    std::ifstream in("E:\\dev\\projects\\testing\\Lab10\\build\\matrix.txt");
    std::vector<std::vector<int>> matrix;
    std::vector<int> matrixEmptyLine;
    matrixEmptyLine.push_back(0);
    matrix.push_back(matrixEmptyLine);

    int row = 0;
    int matrixNumber = 1;
    std::string line;
    if (in.is_open())
    {
        while (std::getline(in, line))
        {

            matrix.push_back(matrixEmptyLine);

            size_t pos = 0;
            std::string token;
            line += " ";
            std::string delimiter = " ";
            std::vector<int> matrixLine;
            matrixLine.push_back(0);

            while ((pos = line.find(delimiter)) != std::string::npos)
            {
                token = line.substr(0, pos);
                matrixLine.push_back(convert(token));
                line.erase(0, pos + delimiter.length());
            }
            matrixLine.push_back(0);
            matrix.push_back(matrixLine);
        }
        in.close();
    }
    else
    {
        std::cout << "file is closed\n";
        return 0;
    }

    formula1(matrix);

    // readFiles();
}