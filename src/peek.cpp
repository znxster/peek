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
#include <cstdlib>
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

// Zzip() {{{
#ifdef ZZIP
void Peek::Zzip() {
	this->command = ZZIP " l "+this->fname;
	return;
}
#endif
// }}}

// Rzip() {{{
#ifdef RZIP
void Peek::Rzip() {
  this->command = RZIP " -d "+this->fname;
  return;
}
#endif
// }}}

// Ar() {{{
#ifdef AR
void Peek::Ar() {
	this->command = AR " t "+this->fname;
	return;
}
#endif
// }}}

// Lzop() {{{
#ifdef LZOP
void Peek::Lzop() {
	// XXX: Yes lzop is this stupid
	this->command = LZOP " -dc "+this->fname+" | cat";
	return;
}
#endif
// }}}

// Cpio() {{{
#ifdef CPIO
void Peek::Cpio() {
	this->command = CPIO " -tv <"+this->fname;
	return;
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
    this->command = COMPRESS " -d -c "+this->fname;
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
    this->command = GUNZIP " < "+this->fname;
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
    this->command = RAR " l "+this->fname;
    return;
}
#endif
// }}}

// P7Zip() {{{
#ifdef SEVENZ
void Peek::P7Zip() {
    this->command = SEVENZ " l "+this->fname;
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

// Lha() {{{
#ifdef LHA
void Peek::Lha() {
	this->command = LHA " l "+this->fname;
	return;
}
#endif
// }}}

// Xar() {{{
#ifdef XAR
void Peek::Xar() {
	this->command = XAR " -tf "+this->fname;
	return;
}
#endif
// }}}

// Shar() {{{
#ifdef SHAR
void Peek::Shar() {
	// XXX: Is this particular to GNU shar ?
	this->command = "grep '^# ===' "+this->fname+" | sed 's/.*= \\(.*\\) =.*/\\1/'";
	return;
}
#endif
// }}}

// Zoo() {{{
#ifdef ZOO
void Peek::Zoo() {
    this->command = ZOO " -list "+this->fname;
    return;
}
#endif
// }}}

// Tar() {{{
#ifdef TAR
void Peek::Tar() {
    if(this->command != "")
        this->command = this->command+ TAR " -tvf -";
    else
        this->command = TAR " -tvf "+this->fname;
    return;
}
#endif
// }}}

// Constructor {{{
Peek::Peek() {
  this->setPager(false);
  fexts["cpio"] = FILE_CPIO;
  fexts["a"]    = FILE_AR;
  fexts["ar"]   = FILE_AR;
  fexts["gz"]   = FILE_GZ;
  fexts["bz2"]  = FILE_BZ2;
  fexts["tgz"]  = FILE_TGZ;
  fexts["tbz2"] = FILE_TBZ2;
  fexts["rar"]  = FILE_RAR;
  fexts["tar"]  = FILE_TAR;
  fexts["7z"]   = FILE_P7ZIP;
  fexts["zip"]  = FILE_ZIP;
  fexts["zoo"]  = FILE_ZOO;
  fexts["lha"]  = FILE_LHA;
  fexts["lzh"]  = FILE_LHA;
  fexts["xar"]  = FILE_XAR;
  fexts["shar"] = FILE_SHAR;
  fexts["arj"]  = FILE_ARJ;
  fexts["lzo"]  = FILE_LZO;
  fexts["ace"]  = FILE_ACE;
  fexts["Z"]    = FILE_COMP;
  fexts["zz"]   = FILE_ZZIP;
  fexts["rz"]   = FILE_RZIP;
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
        case FILE_TAR:
#ifdef TAR
            this->Tar();
#else
			cerr << "peek: Please install 'tar' and rebuild to support" << endl;
#endif
            break;
        case FILE_TGZ:
#if defined(TAR) && defined(GUNZIP)
            this->TarGz();
#else
			cerr << "peek: Please install 'tar' and 'gunzip' and rebuild to support" << endl;
#endif
            break;
        case FILE_TBZ2:
#if defined(TAR) && defined(BUNZIPTWO)
            this->TarBz2();
#else
			cerr << "peek: Please install 'tar' and 'bunzip2' and rebuild to support" << endl;
#endif
            break;
        case FILE_TCOMP:
#if defined(TAR) && defined(COMPRESS)
            this->TarCompress();
#else
			cerr << "peek: Please install 'tar' and 'compress' and rebuild to support" << endl;
#endif
            break;
        case FILE_BZ2:
#ifdef BUNZIPTWO
            this->Bz2();
#else
			cerr << "peek: Please install 'bunzip2' and rebuild to support" << endl;
#endif
            break;
        case FILE_GZ:
#ifdef GUNZIP
            this->Gz();
#else
			cerr << "peek: Please install 'gunzip' and rebuild to support" << endl;
#endif
            break;
        case FILE_RAR:
#ifdef RAR
            this->Rar();
#else
			cerr << "peek: Please install 'rar' and rebuild to support" << endl;
#endif
            break;
        case FILE_P7ZIP:
#ifdef SEVENZ
            this->P7Zip();
#else
			cerr << "peek: Please install '7z' or '7za' and rebuild to support" << endl;
#endif
            break;
        case FILE_ZIP:
#ifdef UNZIP
            this->Zip();
#else
			cerr << "peek: Please install 'unzip' and rebuild to support" << endl;
#endif
            break;
		case FILE_LHA:
#ifdef LHA
			this->Lha();
#else
			cerr << "peek: Please install 'lha' and rebuild to support" << endl;
#endif
			break;
		case FILE_XAR:
#ifdef XAR
			this->Xar();
#else
			cerr << "peek: Please install 'xar' and rebuild to support" << endl;
#endif
			break;
		case FILE_SHAR:
#ifdef SHAR
			this->Shar();
#else
			cerr << "peek: Please install 'shar' and rebuild to support" << endl;
#endif
			break;
        case FILE_ZOO:
#ifdef ZOO
            this->Zoo();
#else
			cerr << "peek: Please install 'zoo' and rebuild to support" << endl;
#endif
            break;
		case FILE_AR:
#ifdef AR
			this->Ar();
#else
			cerr << "peek: Please install 'ar' and rebuild to support" << endl;
#endif
			break;
    case FILE_RZIP:
#ifdef RZIP
      this->Rzip();
#else
      cerr << "peek: Please install 'rzip' and rebuild to support" << endl;
#endif
      break;
		case FILE_ZZIP:
#ifdef ZZIP
			this->Zzip();
#else
			cerr << "peek: Please install 'zzip' or 'zzip.exe' and rebuild to support" << endl;
#endif
			break;
		case FILE_CPIO:
#ifdef CPIO
			this->Cpio();
#else
			cerr << "peek: Please install 'cpio' and rebuild to support" << endl;
#endif
			break;
		case FILE_LZO:
#ifdef LZOP
			this->Lzop();
#else
			cerr << "peek: Please install 'lzop' and rebuild to support" << endl;
#endif
			break;
        case FILE_ARJ:
#ifdef ARJ
            this->Arj();
#else
			cerr << "peek: Please install 'arj' and rebuild to support" << endl;
#endif
            break;
        case FILE_ACE:
#ifdef ACE
            this->Ace();
#else
			cerr << "peek: Please install 'unace' and rebuild to support" << endl;
#endif
            break;
        case FILE_COMP:
#ifdef COMPRESS
            this->Compress();
#else
			cerr << "peek: Please install 'compress' and rebuild to support" << endl;
#endif
            break;
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
