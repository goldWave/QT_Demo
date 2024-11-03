#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "qtTrans_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }

    QTranslator translator;
    auto isSue =  translator.load("qtTrans_zh_CN.qm", R"(C:\Users\jimbo\Documents\qtTrans)");
    qDebug() <<"isLoad succeed" << isSue;
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
