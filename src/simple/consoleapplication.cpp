#include "simple/consoleapplication.h"
#include "qt/database.h"
#include "qt/databasebuilder.h"

SimpleConsoleApplication::SimpleConsoleApplication() {
    QtDataBaseBuilder builder;
    m_database = builder.getDatabase();
    std::cout << "Welcome to the dictionary! Enter any word and see if the dictionary has it.\n\n";
}
void SimpleConsoleApplication::run() {
    while (true) {
        std::string word;
        std::cin >> word;
        std::shared_ptr<Query> query = std::make_shared<SimpleQuery>(word);
        std::shared_ptr<QueryAnswer> answer = m_database->search(query);
        answer->print();
        std::cout << "\n";
    }
}

