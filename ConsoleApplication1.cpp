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
    pt::ptree root;

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
        string after_equally;
        string type;
        pt::ptree AST;
        if (in.is_open())
        {
            while (getline(in, our_line))
            {
                boost::split(substrings, our_line, boost::is_any_of("."), boost::token_compress_on);
                size_t pos = our_line.find("=");
                if (pos++ != our_line.npos) {
                    after_equally = our_line.substr(pos);
                }
                if (after_equally == "true" || after_equally == "false") {
                    type = "bool";
                }
                else if(after_equally.find_first_not_of("0123456789") == string::npos){
                    type = "int";
                }
                else {
                    type = "string";
                }

                pt::ptree property;
                for (auto& our_line : substrings) {
                    string my_line = our_line.substr(0, our_line.find("=", 0));
                    if (our_line!="root" && our_line!="AST") {
                    property.add("<xmlattr>.id", my_line);
                    property.add("<xmlattr>.type", type);
                    property.add("<xmlattr>.value", after_equally);
                    }
                }
                AST.add_child("property", property);
                //каккую группу я сейчас заполняю узнать, если группа поменялась то аст записать в рут и создать новое поддерево аудио которое мы потом запишем в рут.
            }
            root.add_child("root.AST", AST);

        }

            in.close();
            return 0;
        }




    void WriteXML(const string& filename) {
        write_xml(filename, root);
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