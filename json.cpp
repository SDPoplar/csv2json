#include "json.h"
#include <regex>
#include "str.h"

JSON::JSON( std::string fileName )
{
    this->m_s_fileName = fileName;
    this->m_file.open( fileName, std::ios::out );
}

JSON::~JSON( void )
{
    if( this->m_file.is_open() )
    {
        this->m_file.close();
    }
}

bool JSON::valid( void ) const noexcept
{
    return this->m_file.is_open();
}

std::string JSON::GetFilePath() const noexcept
{
    return this->m_s_fileName;
}

void JSON::SetColumns( std::vector<std::string> columns )
{
    this->m_columns = columns;
}

void JSON::Append( std::vector<std::string> line )
{
    int size = this->m_columns.size();
    for( int i = 0; i < size; i++ )
    {
        std::string item = this->m_columns[ i ];
        item += ": ";
        item += ( ( i >= line.size() ) ? "-" : line[ i ] );
        line[ i ] = item;
    }
    std::string l = "\t{";
    l += StrJoin( line, ", " );
    l += "}";
    this->m_lines.push_back( l );
}

void JSON::Write()
{
    this->m_file.write( "[\n", strlen( "[\n" ) );
    for( auto line = this->m_lines.begin(); line<this->m_lines.end(); line++ )
    {
        this->m_file.write( line->c_str(), line->length() );
        if( line != ( this->m_lines.end() - 1 ) )
        {
            this->m_file.put( ',' );
        }
        this->m_file.put( '\n' );
    }
    this->m_file.put( ']' );
}
