/* peek.cpp, $Revision: $, $Date: $
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
#include "peek.hpp"
#include "config.h"
using namespace std;

// findTar() {{{
#ifdef TAR
bool Peek::findTar() {
    int tmp = this->fname.find_last_of(".",this->flo-1);
    if(this->fname.substr(tmp+1,3) == "tar")
        return true;
    else
        return false;
}
#endif
// }}}

// Arj() {{{
#ifdef ARJ
void Peek::Arj() {
    this->command = ARJ " l "+this->fname;
    return;
}
#endif
// }}}

// Ace() {{{
#ifdef UNACE
void Peek::Ace() {
    this->command = UNACE " l "+this->fname;
    return;
}
#endif
// }}}

// Compress() {{{
#ifdef COMPRESS
void Peek::Compress() {
    this->command = "compress -d -c "+this->fname;
    return;
}
#endif
// }}}

// TarCompress() {{{
#if defined(TAR) && defined(COMPRESS)
void Peek::TarCompress() {
    this->Compress();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
}
#endif
// }}}

// Gz() {{{
#ifdef GUNZIP
void Peek::Gz() {
    this->command = "gunzip < "+this->fname;
    return;
}
#endif
// }}}

// Bz2() {{{
#ifdef BUNZIPTWO
void Peek::Bz2() {
    this->command = BUNZIPTWO " < "+this->fname;
    return;
}
#endif
// }}}

// TarGz() {{{
#if defined(TAR) && defined(GUNZIP)
void Peek::TarGz() {
    this->Gz();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
    return;
}
#endif
// }}}

// TarBz2() {{{
#if defined(TAR) && defined(BUNZIPTWO)
void Peek::TarBz2() {
    this->Bz2();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
    return;
}
#endif
// }}}

// Rar() {{{
#ifdef RAR
void Peek::Rar() {
    this->command = "rar l "+this->fname;
    return;
}
#endif
// }}}

// P7Zip() {{{
#ifdef SEVENZ
void Peek::P7Zip() {
    this->command = "7z l "+this->fname;
    return;
}
#endif
// }}}

// Zip() {{{
#ifdef UNZIP
void Peek::Zip() {
    this->command = UNZIP " -l "+this->fname;
    return;
}
#endif
// }}}

// Zoo() {{{
#ifdef ZOO
void Peek::Zoo() {
    this->command = "zoo -list "+this->fname;
    return;
}
#endif
// }}}

// Tar() {{{
#ifdef TAR
void Peek::Tar() {
    if(this->command != "")
        this->command = this->command+"tar -tvf -";
    else
        this->command = "tar -tvf "+this->fname;
    return;
}
#endif
// }}}

// Constructor {{{
Peek::Peek() {
    this->setPager(false);
    fexts["gz"]   = FILE_GZ;
    fexts["bz2"]  = FILE_BZ2;
    fexts["tgz"]  = FILE_TGZ;
    fexts["tbz2"] = FILE_TBZ2;
    fexts["rar"]  = FILE_RAR;
    fexts["tar"]  = FILE_TAR;
    fexts["7z"]   = FILE_P7ZIP;
    fexts["zip"]  = FILE_ZIP;
    fexts["zoo"]  = FILE_ZOO;
    fexts["arj"]  = FILE_ARJ;
    fexts["ace"]  = FILE_ACE;
    fexts["Z"]    = FILE_COMP;
}
// }}}

// File() {{{
void Peek::File(string file) {
    this->fname = file;
    this->flo = file.find_last_of(".");
    this->fext = file.substr(this->flo+1);
    this->command = "";
}
// }}}

// setPager() {{{
void Peek::setPager(bool state) {
    this->usePager = state;
}
// }}}

// Show() {{{
void Peek::Show() {
    switch(fexts[this->fext]) {
#ifdef TAR
        case FILE_TAR:
            this->Tar();
            break;
#endif
#if defined(TAR) && defined(GUNZIP)
        case FILE_TGZ:
            this->TarGz();
            break;
#endif
#if defined(TAR) && defined(BUNZIPTWO)
        case FILE_TBZ2:
            this->TarBz2();
            break;
#endif
#if defined(TAR) && defined(COMPRESS)
        case FILE_TCOMP:
            this->TarCompress();
            break;
#endif
#ifdef BUNZIPTWO
        case FILE_BZ2:
            cout << "got here" << endl;
            this->Bz2();
            break;
#endif
#ifdef GUNZIP
        case FILE_GZ:
            this->Gz();
            break;
#endif
#ifdef RAR
        case FILE_RAR:
            this->Rar();
            break;
#endif
#ifdef SEVENZ
        case FILE_P7ZIP:
            this->P7Zip();
            break;
#endif
#ifdef UNZIP
        case FILE_ZIP:
            this->Zip();
            break;
#endif
#ifdef ZOO
        case FILE_ZOO:
            this->Zoo();
            break;
#endif
#ifdef ARJ
        case FILE_ARJ:
            this->Arj();
            break;
#endif
#ifdef ACE
        case FILE_ACE:
            this->Ace();
            break;
#endif
#ifdef COMPRESS
        case FILE_COMP:
            this->Compress();
            break;
#endif
        default:
            cerr << "peek: Unknown file type: " << this->fname << endl;
            exit(1);
            break;
    }
    
    if(this->usePager)
        this->command += "| "+this->pager;
    system(this->command.c_str());
}
// }}}

/* vim:set fdm=marker ft=cpp: */
