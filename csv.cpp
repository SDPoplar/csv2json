#include "csv.h"
#include <regex>
#include "str.h"

CSV::CSV( std::string fileName )
{
    std::regex patten( "(.+[\\\\|\\/])*([^\\\\|\\/]+)\.csv" );
    std::smatch matches;
    if( !std::regex_search( fileName, matches, patten ) )
    {
        return;
    }
    this->m_s_path = matches[ 1 ];
    this->m_s_name = matches[ 2 ];
    this->m_file.open( fileName, std::ios::in );
    char line[ 128 ];
    this->m_file.getline( line, 128 );
    this->m_columns = StrSplit( line, ',', true );
}

CSV::~CSV()
{
    if( this->m_file.is_open() )
    {
        this->m_file.close();
    }
}

bool CSV::valid( void ) const noexcept
{
    return this->m_file.is_open();
}

std::string CSV::MakeJsonPath()
{
    std::string path = this->m_s_path;
    path += this->m_s_name;
    path += ".json";
    return path;
}

std::vector<std::string> CSV::GetColumns() const noexcept
{
    return this->m_columns;
}

bool CSV::GetLine( std::vector<std::string>& line )
{
    if( this->m_file.eof() )
    {
        return false;
    }
    char fileline[ 1024 ];
    this->m_file.getline( fileline, 1024 );
    line = StrSplit( fileline, ',', true );
    return true;
}
