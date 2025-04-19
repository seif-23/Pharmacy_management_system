#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

struct SearchResult
{
    int lineNumber;
    std::vector<std::string> followingLines;
};

class Functions
{
public:
    std::vector<SearchResult> results;
    SearchResult result;

    Functions() = default;
    virtual ~Functions() = default;

    void editData(const std::string &filename, const std::string &searchStr,
                  const std::string &replacementStr);
    void bestSearch(const std::string &filename, const std::string &searchStr, int linsenum);
    void Search(const std::string &filename, const std::string &searchStr, int linsenum);
    bool Searchtt(const std::string &filename, const std::string &searchStr, int linsenum);
    std::string ToLowerS(std::string nameLower);
};

#endif // FUNCTIONS_H