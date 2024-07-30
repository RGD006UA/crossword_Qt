#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.setAutoFillBackground(true);
  w.setWindowTitle("Кросворд про Павла Тичину");
  w.setWindowIcon(QIcon("F:\\Projects\\Qt\\krosvord\\images\\icon.jpg"));
  w.show();
  return a.exec();
}
