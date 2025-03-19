#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(QColor(112, 128, 144), Qt::SolidPattern));
    setPalette(pal);
}

Form::~Form() { delete ui; }

void Form::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text(), phone = ui->lineEdit_2->text(), email = ui->lineEdit_3->text();
    if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty())
    {
        qDebug() << name << phone << email;
        emit show_contact_data(name, phone, email);
        close();
    }
}

