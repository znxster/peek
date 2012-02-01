/* peek.hpp, $Revision: $, $Date: $
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

#ifndef _PEEK_HH
#define _PEEK_HH 1

#include <map>
#include <string>
#include "config.h"
using namespace std;

enum Type {
    UNK,
        FILE_TGZ, FILE_GZ, FILE_TBZ2, FILE_BZ2, FILE_RAR, FILE_TAR, FILE_P7ZIP,
        FILE_ZIP, FILE_ZOO, FILE_ARJ, FILE_ACE, FILE_TCOMP, FILE_COMP, FILE_CPIO,
        FILE_AR, FILE_LZO, FILE_LHA, FILE_XAR, FILE_SHAR, FILE_ZZIP, FILE_RZIP
};

static map<string, Type> fexts;

class Peek {
private:
    string fname, fext;
    int len;
    size_t flo;
    Type type;
    string command;
    bool usePager;
    
    void Process(void);
#ifdef TAR
    bool findTar(void);
#endif
#ifdef RZIP
    void Rzip(void);
#endif
#ifdef ZZIP
    void Zzip(void);
#endif
#ifdef AR
    void Ar(void);
#endif
#ifdef CPIO
    void Cpio(void);
#endif
#ifdef LZOP
    void Lzop(void);
#endif
#ifdef ARJ
    void Arj(void);
#endif
#ifdef UNACE
    void Ace(void);
#endif
#ifdef COMPRESS
    void Compress(void);
    void TarCompress(void);
#endif
#ifdef GUNZIP
    void Gz(void);
    void TarGz(void);
#endif
#ifdef BUNZIPTWO
    void Bz2(void);
    void TarBz2(void);
#endif
#ifdef RAR
    void Rar(void);
#endif
#ifdef SEVENZ
    void P7Zip(void);
#endif
#ifdef UNZIP
    void Zip(void);
#endif
#ifdef TAR
    void Tar(void);
#endif
#ifdef LHA
    void Lha(void);
#endif
#ifdef XAR
    void Xar(void);
#endif
#ifdef SHAR
    void Shar(void);
#endif
#ifdef ZOO
    void Zoo(void);
#endif
    
public:
    string pager;
    
    Peek(void);
    
    void File(string);
    void setPager(bool);
    void Show(void);
};

#endif /* peek.hpp */
// vim:set fdm=marker ft=cpp:
