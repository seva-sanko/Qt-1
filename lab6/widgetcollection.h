#ifndef WIDGETCOLLECTION_H
#define WIDGETCOLLECTION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMetaObject>
#include <QDebug>

class WidgetCollection : public QWidget {
    Q_OBJECT

public:
    explicit WidgetCollection(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;          // Основной макет
    QList<QWidget *> widgetList;      // Коллекция виджетов
    QPushButton *addButton;           // Кнопка добавления виджетов
    QPushButton *connectButton;       // Кнопка соединения виджетов

    void addWidget(QWidget *widget);  // Метод для добавления виджета
    void connectWidgets();            // Метод для соединения виджетов

private slots:
    void onAddButtonClicked();        // Обработчик добавления виджета
    void onConnectButtonClicked();    // Обработчик соединения виджетов
};

#endif // WIDGETCOLLECTION_H
