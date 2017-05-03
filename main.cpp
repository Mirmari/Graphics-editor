#include <QtGui>
#include <QEventLoop>
#include <QtWidgets>
#include <QSplashScreen>
#include <QTime>
#include "mainwindow.h"
void loadModules(QSplashScreen*);
void initSplash();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    initSplash();
    w.setFixedSize(1000,768);
    w.show();
    

    return a.exec();
}

void initSplash()
{
    QSplashScreen splash(QPixmap("start1.png"));
    splash.show();
    QLabel lbl;
    lbl.hide();
    loadModules(&splash);
    splash.finish(&lbl);
}
void loadModules(QSplashScreen *splash)
{
    QTime time;
    time.start();

    for (int i = 0; i < 1000; ++i)
    {
        if(time.elapsed() > 40)
        {
            time.start();
            i++;
        }

        splash->showMessage("");

       // qApp->processEvents();
    }
}
