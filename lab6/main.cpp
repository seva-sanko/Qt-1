#include <QApplication>
#include "WidgetCollection.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WidgetCollection widgetCollection;
    widgetCollection.setWindowTitle("Динамическая коллекция виджетов");
    widgetCollection.resize(400, 300);
    widgetCollection.show();

    return app.exec();
}
