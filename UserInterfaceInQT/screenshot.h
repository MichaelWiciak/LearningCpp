#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>
#include "responsive_layout.h"
#include "responsive_label.h"
#include "responsive_window.h"

class Screenshot : public ResponsiveWindow {
    Q_OBJECT

public:
    Screenshot(std::string srcLocation) : srcLocation(srcLocation) {};

public slots:
    void doScreenshot();
s
private:
    void showEvent(QShowEvent *);
    void schedule();
    std::vector<QSize> remaining;
    QTimer* mTimer;
    const std::string srcLocation;
};


#endif //SCREENSHOT_H
