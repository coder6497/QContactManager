#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(QColor(112, 128, 144), Qt::SolidPattern));
    setPalette(pal);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"name", "phone", "email"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Widget::~Widget() { delete ui; }

void Widget::on_pushButton_2_clicked()
{
    form = new Form();
    form->show();
    connect(form, &Form::show_contact_data, this, &Widget::updateTable);
}


void Widget::on_pushButton_clicked()
{
    QString QtfileName = QFileDialog::getOpenFileName(nullptr, "Выберите CSV файл", "", "CSV Files (*.csv);;All Files (*)");
    if (!QtfileName.isEmpty())
        ui->label_2->setText(QtfileName);
    std::string string_filename = QtfileName.toStdString();
    std::ifstream in(string_filename);
    std::string line;
    std::vector<std::vector<std::string>> table_vector;
    int col_count = 0;
    if (in.is_open())
    {
        while(std::getline(in, line))
        {
            std::vector<std::string> rows;
            std::string element;
            std::stringstream ss(line);
            while(std::getline(ss, element, ','))
            {
                rows.push_back(element);
            }
            table_vector.push_back(rows);
        }
    }
    in.close();
    for (const auto& row: table_vector)
    {
        ui->tableWidget->setRowCount(table_vector.size());
        for (const auto& elem: row)
        {
            std::cout << elem << " ";
            ui->tableWidget->setItem(0, col_count, new QTableWidgetItem(QString::fromStdString(elem)));
            col_count++;
        }
        std::cout << std::endl;
    }
}

void Widget::updateTable(QString name, QString phone, QString email)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(phone));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(email));
}

void Widget::on_pushButton_3_clicked()
{
    QModelIndexList selected = ui->tableWidget->selectionModel()->selectedRows();
    for (int i = 0; i < selected.count(); i++)
    {
        int row = selected[i].row();
        ui->tableWidget->removeRow(row);
    }
}


void Widget::on_pushButton_4_clicked()
{
    QString QtfileName = QFileDialog::getSaveFileName(nullptr, "Куда сохранить?", "", "CSV Files (*.csv);;All Files (*)");
}

