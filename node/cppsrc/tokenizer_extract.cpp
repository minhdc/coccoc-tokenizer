/*#include <stdio.h>
#include  <getopt.h>
#include <string>
#include "../../tokenizer/tokenizer.hpp"
//#include "../../tokenizer/config.h"
//#include <tokenizer/tokenizer.hpp>
//#include <tokenizer/config.h>

#define FORMAT_TSV 0
#define FORMAT_ORIGINAL 1
#define FORMAT_VERBOSE 2

using namespace std;

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

int main (int argc, char** argv){
    tokenizer_option opts;
    auto process = [&opts](const std::string &text)
	{
		std::vector< FullToken > res = opts.format != FORMAT_ORIGINAL ?
			Tokenizer::instance().segment(text, false, opts.tokenize_option) :
			Tokenizer::instance().segment_original(text, opts.tokenize_option);

		if (opts.format == FORMAT_ORIGINAL)
		{
			size_t i = 0;

			for (/* void *//*; i < res.size(); ++i)
			{
				size_t punct_start = (i > 0) ? res[i - 1].original_end : 0;
				size_t punct_len = res[i].original_start - punct_start;

				if (punct_len > 0)
				{
					std::cout << text.substr(punct_start, punct_len);
				} else if (i > 0) {
					std::cout << ' '; // avoid having tokens sticked together
				}

				std::cout << res[i].text;
			}

			size_t punct_start = (i > 0) ? res[i - 1].original_end : 0;
			size_t punct_len = text.size() - punct_start;

			if (punct_len > 0)
			{
				std::cout << text.substr(punct_start, punct_len);
			}
		}
		else
		{
			for (size_t i = 0; i < res.size(); ++i)
			{
				if (i > 0)
				{
					std::cout << '\t';
				}

				std::cout << ((opts.format == FORMAT_VERBOSE) ? res[i].to_string() : res[i].text);
			}
		}

		std::cout << std::endl;
	};

	for (int i = optind; i < argc; ++i)
	{
		process(argv[i]);
	}

	if (optind == argc)
	{
		std::string line;
		while (std::getline(std::cin, line))
		{
			process(line);
		}
	}

	return 0;
}*/