/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *imgLab;
    QPushButton *imgbutn;
    QPushButton *setimg;
    QLineEdit *imgpath;
    QPushButton *openfile;
    QLineEdit *lineset;
    QLabel *m_dis;
    QLabel *disoutput;
    QLabel *m_line;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 720);
        MainWindow->setMinimumSize(QSize(960, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        imgLab = new QLabel(centralwidget);
        imgLab->setObjectName("imgLab");
        imgLab->setGeometry(QRect(420, 40, 441, 631));
        imgLab->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        imgbutn = new QPushButton(centralwidget);
        imgbutn->setObjectName("imgbutn");
        imgbutn->setGeometry(QRect(50, 330, 141, 51));
        setimg = new QPushButton(centralwidget);
        setimg->setObjectName("setimg");
        setimg->setGeometry(QRect(40, 160, 151, 51));
        imgpath = new QLineEdit(centralwidget);
        imgpath->setObjectName("imgpath");
        imgpath->setGeometry(QRect(40, 90, 221, 51));
        openfile = new QPushButton(centralwidget);
        openfile->setObjectName("openfile");
        openfile->setGeometry(QRect(260, 90, 61, 51));
        lineset = new QLineEdit(centralwidget);
        lineset->setObjectName("lineset");
        lineset->setGeometry(QRect(150, 270, 113, 25));
        m_dis = new QLabel(centralwidget);
        m_dis->setObjectName("m_dis");
        m_dis->setGeometry(QRect(50, 460, 61, 31));
        m_dis->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        disoutput = new QLabel(centralwidget);
        disoutput->setObjectName("disoutput");
        disoutput->setGeometry(QRect(120, 460, 181, 41));
        disoutput->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        disoutput->setAlignment(Qt::AlignCenter);
        m_line = new QLabel(centralwidget);
        m_line->setObjectName("m_line");
        m_line->setGeometry(QRect(20, 270, 121, 31));
        m_line->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(260, 270, 41, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imgLab->setText(QString());
        imgbutn->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\345\233\276\347\211\207", nullptr));
        setimg->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\233\276\347\211\207", nullptr));
        imgpath->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        openfile->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
        m_dis->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\357\274\232", nullptr));
        disoutput->setText(QString());
        m_line->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\255\243\346\226\271\345\275\242\350\276\271\351\225\277", nullptr));
        comboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
