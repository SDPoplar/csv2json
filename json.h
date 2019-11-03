#pragma once

#include <fstream>
#include <string>
#include <vector>

class JSON
{
public:
    JSON( std::string fileName );
    ~JSON( void );

    bool valid( void ) const noexcept;
    std::string GetFilePath() const noexcept;

    void SetColumns( std::vector<std::string> columns );
    void Append( std::vector<std::string> line );

    void Write();

protected:
    std::ofstream m_file;
    std::string m_s_fileName;

    std::vector<std::string> m_columns;
    std::vector<std::string> m_lines;
};
