#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>
#include <QScrollArea>
#include "responsiveQScrollArea.h"

ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();

}

void ResponsiveWindow::createWidgets() {

    // initialises our layers
    this->rl = new ResponsiveLayout();
    this->scrollArea = new responsiveQScrollArea(this);
    // sets up scroll area
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scrollArea->setWidgetResizable( true );
    this->widget = new QWidget();
    scrollArea->setWidget( this->widget );
    // add all the widgets we need to demonstrate all layouts
    for (int i=0; i<17; i++){
        rl->addWidget(new ResponsiveLabel(kSearchResult));
    }
    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    rl->addWidget(new ResponsiveLabel(kSearchText));
    rl->addWidget(new ResponsiveLabel(kSearchBackward));
    rl->addWidget(new ResponsiveLabel(kSearchForward));
    rl->addWidget(new ResponsiveLabel(kSearchOptions));
    rl->addWidget(new ResponsiveLabel(kRefresh));
    rl->addWidget(new ResponsiveLabel(kLanguage));
    // Set the layout and finish setting up the screen
    setLayout(rl);
    this->widget->setLayout( rl );
    this->scrollArea->setGeometry(0,0, 0, 0);


}

void ResponsiveWindow::resizeEvent(QResizeEvent *e)
{
    // This gets called everytime the window is resised
    // It gets used to adjust the widgets inside the scroll area
    this->rl->setGeometry(this->rect());
    this->widget->setFixedHeight(this->rl->getMaxWidth());
    this->scrollArea->setGeometry(this->rect());
    this->rl->setGeometry(this->rect());

}
