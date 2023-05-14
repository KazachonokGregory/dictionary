#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include "qt/database.h"
#include "qt/databasebuilder.h"

TEST(DataBaseTests, TestSearch) {
    QtDataBaseBuilder builder;
    auto database = builder.getDatabase();
    std::shared_ptr<SimpleQuery> query = std::make_shared<SimpleQuery>(std::string("abaca")); 
    std::shared_ptr<SimpleQueryAnswer> query_answer = std::dynamic_pointer_cast<SimpleQueryAnswer>(database->search(query));
    std::string result = query_answer->getData();
    ASSERT_EQ(result, "абака");
}

TEST(DataBaseTests, TestSearchUnexisistent) {
    QtDataBaseBuilder builder;
    auto database = builder.getDatabase();
    std::shared_ptr<SimpleQuery> query = std::make_shared<SimpleQuery>(std::string("nonsense string")); 
    std::shared_ptr<SimpleQueryAnswer> query_answer = std::dynamic_pointer_cast<SimpleQueryAnswer>(database->search(query));
    std::string result = query_answer->getData();
    ASSERT_EQ(result, "Nothing was found!");
}

