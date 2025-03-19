#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QBrush>
#include <QFileDialog>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

  private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void updateTable(QString name, QString phone, QString email);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

  private:
    Ui::Widget *ui;
    Form* form;

};
#endif // WIDGET_H
