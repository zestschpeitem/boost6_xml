#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>

using namespace std;

namespace pt = boost::property_tree;

pt::ptree tree;

int check(const string& name_file) { //функция проверяет на наличие нужного файла проверка на путь. Функция которая будет проверять путь.
    try {
        if (std::ifstream(name_file)) {
            return 0;
        }
        else {
            cout << "File not find!!!";
            return -1;
        }
    }
    catch (...) {
        std::cout << "Failed !!!";
        return -1;
    }
}

int create_xml (const string& name_file) {

    string line;

    ifstream in(name_file); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
    return 0;
    }


    int main(int argc, char* argv[])
    {
        if (argc < 1 || argc > 2) {
            cout << "Error!";
            return -1;
        }

        else {
            const string name_file(argv[1]);
            if (check(name_file) == -1) {
                return -1;
            }
            else {
                return create_xml(name_file);
            }
        }
    }
