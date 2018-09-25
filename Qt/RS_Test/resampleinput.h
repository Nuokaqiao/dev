#ifndef RESAMPLEINPUT_H
#define RESAMPLEINPUT_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include "ui_resampleinput.h"

namespace Ui {
class resampleinput;
}

class resampleinput : public QDialog
{
    Q_OBJECT

public:
    explicit resampleinput(QWidget *parent = 0);
    ~resampleinput();
    double getdoublex();
    double getdoubley();
private:
    Ui::resampleinput *ui;
    QLineEdit *xLineEdit;
    QLineEdit *yLineEdit;
};

#endif // RESAMPLEINPUT_H
