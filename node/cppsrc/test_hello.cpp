#include <iostream>
#include <getopt.h>
#include "../../tokenizer/tokenizer.hpp"
#include "../../build/auto/tokenizer/config.h"

using namespace std;

#define FORMAT_TSV 1
#define FORMAT_ORIGINAL 1
#define FORMAT_VERBOSE 2

struct tokenizer_option
{
	bool no_sticky;
	int tokenize_option;
	int format;
	const char *dict_path;

	tokenizer_option()
	    : no_sticky(false),
	      tokenize_option(Tokenizer::TOKENIZE_NORMAL),
	      format(FORMAT_TSV),
	      dict_path(DICT_PATH)
	{
	}
};

int main(int argc, char const *argv[])
{
    
    tokenizer_option opts;
    std::string text = "ngày hôm nay đẹp trời vãi";
    
    //init 
	//dict_path, 
	// sticky
    if (0 > Tokenizer::instance().initialize("/usr/local/share/tokenizer/dicts", opts.no_sticky))
    {
        exit(EXIT_FAILURE);
    }
    //use
    std::vector< FullToken > res = Tokenizer::instance().segment(text, false, opts.tokenize_option);

    size_t i = 0;

    for (size_t i = 0; i < res.size(); ++i)
			{
				if (i > 0)
				{
					std::cout << '\t';
				}

				std::cout << ((opts.format == FORMAT_VERBOSE) ? res[i].to_string() : res[i].text);
			}
			

    return 0;
}
