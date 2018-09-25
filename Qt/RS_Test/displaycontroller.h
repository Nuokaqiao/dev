#ifndef DISPLAYCONTROLLER_H
#define DISPLAYCONTROLLER_H

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QPushButton>
#include "ui_displaycontroller.h"

namespace Ui {
class DisplayController;
}

class DisplayController : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayController(QWidget *parent = 0);
    ~DisplayController();
    QPushButton *ApplyButton;
    QComboBox *RSelector;
    QComboBox *GSelector;
    QComboBox *BSelector;

private:
    Ui::DisplayController *ui;
    QLabel *noticetext;
    QPushButton *CancelButton;
    QScrollArea *area;
};

#endif // DISPLAYCONTROLLER_H
