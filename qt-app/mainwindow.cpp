#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qt/databasebuilder.h"
#include <memory>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QtDataBaseBuilder builder;
    database = builder.getDatabase();
    std::vector<std::string> supported_langs = std::dynamic_pointer_cast<QtDataBase>(database)->get_langs();

    QStringList list;
    for (auto lang : supported_langs) {
        list << QString::fromStdString(lang);
    }
    ui->translationLang->addItems(list);
    ui->translationLang->setCurrentIndex(0);
    ui->originalLang->addItems(list);
    ui->originalLang->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // get translation
    std::shared_ptr<SimpleQuery> query = std::make_shared<SimpleQuery>(ui->originalEdit->toPlainText().toStdString()); 
    std::shared_ptr<SimpleQueryAnswer> query_answer = std::dynamic_pointer_cast<SimpleQueryAnswer>(database->search(query));
    ui->translationEdit->document()->setPlainText(QString::fromStdString(query_answer->getData()));
}





