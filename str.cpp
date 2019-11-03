#include "str.h"
#include <cctype>
#include <algorithm>
#include <sstream>

std::vector<std::string> StrSplit( std::string str, char splitBy, bool fixType )
{
    std::vector<std::string> ret;
    std::string part;
    std::istringstream stream( str );
    while( std::getline( stream, part, splitBy ) )
    {
        ret.push_back( fixType ? StrFixType( part ) : part );
    }
    return ret;
}

#define CHECK_SPACE []( int ch )->bool { return ( ch < 0 ) || ( ch > 255 ) || !std::isspace( ch ); }
std::string StrFixType( std::string str )
{
    str.erase( str.begin(), std::find_if( str.begin(), str.end(), CHECK_SPACE ) );
    str.erase( std::find_if( str.rbegin(), str.rend(), CHECK_SPACE ).base() );
    for( char ch : str )
    {
        if( ( ( ch >= '0' ) && ( ch <= '9' ) ) || ( ch == '-' ) )
        {
            continue;
        }
        std::string s = "\"";
        s += str;
        s += "\"";
        return s;
    }
    return str;
}

std::string StrJoin( std::vector<std::string>elements, std::string joinBy )
{
    std::string ret;
    for( auto item = elements.begin(); item < elements.end(); item++ )
    {
        ret += *item;
        if( item != (elements.end() - 1) )
        {
            ret += joinBy;
        }
    }
    return ret;
}
