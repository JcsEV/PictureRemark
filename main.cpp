#include "unistd.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

#include <QMovie>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/resource/loading.gif");
    QSplashScreen splash(pixmap);
    QLabel label(&splash);
    QMovie movie(":/resource/loading.gif");
    label.setMovie(&movie);
    movie.start();
    splash.show();
    splash.setCursor(Qt::BlankCursor);
    for(int i=0; i<5000; i+=movie.speed()) {
        QCoreApplication::processEvents();
        usleep(500*static_cast<useconds_t>(movie.speed()));
    }
    MainWindow w;
    w.show();
    return a.exec();
}
