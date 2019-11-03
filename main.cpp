#include <iostream>
#include "csv.h"
#include "json.h"

int main( int argc, char* argv[] )
{
    if( argc < 2 )
    {
        std::cout << "Usage: csv2json csv_file_path [json_file_path]" << std::endl;
        return 1;
    }

    CSV csv( argv[ 1 ] );
    if( !csv.valid() )
    {
        std::cout << "Input file [" << argv[ 1 ] << "] not found" << std::endl;
        return 2;
    }

    JSON json( ( argc > 2 ) ? argv[ 2 ] : csv.MakeJsonPath() );
    if( !json.valid() )
    {
        std::cout << "Output file [" << json.GetFilePath() << "] cannot be writen" << std::endl;
        return 3;
    }

    json.SetColumns( csv.GetColumns() );
    std::vector<std::string> line;
    while( csv.GetLine( line ) )
    {
        json.Append( line );
    }
    json.Write();
    return 0;
}
