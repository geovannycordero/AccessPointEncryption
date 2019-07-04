#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "Socket.h"
#include "chrono"
#include "iostream"
#include <string>
#include <iostream>
#include <fstream>

#define SIZE 512

int main() {

    std::ofstream myfile;


    myfile.open("results.cvs");

    char* archivos[]={(char*)"1k.txt",
        (char*)"10k.txt",
        (char*)"100k.txt",
        (char*)"128k.txt",
        (char*)"256k.txt",
        (char*)"512k.txt",
        (char*)"1m.txt",
        (char*)"10m.txt"};

    for(int arc = 0; arc < 8; arc++){
        printf("\n\n%s\n",archivos[arc]);
        myfile << "\n\n";
        myfile << archivos[arc];
        myfile << "\n";

        for(int rep=0;rep<10;rep++){
            Socket s('s',false);
            char buffer[ SIZE ];
            int id, st;
            long sent, psize;
            double rate;
            psize = 128 * 1024 * 1024;
            id = open(archivos[arc],O_RDONLY);

            if (-1==id){
                printf("ERROR\n");
                return 1;
            }
            s.Connect((char*)"localhost",(char*)"5000");
            s.Write(archivos[arc],128);
            s.Read((char*)buffer,2);

            auto ci = std::chrono::system_clock::now();

            sent = 0;
            while (st=read(id,buffer,SIZE)){
                st = s.Write(buffer,SIZE);
                sent += st;
            }
            s.Shutdown(SHUT_WR) ;
            s.Read((char*)buffer,SIZE);
            std::chrono::duration<double> cf = std::chrono::system_clock::now()-ci;

            std::cout << cf.count() << std::endl;
            myfile << cf.count();
            myfile << "\n";

            rate=cf.count()+(cf.count()/1000000000);
            rate=(double)(sent/1024/1024)/rate;
            close(id);
        }
    }

    myfile.close();
}
