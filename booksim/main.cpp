#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{    
    if (system(NULL))
    {
        string command = "./booksim examples/anynet_config ";
        string str1 = "examples/anynet_config";

        ifstream file_config, file_map;
        string line;
        std::size_t pos1, pos2;
        string mapping_file = "";
        int line_count = 0;

        file_config.open(str1);
        while(1)
        {
            getline(file_config,line);
            pos1 = line.find("mapping_file");

            if (pos1 != std::string::npos)
            {
                pos1 = line.find("=");
                pos2 = line.find(";");
                mapping_file = line.substr(pos1+2,pos2-pos1-2);

                break;
            }
        }
        file_config.close();

        file_map.open(mapping_file);

        while(getline(file_map,line))
        {
            line_count++;
        }
        file_map.close();



        for (int iter = 1; iter <=line_count;iter++)
        {
            string num = std::to_string(iter);
            string cmd_temp = command+num;

            char * cmd = const_cast<char *>(cmd_temp.c_str());//strcat(cmd_temp,num);

            system(cmd);
            // cout << cmd;
        }
    }
    else
    {
           cout << "Command processor doesn't exists" << endl;
    }


    cout << "Execution Complete" << endl;
    return 0;
}
