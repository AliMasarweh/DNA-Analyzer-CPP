#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
    if(strcmp(argv[0],"<<<"))
    {
        std::cout << "Wrong format!" << std::endl;
        return 1;
    }
    switch (argc){
        case 2:
            /*handleRequest(argv[1]);*/
            break;
        case 3:
            /*handleRequest(argv[1], argv[2]);*/
            break;
        case 4:
            /*handleRequest(argv[1], argv[2], argv[3]);*/
            break;
    }

    //handleRequest(argv[1]);
    return 0;
}
