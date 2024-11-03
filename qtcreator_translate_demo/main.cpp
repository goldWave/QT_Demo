#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    // 工作目录为 可执行文件的 exe所在的 目录
    auto isSue =  translator.load("qtTrans_zh_CN.qm", QCoreApplication::applicationDirPath());
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
