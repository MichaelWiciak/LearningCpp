#include "screenshot.h"
#include <sys/stat.h>
#include <fstream>
#include <QApplication>
#include <string>
#include <sys/types.h>
#include <iostream>

#if defined(_WIN32)
#include <direct.h>
#endif

//using namespace std;

void Screenshot::doScreenshot() {

    auto active_window = QApplication::activeWindow();

    // screen shot currently sized window
    if (active_window) {
        QPixmap pixmap(active_window->size());
        active_window->render(&pixmap);

        QSize &size = remaining.back();

        std::string s = srcLocation + "/report/images/rendered" +  std::to_string ( size.width() ) +
                "x" + std::to_string ( size.height() ) +".png";

        QFile file( QString::fromStdString(s));

        file.open(QIODevice::WriteOnly);
        pixmap.save(&file, "PNG");
    }
    remaining.pop_back();
    schedule();
}

void mkdir2 (std::string sPath) {  // https://stackoverflow.com/a/35109823/708802
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

void Screenshot::showEvent(QShowEvent *) {

    mkdir2( srcLocation + "/report");
    mkdir2( srcLocation + "/report/images");

    remaining.push_back(QSize(320,320));

    remaining.push_back(QSize(568,320));
    remaining.push_back(QSize(320,568));

    remaining.push_back(QSize(812,375));
    remaining.push_back(QSize(375,720));

    remaining.push_back(QSize(1024,600));

    remaining.push_back(QSize(720 ,720));
    remaining.push_back(QSize(500 ,720));

    remaining.push_back(QSize(1280,320));
    remaining.push_back(QSize(1280,720));



    std::ofstream html;
    html.open( srcLocation + "/report/index.html", std::fstream::in | std::fstream::out | std::fstream::app);

    html << "</pre><h4>responsive layouts:</h4>" << std::endl;

    for (QSize size : remaining)
        html << "<p><img width = \"320px\" src=\"" << "images/rendered" +
                std::to_string ( size.width() ) + "x" + std::to_string ( size.height() ) +
                ".png\"/><br/>" << size.width() << "x" << size.height() << "</p>" << std::endl ;

    html << "</body></html>" << std::endl;

    html.close();

    schedule();
}

// schedule the next sized screenshot from the remaining list.
void Screenshot::schedule() {
    if (remaining.size() == 0) {
        QApplication::quit();
        return;
    }

    QSize &size = remaining.back();
    resize(size);

    mTimer = new QTimer(NULL);
    mTimer->setSingleShot(true);
    mTimer->setInterval(200);
    mTimer->start();

    connect( mTimer, SIGNAL (timeout()), SLOT ( doScreenshot() ) );
}

