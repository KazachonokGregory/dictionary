#include "qt/database.h"

QtDataBase::QtDataBase(QSqlDatabase db, std::vector<std::string> supported_langs):
    db(db),
    supported_langs(supported_langs) {}

QtDataBase::~QtDataBase() {
    db.close();
}

std::shared_ptr<QueryAnswer> QtDataBase::search(const std::shared_ptr<Query> query) const {
    const std::shared_ptr<SimpleQuery> simpleQuery = std::dynamic_pointer_cast<SimpleQuery>(query);
    if (simpleQuery == nullptr) {
        throw std::runtime_error("Error: wrong type of Query");
    }
    std::string word = simpleQuery->get_word();
//    qDebug() << QString::fromStdString(word) << "\n";
    QSqlQuery sql_query;
    sql_query.prepare("SELECT TRANSLATION FROM DICTIONARY WHERE ORIGINAL = :Original");
    sql_query.bindValue(":Original", QString::fromStdString(word));
    sql_query.exec();
    std::stringstream ss;
    if (sql_query.next()) {
        ss << sql_query.value(0).toString().toStdString();
//        ss << sql_query.value(1).toString().toStdString() << "\n";
    } else {
        ss << "Nothing was found!";
    }
    return std::make_shared<SimpleQueryAnswer>(ss.str());
}

