//
// Created by lmussio on 08/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    FILE *in;
    char buff[512];
    std::string zombie;
    int flag = 0;
    while(true) {
        if(flag == 0) sleep(atoi(argv[1]));
        flag++;
        if (!(in = popen("ps -ef | grep [d]efunct | head -1 | awk '{ printf $3\"\\n\" }'", "r"))) return 1;
        while (fgets(buff, sizeof(buff), in) != NULL) {
            flag = 0;
            zombie = buff;
            system(("kill " + zombie).c_str());
            std::cout << "Zombie " + zombie + " exterminado! " << std::endl;
        }
        pclose(in);
        if(flag>=2) exit(0);
    }
}