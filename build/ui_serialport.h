/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialPort
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialPort)
    {
        if (serialPort->objectName().isEmpty())
            serialPort->setObjectName(QStringLiteral("serialPort"));
        serialPort->resize(253, 334);
        centralWidget = new QWidget(serialPort);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        serialPort->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(serialPort);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 253, 21));
        serialPort->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serialPort);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serialPort->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serialPort);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serialPort->setStatusBar(statusBar);

        retranslateUi(serialPort);

        QMetaObject::connectSlotsByName(serialPort);
    } // setupUi

    void retranslateUi(QMainWindow *serialPort)
    {
        serialPort->setWindowTitle(QApplication::translate("serialPort", "serialPort", 0));
    } // retranslateUi

};

namespace Ui {
    class serialPort: public Ui_serialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
