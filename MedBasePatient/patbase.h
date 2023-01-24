#ifndef PATBASE_H
#define PATBASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <helpwindow.h>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class PatBase; }
QT_END_NAMESPACE

class PatBase : public QMainWindow
{
    Q_OBJECT

public:
    PatBase(QWidget *parent = nullptr);
    ~PatBase();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonRemove_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();



private:
    Ui::PatBase *ui;
    QSqlDatabase db; //коннектор
    QSqlTableModel *tabmodel; //модель
    int currentRow; //текущая строка
    HelpWindow help;
    int dates;

};
#endif // PATBASE_H
