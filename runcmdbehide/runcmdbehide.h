#ifndef RUNCMDBEHIDE_H
#define RUNCMDBEHIDE_H

#include <QtGui/QMainWindow>
#include "ui_runcmdbehide.h"

class runcmdbehide : public QMainWindow
{
    Q_OBJECT

public:
    runcmdbehide(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~runcmdbehide();

private:
    Ui::runcmdbehideClass ui;
};

#endif // RUNCMDBEHIDE_H
