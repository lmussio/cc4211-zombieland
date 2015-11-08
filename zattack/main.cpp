#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
    int max = atoi(argv[1]);
    int j=0;
    for(int i = 0; i < max ; i++) {
        system("./zombie/zombie &");
//        if((j/2)==0) system("./zombie/zombie &");
    }

    FILE *in;
    char buff[512];
    std::list<std::string> zombies;

    if(!(in = popen("ps -ef | grep ./zombie | head -n -1 | awk '{ printf $2\"\\n\" }'", "r"))){
        return 1;
    }

    while(fgets(buff, sizeof(buff), in)!=NULL){
        zombies.push_back(buff);
    }
    for (std::list<std::string>::iterator it = zombies.begin(); it != zombies.end(); it++){
        sleep(10);
        system(("kill " + *it).c_str());
    }


    pclose(in);

    pause();

    return 0;
}