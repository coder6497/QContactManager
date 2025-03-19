#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QBrush>

namespace Ui {
class Form;
}

class Form : public QWidget {
    Q_OBJECT

  public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::Form *ui;
  signals:
    void show_contact_data(QString name, QString phone, QString email);
};

#endif // FORM_H
