#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "no input file" << std::endl;
        exit(1);
    }
    if (argc < 3) {
        std::cout << "no output file" << std::endl;
        exit(1);
    }

    string inputFile{argv[1]};
    string outputFile{argv[2]};

    ifstream ifs{inputFile};
    ofstream ofs{outputFile};

    std::cout << "Generating data" << std::endl;
    string line;
    while (std::getline(ifs, line) && line.size() > 0) {
        // std::cout << line << std::endl;
        if (line[0] != 'a') {
            continue;
        }
        istringstream iss{line};
        char a;
        int u, v, w;
        iss >> a >> u >> v >> w;
        // ofs << u << "," << v << "," << w << std::endl;
        ofs << u << "," << v << std::endl;
    }
    ifs.close();
    ofs.close();

    std::cout << "Data generation done!" << std::endl;
}