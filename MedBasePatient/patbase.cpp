#include "patbase.h"
#include "ui_patbase.h"

PatBase::PatBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatBase)
{
    ui->setupUi(this);
    this->setWindowTitle("MedList");


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //указываем драйвер.
    db.setDatabaseName("./../MedBase/MedBase.db"); //Подключаем базу sqllite.
    if (db.open()) //Проверка подключения в статус баре.
    {
        ui->statusbar->showMessage("База данных подключена");
        tabmodel = new QSqlTableModel(this, db); // создание модели(родитель, коннектор БД).
        tabmodel ->setTable("MedicalPatient"); //указывается название таблицы БД.
        tabmodel ->select(); //запрос данных из БД.
        ui->tableView->setModel(tabmodel); // задание модели.
    }
    else
    {
        ui->statusbar->showMessage("Ошибка подключения базы данных " + db.lastError().databaseText());
    }
}
PatBase::~PatBase()
{
    delete ui;
}

void PatBase::on_pushButtonAdd_clicked()
{
    tabmodel ->insertRow(tabmodel -> rowCount()); //добавление новой строки, передача количества строк.
}

void PatBase::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row(); //присвоение индекса строки
   // dates = currentRow; // просмотор индекса строки в статусбаре
   // QString s = QString::number(dates);
   // ui->statusbar->showMessage(s);

}
void PatBase::on_pushButtonRemove_clicked()
{
    tabmodel ->removeRow(currentRow); // удаление строки по индексу
    tabmodel ->select();
}


void PatBase::on_pushButton_3_clicked()
{
    help.show();
}



