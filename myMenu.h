#ifndef MYMENU_H
#define MYMENU_H


#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QPalette>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <QCursor>
#include <QPushButton>
#include <QColor>
#include <QColorDialog>
#include <QToolBar>
#include <QInputDialog>

class myMenu : public QWidget
{
    Q_OBJECT

    QMenu *prMenu;
    QMenuBar menuBar;
    QPushButton *btLine;
    QPushButton *btFree;
    QPushButton *btClear;
    QPushButton *btColor;
    QPushButton *btPlus;
    QPushButton *btMinus;
//    QToolBar *toolB;
    QColor sColor;
//    QColorDialog *color;
    int size;
    int x0,y0;

//    QLabel *lbl;
//    QImage img;
public:
    explicit myMenu(QWidget *parent = 0);
     QToolBar* createToolBar();
    
signals:
public:
    QLabel *lbl;
    QImage img;
    int relay;
    
public slots:
    void openFile();
    void saveFile();
    void drPoint();
    void drLine();
    void drFree();
    void drRect();
    void lblClear();
    void setColor();
    void changeSize();
    void drElipse();
    void drText();
    void drErase();
public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);



    
};

#endif // MYMENU_H
