#include "screenshot.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <QString>
#include<ctime>
#include <regex>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#if defined(_WIN32)
#include <direct.h>
#endif
#if defined(__unix)
#include <sys/stat.h>
#endif
using namespace std;



void mkdir_ ( std::string sPath) {  // https://stackoverflow.com/a/35109823/708802
    int nError = 0;
    #if defined(_WIN32)
      nError = _mkdir(sPath.c_str()); // can be used on Windows
    #else
      nError = mkdir(sPath.c_str(), S_IRWXU); // can be used on non-Windows
    #endif
    if (nError != 0) {
      std::cout << "error creating directory "<< sPath <<". quitting.";
      exit (-2);
    }
}



int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
       cout << "Qt version: " << QT_VERSION_STR << endl;


       if (argc == 3)  {
           if (string(argv[1]) =="test") {
               // create the Qt Application
               QApplication app(argc, argv);

               // have you given a valid source folder (cw1 culprits: you know who you are...)
               string srcLocation(argv[2]);

               // grading-mode - run the screenshot subclass
               Screenshot screenshot (srcLocation);
               screenshot.show();

               return app.exec();
           }
           else
               cout <<  "unknown command line argument: "<<  string(argv[2]) <<endl;
       } else { // run interactively
           // create the Qt Application
           QApplication app(argc, argv);
           // interactive mode - run the regular superclass
           ResponsiveWindow window;
           window.show();
           // wait for the app to terminate
           return app.exec();
       }
}
