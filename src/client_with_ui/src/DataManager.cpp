#include "DataManager.hpp"

TDataManager::TDataManager() {}

void TDataManager::Update(){
    this->Parse();
}

bool TDataManager::empty(){
    return this->data.empty();
}

std::pair<std::string, std::string> TDataManager::Get()
{
    std::pair<std::string, std::string> result = this->data.front();
    this->data.pop();

    return result;
}

