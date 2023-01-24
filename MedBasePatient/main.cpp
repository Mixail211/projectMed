#include "patbase.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PatBase w;
    w.show();
    return a.exec();
}
