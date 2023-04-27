#include "simple/entry.h"

SimpleEntry::SimpleEntry(std::string original, std::string translation):
    m_original(original),
    m_translation(translation)
{}

void SimpleEntry::updateMap(std::map<std::string, std::string>& dictionary) {
    dictionary[m_original] = m_translation;
}
