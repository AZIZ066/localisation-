/********************************************************************************
** Form generated from reading UI file 'gmeteora.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GMETEORA_H
#define UI_GMETEORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GMeteORA
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GMeteORA)
    {
        if (GMeteORA->objectName().isEmpty())
            GMeteORA->setObjectName("GMeteORA");
        GMeteORA->resize(800, 600);
        centralwidget = new QWidget(GMeteORA);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(190, 130, 120, 80));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        GMeteORA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GMeteORA);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        GMeteORA->setMenuBar(menubar);
        statusbar = new QStatusBar(GMeteORA);
        statusbar->setObjectName("statusbar");
        GMeteORA->setStatusBar(statusbar);

        retranslateUi(GMeteORA);

        QMetaObject::connectSlotsByName(GMeteORA);
    } // setupUi

    void retranslateUi(QMainWindow *GMeteORA)
    {
        GMeteORA->setWindowTitle(QCoreApplication::translate("GMeteORA", "GMeteORA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GMeteORA: public Ui_GMeteORA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GMETEORA_H
