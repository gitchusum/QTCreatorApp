#include "TaskPopUp.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

TaskPopUp::TaskPopUp(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Task Popup");
    resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("This is a task popup!", this);
    QPushButton *closeButton = new QPushButton("Close", this);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &TaskPopUp::close);
}
