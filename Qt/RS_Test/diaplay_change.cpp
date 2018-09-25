#include "diaplay_change.h"
#include "ui_diaplay_change.h"

diaplay_change::diaplay_change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diaplay_change)
{
    ui->setupUi(this);
}

diaplay_change::~diaplay_change()
{
    delete ui;
}
