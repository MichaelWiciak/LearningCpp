#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QLabel>
#include <QString>
#include <map>

const QString
        kHomeLink       = "home",
        kShoppingBasket = "basket",
        kSignIn         = "sign-in",
        kMenu           = "menu-button",
        kNavTabs        = "navigation tabs",
        kAdvert         = "advert",
        kSearchButton   = "search",
        kSearchResult   = "result",
        kSearchText     = "search query",
        kSearchForward  = ">",
        kSearchBackward = "<",
        kSearchOptions  = "search options",
        kRefresh        = "Refresh",
        kLanguage       = "Language",
        kSearchBox      = "";

// every label name has a colour
const std::map<QString, QString> kColours = {
        std::make_pair(kHomeLink,       "#ffaaff"),
        std::make_pair(kShoppingBasket, "#ffaaaa"),
        std::make_pair(kSignIn,         "#aaffaa"),
        std::make_pair(kNavTabs,        "#ffa9d3"),
        std::make_pair(kAdvert,         "#ffaa66"),
        std::make_pair(kSearchButton,   "#aaffff"),
        std::make_pair(kSearchResult,   "#99ddff"),
        std::make_pair(kSearchText,     "#aaaaff"),
        std::make_pair(kSearchForward,  "#5caeff"),
        std::make_pair(kSearchBackward, "#5caeff"),
        std::make_pair(kMenu,           "#E3CEF6"),
        std::make_pair(kSearchBox,      "#ffffff"),
        std::make_pair(kRefresh,        "#F2F5A9"),
        std::make_pair(kLanguage,       "#D8D8D8"),
        std::make_pair(kSearchOptions,  "#9dceff")
    };

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;
    ResponsiveLabel(QString name, QString colour) ;
};


#endif // RESPONSIVELABEL_H
