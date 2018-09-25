#ifndef DIAPLAY_CHANGE_H
#define DIAPLAY_CHANGE_H

#include <QWidget>

namespace Ui {
class diaplay_change;
}

class diaplay_change : public QWidget
{
    Q_OBJECT

public:
    explicit diaplay_change(QWidget *parent = 0);
    ~diaplay_change();

private:
    Ui::diaplay_change *ui;
};

#endif // DIAPLAY_CHANGE_H
