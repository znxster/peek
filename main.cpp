/* Peek, $Revision: 1.10 $, $Date: 2007/09/30 00:35:45 $
 *
 * This is a simple bit of code to allow the user to quickly view multiple
 * types of compressed files from only one command! It's like a pocket
 * calculator revolution!
 * 
 * Copyright (C) 2007 Mark Sangster <znxster@gmail.com>
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
 * $Id: main.cpp,v 1.10 2007/09/30 00:35:45 mark Exp $
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "peek.hpp"
using namespace std;

#ifndef HAS_CLEARENV
extern char **environ;
#endif

#define PEEK_VERSION "$Revision: 1.10 $"
#define RELEASE_DATE "$Date: 2007/09/30 00:35:45 $"

// Setup static strings for information {{{
static const string SupportedTypes = ("\
Currently supports, tgz, gz, tbz2, bz2, rar, tar, 7z, zip, zoo, arj,\n\
ace, Z and tar.Z files.\n");

static const string Notice = ("\
Peek comes with ABSOLUTELY NO WARRANTY; for details type `peek -vv'.\n\
Peek is free software, and you are welcome to redistribute it\n\
under certain conditions; type `peek -vv' for details.\n");

static const string Copyright = ("\
Copyright (c) 2007 Mark Sangster <znxster@gmail.com>\n");

static const string Licence = ("\
    This program is free software; you can redistribute it and/or modify\n\
    it under the terms of the GNU General Public License as published by\n\
    the Free Software Foundation; either version 2 of the License, or\n\
    (at your option) any later version.\n\
\n\
    This program is distributed in the hope that it will be useful,\n\
    but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n\
    GNU General Public License for more details.\n");

static const string Obtaining = ("\
    You should have received a copy of the GNU General Public License\n\
    along with this program; if not, write to the Free Software\n\
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,\n\
    USA.\n\
");

static const string ReachingUs = ("\
To contact the developer, please mail to <znxster@gmail.com>.\n");
/* To report a bug, please visit http://bugs.kutzooi.co.uk/. */
// }}}

// peek_version() {{{
static void peek_version(void) {
    string tmp = PEEK_VERSION, pmt = RELEASE_DATE;
    cout
        << "Peek " << tmp.substr(11,tmp.length()-13)
        << " (" << pmt.substr(7,pmt.length()-18) << ")" << endl
        << Copyright
        << Notice
        << endl;
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
	eTERM = getenv("TERM");
    eHOME = getenv("HOME");
	eTZ = getenv("TZ");
    if(ePAGER==NULL)
        ePAGER = "more";
    peek->pager = ePAGER;
#ifdef HAS_CLEARENV
    clearenv();
#else
    environ = NULL;
#endif
    setenv("PATH","/bin:/usr/bin:/usr/local/bin:/opt/bin",0);
    setenv("IFS","\t\n",0);
    setenv("PAGER",ePAGER,0);
    setenv("TERM",eTERM,0);
    setenv("HOME",eHOME,0);
	setenv("TZ",eTZ,0);
    
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
                << Copyright << endl
                << Licence << endl
                << Obtaining << endl
                << ReachingUs
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
            cerr << "peek: File " << argv[i] << " doesn't exist" << endl;
            exist.clear(ios::failbit);
        } else {
            peek->File(argv[i]);
            peek->Show();
            cout << endl;
        }
    }
    return 0;
}
// }}}

// vim:set fdm=marker ft=cpp:
