/* Peek, $Revision:$, $Date:$
 *
 * This is a simple bit of code to allow the user to quickly view multiple
 * types of compressed files from only one command! It's like a pocket
 * calculator revolution!
 *
 * Copyright (C) 2007-2008 Mark Sangster <znxster@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id: $
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "peek.hpp"
#include "config.h"

using namespace std;

// Setup static strings for information {{{
const string ReleaseDate = "2008/02/10";
const string SupportedTypes = ("\
Currently supports multiple types of compressed files and archives.\n");

static const string Notice = ("\
Peek comes with ABSOLUTELY NO WARRANTY; for details type `peek -vv'.\n\
Peek is free software, and you are welcome to redistribute it\n\
under certain conditions; type `peek -vv' for details.\n");

const string Copyright = "Copyright (c) 2007-2008 Mark Sangster";

static const string Licence = ("\
    This program is free software; you can redistribute it and/or modify\n\
    it under the terms of the GNU General Public License as published by\n\
    the Free Software Foundation; either version 3 of the License, or\n\
    (at your option) any later version.\n\
\n\
    This program is distributed in the hope that it will be useful,\n\
    but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n\
    GNU General Public License for more details.\n");

static const string Obtaining = ("\
    You should have received a copy of the GNU General Public License\n\
    along with this program; if not, see <http://www.gnu.org/licenses/>.\n\
");
// }}}

// peek_version() {{{
static void peek_version(void) {
    cout
        << PACKAGE_NAME
        << " v" << PACKAGE_VERSION
        << " (" << ReleaseDate << ")" << endl
        << Copyright
        << " <" << PACKAGE_BUGREPORT << ">" << endl
        << Notice << endl;
}
// }}}

// peek_usage() {{{
static void peek_usage(void) {
    peek_version();
    cout
        << "usage: peek [-pvh] file..." << endl
        << "options:" << endl
        << "  -p\t\toutput through a pager" << endl
        << "  -v\t\tshow version" << endl
        << "  -h\t\tthis help message" << endl
        << endl
        << SupportedTypes << endl;
    exit(0);
}
// }}}

// main() {{{
int main(int argc, char *argv[]) {
    int i, start = 1, version = 0;
    ifstream exist;
    Peek *peek = new Peek();

    /* extract, cleanse and rebuild environment */
    char *ePAGER, *eTERM, *eHOME, *eTZ;
    ePAGER = getenv("PAGER");
    if(ePAGER==NULL)
        ePAGER = "more";
    peek->pager = ePAGER;
    eTERM = getenv("TERM");
    if(eTERM==NULL)
        eTERM="vt100";
    eHOME = getenv("HOME");
    eTZ = getenv("TZ");
    if(eTZ==NULL)
        eTZ="C";

#ifdef HAS_SETENV
    setenv("PATH","/bin:/usr/bin:/usr/local/bin:/opt/bin",0);
    setenv("IFS","\t\n",0);
    setenv("PAGER",ePAGER,0);
    setenv("TERM",eTERM,0);
    setenv("HOME",eHOME,0);
    setenv("TZ",eTZ,0);
#else
    putenv("IFS=\t\n");
    putenv("PATH=/bin:/usr/bin:/usr/local/bin:/opt/bin");
    char s[20];
    strcpy(s,"PAGER=");
    strcat(s,ePAGER);
    putenv(s);
    strcpy(s,"TERM=");
    strcat(s,eTERM);
    putenv(s);
    strcpy(s,"HOME=");
    strcat(s,eHOME);
    putenv(s);
    strcpy(s,"TZ=");
    strcat(s,eTZ);
    putenv(s);
#endif
    
    /* check we aren't running with privileges */
    if(getegid() != getgid()) {
        cerr << "peek: I don't want privileges!" << endl;
        exit(1);
    }
    
    while((i = getopt(argc, argv, "phv")) != EOF)
        switch(i) {
            case 'v':
                version++;
                break;
            case 'p':
                peek->setPager(true);
                start++;
                break;
            default:
                peek_usage();
        }

    switch(version) {
        case 0:
            break;
        case 1:
            peek_version();
            exit(0);
            break;
        default:
        case 2:
            peek_version();
            cout
                << Copyright
                << " <" << PACKAGE_BUGREPORT << ">" << endl
                << Licence << endl
                << Obtaining << endl
                << "To contact the developer, please mail to <"
                << PACKAGE_BUGREPORT << ">" << endl
                << endl;
            exit(0);
    }

    /* requires at least one file name */
    if(argc < 2) {
        peek_usage();
        exit(1);
    }

    for(i = start; i < argc; i++) {
        exist.open(argv[i], ifstream::in);
        exist.close();
        if(exist.fail()) {
            cerr << "peek: File '" << argv[i] << "' doesn't exist" << endl;
            exit(1);
        } else {
            peek->File(argv[i]);
            peek->Show();
            cout << endl;
        }
    }
    return 0;
}
// }}}

/* vim:set fdm=marker ft=cpp: */
