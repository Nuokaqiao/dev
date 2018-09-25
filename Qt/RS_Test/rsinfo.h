#ifndef RSINFO_H
#define RSINFO_H


#include <QWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include "ui_rsinfo.h"

namespace Ui {
class RSInfo;
}

class RSInfo : public QWidget
{
    Q_OBJECT

public:
    explicit RSInfo(QWidget *parent = 0);
    ~RSInfo();
    QLabel *longitude_start;
    QLabel *longitude_stop;
    QLabel *latitude_start;
    QLabel *latitude_stop;


private:
    Ui::RSInfo *ui;
    QScrollArea *area;
    QVBoxLayout *layout;
    QFormLayout *form;
};

#endif // RSINFO_H
