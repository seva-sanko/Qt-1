#include "WidgetCollection.h"
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QMetaMethod>

WidgetCollection::WidgetCollection(QWidget *parent)
    : QWidget(parent), mainLayout(new QVBoxLayout(this)) {
    addButton = new QPushButton("Добавить виджет", this);
    connectButton = new QPushButton("Соединить виджеты", this);

    connect(addButton, &QPushButton::clicked, this, &WidgetCollection::onAddButtonClicked);
    connect(connectButton, &QPushButton::clicked, this, &WidgetCollection::onConnectButtonClicked);

    mainLayout->addWidget(addButton);
    mainLayout->addWidget(connectButton);
    setLayout(mainLayout);
}

void WidgetCollection::addWidget(QWidget *widget) {
    widgetList.append(widget);
    mainLayout->addWidget(widget);
    qDebug() << "Добавлен виджет:" << widget->metaObject()->className();
}

void WidgetCollection::onAddButtonClicked() {
    int type = widgetList.size() % 4;
    QWidget *newWidget = nullptr;

    if (type == 0) newWidget = new QLabel("this is QLabel", this);
    else if (type == 1) newWidget = new QSlider(Qt::Horizontal, this);
    else if (type == 2) newWidget = new QScrollBar(Qt::Horizontal, this);
    else if (type == 3) newWidget = new QSpinBox(this);

    if (newWidget) addWidget(newWidget);
}

void WidgetCollection::connectWidgets() {
    for (int i = 0; i < widgetList.size(); ++i) {
        for (int j = i + 1; j < widgetList.size(); ++j) {
            QObject *widget1 = widgetList[i];
            QObject *widget2 = widgetList[j];

            const QMetaObject *metaObj1 = widget1->metaObject();
            const QMetaObject *metaObj2 = widget2->metaObject();

            int signalIndex1 = metaObj1->indexOfSignal("valueChanged(int)");
            int slotIndex2 = metaObj2->indexOfSlot("setValue(int)");

            if (signalIndex1 >= 0 && slotIndex2 >= 0) {
                QMetaMethod signal = metaObj1->method(signalIndex1);
                QMetaMethod slot = metaObj2->method(slotIndex2);

                bool connected1 = connect(widget1, signal, widget2, slot, Qt::UniqueConnection);
                bool connected2 = connect(widget2, signal, widget1, slot, Qt::UniqueConnection);

                qDebug() << "Соединение" << widget1->metaObject()->className()
                         << "->" << widget2->metaObject()->className()
                         << ":" << (connected1 && connected2 ? "Успешно" : "Ошибка");
            }
        }
    }
    qDebug() << "Все виджеты в коллекции соединены.";
}

void WidgetCollection::onConnectButtonClicked() {
    connectWidgets();
}
