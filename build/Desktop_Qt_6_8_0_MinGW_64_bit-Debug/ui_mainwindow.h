/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QPushButton *btnAddTask;
    QListWidget *listWidget;
    QPushButton *btnDelete;
    QPushButton *btnClearAll;
    QLineEdit *txtNewTask;
    QPushButton *btnStartTimer;
    QLabel *lblTimer;
    QListWidget *listWidget_2;
    QPushButton *btnDelete_2;
    QPushButton *btnClearAll_2;
    QPushButton *btnAddTask_2;
    QLineEdit *txtNewTask_2;
    QPushButton *btnStopTimer;
    QPushButton *btnResetTimer;
    QPushButton *taskButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(637, 493);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"background-image: url(:/istockphoto-108203887-612x612.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnAddTask = new QPushButton(centralwidget);
        btnAddTask->setObjectName("btnAddTask");
        btnAddTask->setGeometry(QRect(220, 210, 80, 24));
        btnAddTask->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 240, 291, 171));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDropMode::DragDrop);
        listWidget->setDefaultDropAction(Qt::DropAction::MoveAction);
        listWidget->setSortingEnabled(false);
        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(50, 420, 80, 24));
        btnDelete->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        btnClearAll = new QPushButton(centralwidget);
        btnClearAll->setObjectName("btnClearAll");
        btnClearAll->setGeometry(QRect(180, 420, 80, 24));
        btnClearAll->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        txtNewTask = new QLineEdit(centralwidget);
        txtNewTask->setObjectName("txtNewTask");
        txtNewTask->setGeometry(QRect(10, 210, 191, 24));
        txtNewTask->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        btnStartTimer = new QPushButton(centralwidget);
        btnStartTimer->setObjectName("btnStartTimer");
        btnStartTimer->setGeometry(QRect(510, 10, 91, 24));
        btnStartTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 255, 79);\n"
"color: rgb(0, 0, 0);"));
        lblTimer = new QLabel(centralwidget);
        lblTimer->setObjectName("lblTimer");
        lblTimer->setGeometry(QRect(100, 10, 391, 151));
        QFont font;
        font.setPointSize(60);
        lblTimer->setFont(font);
        lblTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 255);"));
        lblTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(330, 240, 291, 171));
        listWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        listWidget_2->setDragEnabled(true);
        listWidget_2->setDragDropMode(QAbstractItemView::DragDropMode::DragDrop);
        listWidget_2->setDefaultDropAction(Qt::DropAction::MoveAction);
        listWidget_2->setSortingEnabled(false);
        btnDelete_2 = new QPushButton(centralwidget);
        btnDelete_2->setObjectName("btnDelete_2");
        btnDelete_2->setGeometry(QRect(370, 420, 80, 24));
        btnDelete_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        btnClearAll_2 = new QPushButton(centralwidget);
        btnClearAll_2->setObjectName("btnClearAll_2");
        btnClearAll_2->setGeometry(QRect(520, 420, 80, 24));
        btnClearAll_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        btnAddTask_2 = new QPushButton(centralwidget);
        btnAddTask_2->setObjectName("btnAddTask_2");
        btnAddTask_2->setGeometry(QRect(540, 210, 80, 24));
        btnAddTask_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        txtNewTask_2 = new QLineEdit(centralwidget);
        txtNewTask_2->setObjectName("txtNewTask_2");
        txtNewTask_2->setGeometry(QRect(330, 210, 191, 24));
        txtNewTask_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        btnStopTimer = new QPushButton(centralwidget);
        btnStopTimer->setObjectName("btnStopTimer");
        btnStopTimer->setGeometry(QRect(510, 70, 91, 21));
        btnStopTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"color: rgb(0, 0, 0);"));
        btnResetTimer = new QPushButton(centralwidget);
        btnResetTimer->setObjectName("btnResetTimer");
        btnResetTimer->setGeometry(QRect(510, 130, 91, 24));
        btnResetTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        taskButton = new QPushButton(centralwidget);
        taskButton->setObjectName("taskButton");
        taskButton->setGeometry(QRect(260, 170, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 637, 21));
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
        btnAddTask->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btnClearAll->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        btnStartTimer->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        lblTimer->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        btnDelete_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btnClearAll_2->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        btnAddTask_2->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        btnStopTimer->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        btnResetTimer->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        taskButton->setText(QCoreApplication::translate("MainWindow", "AddTask", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
