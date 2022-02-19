#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// matrix[a][matrix[b][c]] != matrix[matrix[a][b]][c]

int main()
{
    std::ifstream in("matrix.txt");
    std::vector<std::vector<int>> matrix;

    int row = 0;
    int matrixNumber = 1;
    std::string line;
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            if (line == "-")
            {
                int count = 0;

                for (int a = 0; a < matrix.size(); a++)
                    for (int b = 0; b < matrix.size(); b++)
                        for (int c = 0; c < matrix.size(); c++)
                            if (matrix[a][matrix[b][c]] != matrix[matrix[a][b]][c])
                                count++;

                if (count == 0)
                    std::cout << "Matricea #" << matrixNumber << " are aceste proprietati\n";
                else
                    std::cout << "Matricea #" << matrixNumber << " nu are aceste proprietati\n";

                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i].clear();
                }
                matrix.clear();
                matrixNumber++;
                count = 0;
                continue;
            }

            line += " ";
            size_t pos = 0;
            std::string token;
            std::string delimiter = " ";
            std::vector<int> matrixLine;

            while ((pos = line.find(delimiter)) != std::string::npos)
            {
                token = line.substr(0, pos);
                matrixLine.push_back(std::stoi(token) - 1);
                line.erase(0, pos + delimiter.length());
            }
            matrix.push_back(matrixLine);
        }
        in.close();
    }
    else
    {
        std::cout << "file is closed\n";
        return 0;
    }

    for (std::vector<int> v : matrix)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}