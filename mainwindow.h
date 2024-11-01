// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QStandardPaths>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private slots:
//     void on_btnAddTask_clicked();        // Slot for adding a work task
//     void on_btnDelete_clicked();          // Slot for deleting a work task
//     void on_btnClearAll_clicked();        // Slot for clearing all work tasks
//     void on_btnAddTask_2_clicked();      // Slot for adding a break task
//     void on_btnDelete_2_clicked();        // Slot for deleting a break task
//     void on_btnClearAll_2_clicked();      // Slot for clearing all break tasks

// private:
//     Ui::MainWindow *ui;

//     QString currentFile; // Track the current task file
//     QString workPath;    // File path for work tasks
//     QString breakPath;   // File path for break tasks

//     void loadTasks(); // Load tasks from the current file
//     void saveTasks(); // Save tasks to the current file
// };

// #endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QTimer> // Include QTimer for timer functionality
#include "TaskPopUp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddTask_clicked();        // Slot for adding a work task
    void on_btnDelete_clicked();          // Slot for deleting a work task
    void on_btnClearAll_clicked();        // Slot for clearing all work tasks
    void on_btnAddTask_2_clicked();      // Slot for adding a break task
    void on_btnDelete_2_clicked();        // Slot for deleting a break task
    void on_btnClearAll_2_clicked();      // Slot for clearing all break tasks
    void on_btnStartTimer_clicked();      // Slot for starting the countdown timer
    void on_btnStopTimer_clicked();       // Slot for stopping the countdown timer
    void on_btnResetTimer_clicked();      // Slot for resetting the countdown timer
    void updateTimer();
    void showTaskPopUp();        // Slot to update the timer display

private:
    Ui::MainWindow *ui;

    QString currentFile; // Track the current task file
    QString workPath;    // File path for work tasks
    QString breakPath;   // File path for break tasks

    QTimer *timer;       // Timer for countdown
    int countdownTime;   // Countdown time in seconds

    void loadWorkTasks(); // Load tasks from the current file
    void saveWorkTasks(); // Save tasks to the current file
    void loadBreakTasks();
    void saveBreakTasks();
};

#endif // MAINWINDOW_H

