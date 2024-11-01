// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <QFile>
// #include <QStandardPaths>
// #include <QMessageBox>
// #include <QTextStream>

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);

//     workPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\workTasks.txt";
//     breakPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\breakTasks.txt";

//     // Create task files if they don't exist
//     QFile workFile(workPath);
//     if (!workFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
//         QMessageBox::information(this, "Error", workFile.errorString());
//     }
//     workFile.close();

//     QFile breakFile(breakPath);
//     if (!breakFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
//         QMessageBox::information(this, "Error", breakFile.errorString());
//     }
//     breakFile.close();

//     currentFile = workPath; // Default to work tasks
//     loadTasks(); // Load tasks for the default category

//     // Set Work Tasks radio button as checked
//     ui->radioWorkTask->setChecked(true);

//     connect(ui->radioWorkTask, &QRadioButton::toggled, this, &MainWindow::on_radioWorkTask_toggled);
//     connect(ui->radioBrkTask, &QRadioButton::toggled, this, &MainWindow::on_radioBrkTask_toggled);

//     // Connect the returnPressed signal to add task slot
//     connect(ui->txtNewTask, &QLineEdit::returnPressed, this, &MainWindow::on_btnAddTask_clicked);
// }

// MainWindow::~MainWindow()
// {
//     saveTasks(); // Save tasks when exiting
//     delete ui;
// }

// void MainWindow::loadTasks()
// {
//     ui->listWidget->clear(); // Clear the current list

//     QFile file(currentFile); // Use the current file path

//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QMessageBox::information(this, "Error", file.errorString());
//         return;
//     }

//     QTextStream fileIn(&file);
//     while (!fileIn.atEnd()) {
//         QListWidgetItem* item = new QListWidgetItem(fileIn.readLine(), ui->listWidget);
//         ui->listWidget->addItem(item);
//         item->setFlags(item->flags() | Qt::ItemIsEditable);
//     }

//     file.close();
// }

// void MainWindow::saveTasks()
// {
//     QFile file(currentFile);
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         QMessageBox::information(this, "Error", file.errorString());
//         return;
//     }

//     QTextStream fileOut(&file);
//     for (int i = 0; i < ui->listWidget->count(); ++i) {
//         fileOut << ui->listWidget->item(i)->text() << "\n";
//     }

//     file.close();
// }

// void MainWindow::on_btnAddTask_clicked()
// {
//     QString taskText = ui->txtNewTask->text().trimmed();

//     if (!taskText.isEmpty()) {
//         QListWidgetItem* item = new QListWidgetItem(taskText, ui->listWidget);
//         ui->listWidget->addItem(item);
//         item->setFlags(item->flags() | Qt::ItemIsEditable);
//     } else {
//         QMessageBox::warning(this, "Warning", "Task cannot be empty.");
//     }

//     ui->txtNewTask->clear();
//     ui->txtNewTask->setFocus();
// }

// void MainWindow::on_btnDelete_clicked()
// {
//     QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
//     delete item;
// }

// void MainWindow::on_btnClearAll_clicked()
// {
//     ui->listWidget->clear();
// }

// void MainWindow::on_radioWorkTask_toggled()
// {
//     if (ui->radioWorkTask->isChecked()) {
//         saveTasks(); // Save current tasks before switching
//         currentFile = workPath; // Set current file to work tasks
//         loadTasks(); // Load work tasks
//     }
// }

// void MainWindow::on_radioBrkTask_toggled()
// {
//     if (ui->radioBrkTask->isChecked()) {
//         saveTasks(); // Save current tasks before switching
//         currentFile = breakPath; // Set current file to break tasks
//         loadTasks(); // Load break tasks
//     }
// }

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize file paths for CSV files
    workPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/workTasks.csv";
    breakPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/breakTasks.csv";

    // Load tasks when starting the application
    loadWorkTasks();
    loadBreakTasks();

    // Initialize timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    // Set countdown time to 25 minutes (1500 seconds)
    countdownTime = 1500;
    ui->lblTimer->setText(QTime(0, 25).toString("mm:ss"));

    connect(ui->txtNewTask, &QLineEdit::returnPressed, this, &MainWindow::on_btnAddTask_clicked);
    // Assuming you have a button named 'taskButton' in your UI
    connect(ui->taskButton, &QPushButton::clicked, this, &MainWindow::showTaskPopUp);

}

MainWindow::~MainWindow()
{
    saveWorkTasks(); // Save work tasks when exiting
    saveBreakTasks(); // Save break tasks when exiting
    delete ui;
}

void MainWindow::loadWorkTasks()
{
    ui->listWidget->clear(); // Clear the current list

    QFile file(workPath); // Use the work tasks file path

    // Check if the file exists
    if (!QFile::exists(workPath)) {
        // If not, create an empty file
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Error", file.errorString());
        return;
    }

    QTextStream fileIn(&file);
    while (!fileIn.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(fileIn.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

void MainWindow::saveWorkTasks()
{
    QFile file(workPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Error", file.errorString());
        return;
    }

    QTextStream fileOut(&file);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        fileOut << ui->listWidget->item(i)->text() << "\n";
    }

    file.close();
}

void MainWindow::loadBreakTasks()
{
    ui->listWidget_2->clear(); // Clear the current list

    QFile file(breakPath); // Use the break tasks file path

    // Check if the file exists
    if (!QFile::exists(breakPath)) {
        // If not, create an empty file
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Error", file.errorString());
        return;
    }

    QTextStream fileIn(&file);
    while (!fileIn.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(fileIn.readLine(), ui->listWidget_2);
        ui->listWidget_2->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

void MainWindow::saveBreakTasks()
{
    QFile file(breakPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Error", file.errorString());
        return;
    }

    QTextStream fileOut(&file);
    for (int i = 0; i < ui->listWidget_2->count(); ++i) {
        fileOut << ui->listWidget_2->item(i)->text() << "\n";
    }

    file.close();
}

void MainWindow::on_btnAddTask_clicked()
{
    QString taskText = ui->txtNewTask->text().trimmed();

    if (!taskText.isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem(taskText, ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    } else {
        QMessageBox::warning(this, "Warning", "Task cannot be empty.");
    }

    ui->txtNewTask->clear();
    ui->txtNewTask->setFocus();
}

void MainWindow::on_btnDelete_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}

void MainWindow::on_btnClearAll_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_btnAddTask_2_clicked()
{
    QString taskText = ui->txtNewTask_2->text().trimmed();

    if (!taskText.isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem(taskText, ui->listWidget_2);
        ui->listWidget_2->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    } else {
        QMessageBox::warning(this, "Warning", "Task cannot be empty.");
    }

    ui->txtNewTask_2->clear();
    ui->txtNewTask_2->setFocus();
}

void MainWindow::on_btnDelete_2_clicked()
{
    QListWidgetItem* item = ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    delete item;
}

void MainWindow::on_btnClearAll_2_clicked()
{
    ui->listWidget_2->clear();
}

// Timer methods
void MainWindow::updateTimer()
{
    if (countdownTime > 0) {
        countdownTime--;
        int minutes = countdownTime / 60;
        int seconds = countdownTime % 60;
        ui->lblTimer->setText(QString::number(minutes).rightJustified(2, '0') + ":" + QString::number(seconds).rightJustified(2, '0'));
    } else {
        timer->stop();
        QMessageBox::information(this, "Time's up!", "The countdown has finished.");
    }
}

void MainWindow::on_btnStartTimer_clicked()
{
    if (!timer->isActive()) {
        timer->start(1000); // Start timer with a 1-second interval
    }
}

void MainWindow::on_btnStopTimer_clicked()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void MainWindow::on_btnResetTimer_clicked()
{
    if (timer->isActive()) {
        timer->stop();
    }
    countdownTime = 1500; // Reset to 25 minutes
    ui->lblTimer->setText(QTime(0, 25).toString("mm:ss"));
}

void MainWindow::showTaskPopUp() {
    TaskPopUp *popup = new TaskPopUp(this);
    popup->show(); // Use show() since it's not a modal dialog
}

