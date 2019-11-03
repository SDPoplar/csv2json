#pragma once

#include <fstream>
#include <string>
#include <vector>

class CSV
{
public:
    CSV( std::string fileName );
    ~CSV();

    bool valid( void ) const noexcept;
    std::string MakeJsonPath();

    std::vector<std::string> GetColumns() const noexcept;
    bool GetLine( std::vector<std::string> &line );

protected:
    std::ifstream m_file;

    std::string m_s_path;
    std::string m_s_name;

    std::vector<std::string> m_columns;
};
