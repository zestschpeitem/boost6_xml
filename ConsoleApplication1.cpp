#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp>

using namespace std;

namespace pt = boost::property_tree;

class XML_struct {
    pt::ptree tree;

    public:
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


    int create_xml(const string& name_file) {
        string our_line;
        ifstream in(name_file); // окрываем файл для чтения
        vector<string> substrings;
        pt::ptree AST;
        if (in.is_open())
        {
            while (getline(in, our_line))
            {
                boost::split(substrings, our_line, boost::is_any_of("., ="), boost::token_compress_on);
                for (auto& our_line : substrings) {
                    if (our_line != "root" && our_line !="AST") {
                        pt::ptree line;
                        line.add("<xmlattr>.type", our_line);
                        line.add("<xmlattr>.value", our_line);
                        AST.add_child("AST", line);
                    }
                }
            }

        }
        tree.add_child("root", AST);
            in.close();
            return 0;
        }




    void WriteXML(const string& filename) {
        write_xml(filename, tree);
    }

}; 



    int main(int argc, char* argv[])
    {
        XML_struct element;
        if (argc < 1 || argc > 2) {
            cout << "Error!";
            return -1;
        }
        else {
            const string name_file(argv[1]);
            if (element.check(name_file) == -1) {
                return -1;
            }
            else {
                element.create_xml(name_file);
                element.WriteXML("result.xml");
            }
        }
    }