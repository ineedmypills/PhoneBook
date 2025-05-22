#include "TXTToJSON.hpp"
#include "userInterface.hpp"
#include <windows.h>




int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    txtToJson("input.txt", "output.json");
    userInterface();

    return 0;
}
