#include "myMenu.h"
#include <QStaticText>//!!!!!!!!!!

myMenu::myMenu(QWidget *parent) :
    QWidget(parent)
{
    lbl = NULL;
    lbl = new QLabel((QWidget *)parent);
    prMenu = new QMenu("Menu");
    menuBar.setGeometry(0,0,0,0);

    prMenu->addAction("&Open file",this,SLOT(openFile()));
    prMenu->addSeparator();
    prMenu->addAction("&Save file",this,SLOT(saveFile()));
    prMenu->addSeparator();
    prMenu->addAction("&Close program",(QWidget *)parent,SLOT(close()));
    menuBar.addMenu(prMenu);
    menuBar.setParent((QWidget *)parent);
    menuBar.show();

//    color = new QColorDialog((QWidget *)parent);
    sColor = Qt::black;

    relay = 0;
    x0 =-1;
    y0 =-1;

    img.load("Start.png");
    lbl->setGeometry(100,5,900,1000);
    lbl->setFixedSize(img.size());
    lbl->setPixmap(QPixmap::fromImage(img));
    lbl->show();
    size = 8;
}


void myMenu::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open file","","Image files(*.jpg);;C++ Files(*.png *.h)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Alarm bleat`";
    }
    img.load(fileName);

    lbl->hide();
    lbl = new QLabel((QWidget *)parent());
    lbl->setGeometry(100,5,768,1000);
    lbl->setFixedSize(img.size());
    lbl->setStyleSheet("background-color: green");
    lbl->setPixmap(QPixmap::fromImage(img));
    lbl->show();

    file.close();


}

void myMenu::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open file","","Image files(*.jpg);;C++ Files(*.cpp *.h)");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"Alarm bleat`";
    }
    img.save(fileName);
    file.close();
}

void myMenu::mousePressEvent(QMouseEvent *event)
{


    QPainter paint;
    switch(relay)
    {
    case 1:
        {
            paint.begin(&img);
            QPen pen;
            pen.setWidth(size);
            pen.setColor(sColor);
            paint.setPen(pen);
            paint.drawPoint(event->x()-lbl->x(),event->y());
            lbl->setPixmap(QPixmap::fromImage(img));
            paint.end();
        }
        break;
    case 4:
        {
            paint.begin(&img);
            QPen pen;
            pen.setWidth(size);
            pen.setColor(sColor);
            paint.setPen(pen);
            if(x0 >= 0 && y0 >= 0)
            {
                paint.drawLine(x0,y0,event->x()-lbl->x(),event->y());
                x0 = -1;
                y0 = -1;
            }
            else
            {
                x0 = event->x()-lbl->x();
                y0 = event->y();
            }
            lbl->setPixmap(QPixmap::fromImage(img));
            paint.end();
        }
        break;
    case 5:
        {
            paint.begin(&img);
            QPen pen;
            pen.setWidth(size);
            pen.setBrush(Qt::green);
            pen.setColor(sColor);


            paint.setPen(pen);
            if(x0 >= 0 && y0 >= 0)
            {
                paint.drawRect(event->x()-lbl->x(),event->y(),
                               x0 - (event->x()-lbl->x()),y0 - event->y());
                x0 = -1;
                y0 = -1;
            }
            else
            {
                x0 = event->x()-lbl->x();
                y0 = event->y();
            }
            lbl->setPixmap(QPixmap::fromImage(img));
            paint.end();
        }
        break;
    case 6:
        {
            paint.begin(&img);
            QPen pen;
            pen.setWidth(size);
            pen.setColor(sColor);

            paint.setPen(pen);
            if(x0 >= 0 && y0 >= 0)
            {
                paint.drawEllipse(event->x()-lbl->x(),event->y(),
                                  x0 - (event->x()-lbl->x()),y0 - event->y());
                x0 = -1;
                y0 = -1;
            }
            else
            {
                x0 = event->x()-lbl->x();
                y0 = event->y();
            }
            lbl->setPixmap(QPixmap::fromImage(img));
            paint.end();
        }
        break;
    case 7:
        {
            paint.begin(&img);
            QPen pen;
            QFont font;
            font.setPixelSize(size);
            pen.setWidth(size);
            pen.setColor(sColor);
            paint.setFont(font);
            paint.setPen(pen);
            if(x0 >= 0 && y0 >= 0)
            {
                QRect rect(event->x()-lbl->x(),event->y(),
                           x0 - (event->x()-lbl->x()),y0 - event->y());
                bool ok;
                QString str = QInputDialog::getText((QWidget*)parent(),
                                                    "Please enter text","Enter text", QLineEdit::Normal,"",&ok);

                x0 = -1;
                y0 = -1;

              paint.drawText(rect,Qt::AlignCenter,str);

                }
                else
                {
                    x0 = event->x()-lbl->x();
                    y0 = event->y();
                }

                lbl->setPixmap(QPixmap::fromImage(img));
                paint.end();
        }
        break;
    default:
        break;
    }

}

void myMenu::mouseMoveEvent(QMouseEvent *event)
{

    QPainter paint;
    switch(relay)
    {
    case 2:
        {
            paint.begin(&img);
            paint.setRenderHint(QPainter::Antialiasing,true);
            QPen pen;
            pen.setWidth(size);
            pen.setColor(sColor);
            paint.setPen(pen);
            paint.drawPoint(event->x()-lbl->x(),event->y());
            lbl->setPixmap(QPixmap::fromImage(img));

        }
        break;
    case 3:
        {
            paint.begin(&img);
            paint.setRenderHint(QPainter::Antialiasing,true);
            QPen pen;
            pen.setWidth(size);
            pen.setColor(Qt::white);
            paint.setPen(pen);
            paint.drawPoint(event->x()-lbl->x(),event->y());
            lbl->setPixmap(QPixmap::fromImage(img));

        }
        break;
    default:
        break;
    }

}

QToolBar *myMenu::createToolBar()
{
    QImage color("color1.png");
    QImage pSize("SizePM.png");
    QImage free("hand.png");
    QImage line("Line1.png");
    QImage rect("rect.png");
    QImage clear("clear.png");
    QImage elips("elips.png");
    QImage eraser("eraser.png");
    QImage text("ntext.png"); //Mari
    QToolBar *toolB = new QToolBar("Menu",(QWidget *)parent());
    toolB->setAllowedAreas( Qt::LeftToolBarArea    | Qt::RightToolBarArea);
    toolB->setGeometry(40,0,0,0);
    toolB->setIconSize(QSize(60,60));
    toolB->addAction(QPixmap::fromImage(free), "Free draw",this, SLOT(drFree()));
    toolB->addAction(QPixmap::fromImage(line), "Draw line",this,SLOT(drLine()));
    toolB->addAction(QPixmap::fromImage(rect), "Draw Rect",this, SLOT(drRect()));
    toolB->addAction(QPixmap::fromImage(elips), "Draw Elipse",this, SLOT(drElipse()));
    toolB->addAction(QPixmap::fromImage(eraser), "Eraser",this,SLOT(drErase()));
    toolB->addAction(QPixmap::fromImage(text), "Draw Text",this,SLOT(drText()));
    toolB->addAction(QPixmap::fromImage(pSize), "Change size",this,SLOT(changeSize()));
    toolB->addAction(QPixmap::fromImage(color), "Change color",this,SLOT(setColor()));

    toolB->addSeparator();
    toolB->addAction(QPixmap::fromImage(clear), "Clear",this,SLOT(lblClear()));

    return toolB;
}

void myMenu::drPoint()
{
    if(lbl)
    {
     relay = 1;
    }else
        qDebug()<<"Download picture";
}

void myMenu::drLine()
{

    if(lbl)
    {
        relay = 4;
        x0 = -1;
        y0 = -1;
    }else
    qDebug()<<"Download picture";
}

void myMenu::drFree()
{
    if(lbl)
    {
    relay = 2;
    } else
        qDebug()<<"Download picture";

}

void myMenu::drRect()
{
    if(lbl)
    {
        relay = 5;
    }else
         qDebug()<<"Download picture";
}

void myMenu::drElipse()
{
    if(lbl)
    {
        relay = 6;
    }else
        qDebug()<<"Download picture";

}

void myMenu::drText()
{
    if(lbl)
    {
        relay = 7;
    }else
        qDebug()<<"Download picture";

}

void myMenu::drErase()
{
    if(lbl)
    {
        relay = 3;
    }else
        qDebug()<<"Download picture";
}

void myMenu::lblClear()
{
    if(lbl != NULL)
    {
        delete lbl;
        lbl = NULL;
        lbl = new QLabel((QWidget *)parent());
        img.load("Start.png");
        lbl->setGeometry(100,5,768,1000);
        lbl->setFixedSize(img.size());
        lbl->setPixmap(QPixmap::fromImage(img));
        lbl->show();

    }

}

void myMenu::setColor()
{
    sColor = QColorDialog::getColor();
}

void myMenu::changeSize()
{
    size = QInputDialog::getInt((QWidget *)parent(),"Size","choose your size",1,1,70,1);
}








