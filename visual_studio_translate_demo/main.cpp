#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    // 工作目录为 可执行文件的 exe所在的 目录
    auto isSue =  translator.load("vs_qtTrans_zh_CN.qm", QCoreApplication::applicationDirPath());
    qDebug() << "isLoad: " << isSue << " workDri: " << QCoreApplication::applicationDirPath();
    a.installTranslator(&translator);
       
    MainWindow w;
    w.show();
    return a.exec();
}
