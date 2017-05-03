#include "mainwindow.h"
#include "myMenu.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(10,10,1024,768);
    interface = new myMenu(this);
    addToolBar(Qt::LeftToolBarArea,interface->createToolBar());

}




MainWindow::~MainWindow()
{
    
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    interface->mousePressEvent(event);

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    interface->mouseMoveEvent(event);
}


