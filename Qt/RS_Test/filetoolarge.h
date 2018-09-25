#ifndef FILETOOLARGE_H
#define FILETOOLARGE_H

#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ui_filetoolarge.h"

namespace Ui {
class FileTooLarge;
}

class FileTooLarge : public QWidget
{
    Q_OBJECT

public:
    explicit FileTooLarge(QWidget *parent = 0);
    ~FileTooLarge();
    QPushButton *resample;
    QPushButton *cut;
    QPushButton *cancle;

private:
    Ui::FileTooLarge *ui;
    QLabel* label;
};

#endif // FILETOOLARGE_H
