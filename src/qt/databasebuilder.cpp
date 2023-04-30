#include "qt/databasebuilder.h"
#include <fstream>

QtDataBaseBuilder::~QtDataBaseBuilder() {}

QtDataBaseBuilder::QtDataBaseBuilder() {
    connectToDataBase();

    QSqlQuery query;

}

//  code was taken from https://evileg.com/ru/post/62/

void QtDataBaseBuilder::connectToDataBase() {
    if(!QFile(QDir::currentPath() + "/dictionary.db").exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool QtDataBaseBuilder::restoreDataBase() {
    if(this->openDataBase()) {
        if(!this->createTable()) {
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Unable to restore Data base";
        return false;
    }
    return false;
}

bool QtDataBaseBuilder::openDataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath() + "/dictionary.db");
    
    if (!db.open()) {
        qDebug() << "error insert";
        qDebug() << db.lastError().text();
        return false;
    } else {
        return true;
    }

}

bool QtDataBaseBuilder::createTable() {
    QSqlQuery query;
    if (query.exec("CREATE TABLE DICTIONARY ( ID INTEGER PRIMARY KEY AUTOINCREMENT, \
                    ORIGINAL VARCHAR(255) NOT NULL, \
                    TRANSLATION VARCHAR(255) NOT NULL \
    )")) {
        qDebug() << "Create success\n";

        query.exec("ALTER TABLE DICTIONARY NOCHECK CONSTRAINT ALL");
        query.exec("ALTER INDEX [IX_InvoiceDetail_1] ON [dbo].[InvoiceDetail] DISABLE");
        if (!parseEngRus()) {
            qDebug() << "Couldn't parse English to Russian!";
            return false;
        }
        addEntry("cat", "aboba");
        query.exec("ALTER TABLE DICTIONARY CHECK CONSTRAINT ALL");
        query.exec("ALTER INDEX [IX_InvoiceDetail_1] ON [dbo].[InvoiceDetail] REBUILD PARTITION = ALL WITH ( PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON, ONLINE = OFF, SORT_IN_TEMPDB = OFF )");

        return true;
    } else {
        qDebug() << "Create fail\n";
        qDebug() << query.lastError().text();
        return false;
    }
}

bool QtDataBaseBuilder::addEntry(std::string original, std::string translation) {
    QSqlQuery query;
    
    query.prepare("INSERT INTO DICTIONARY (ORIGINAL, TRANSLATION) VALUES ( ?, ? )");
    query.addBindValue(QString::fromStdString(original));
    query.addBindValue(QString::fromStdString(translation));

    if (!query.exec()) {
        qDebug() << "insert error";
        qDebug() << query.lastError().text();
        return false;
    } else {
//        qDebug() << "insert success";
    }
    return true;
}

std::shared_ptr<DataBase> QtDataBaseBuilder::getDatabase() {
    return std::make_shared<QtDataBase>(db, std::vector<std::string>({"Russian", "English"}));
}

bool QtDataBaseBuilder::parseEngRus() {
    auto file_path = QDir::cleanPath(QDir().absoluteFilePath("../raw/eng-rus.txt"));
    qDebug() << file_path;

    QFile file(file_path);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "file not found";
        qDebug() << file.errorString();
        qDebug() << file_path;
        return 0;
    }


    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        QString original = fields.at(0);
        QString translation = fields.at(1);
        qDebug() << original << translation;
        addEntry(original.toStdString(), translation.toStdString());
    }

    file.close();

    return true;
}
