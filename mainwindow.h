#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
#include "myLabel.h"
#include "myMenu.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *main;
    QVBoxLayout *lay;
    myMenu *interface;
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

protected:
private:
};

#endif // MAINWINDOW_H
