/* peek.cpp, $Revision: 1.5 $, $Date: 2007/09/30 00:35:45 $
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
 * $Id: peek.cpp,v 1.5 2007/09/30 00:35:45 mark Exp $
 */

#include <iostream>
#include "peek.hpp"
using namespace std;

// Process() {{{
void Peek::Process() {
    if(this->fext == "tgz")
        this->type = TGZ;
    else if(this->fext == "gz")
        if(this->findTar())
            this->type = TGZ;
        else
            this->type = GZ;
    else if(this->fext == "tbz2")
        this->type = TBZ2;
    else if(this->fext == "bz2")
        if(this->findTar())
            this->type = TBZ2;
        else
            this->type = BZ2;
    else if(this->fext == "rar")
        this->type = RAR;
    else if(this->fext == "tar")
        this->type = TAR;
    else if(this->fext == "7z")
        this->type = P7ZIP;
    else if(this->fext == "zip")
        this->type = ZIP;
    else if(this->fext == "zoo")
        this->type = ZOO;
    else if(this->fext == "arj")
        this->type = ARJ;
    else if(this->fext == "ace")
        this->type = ACE;
    else if(this->fext == "Z")
        if(this->findTar())
            this->type = TCOMP;
        else
            this->type = COMP;
    else
        this->type = UNK;
}
// }}}

// findTar() {{{
bool Peek::findTar() {
    int tmp = this->fname.find_last_of(".",this->flo-1);
    if(this->fname.substr(tmp+1,3) == "tar")
        return true;
    else
        return false;
}
// }}}

// Arj() {{{
void Peek::Arj() {
    if(this->checkTool("arj"))
        this->command = "arj l "+this->fname;
    return;
}
// }}}

// Ace() {{{
void Peek::Ace() {
    if(this->checkTool("unace"))
        this->command = "unace l "+this->fname;
    return;
}
// }}}

// Compress() {{{
void Peek::Compress() {
	// note if run without -h it expects stdin
    if(this->checkTool("compress -h"))
        this->command = "compress -d -c "+this->fname;
    return;
}
// }}}

// TarCompress() {{{
void Peek::TarCompress() {
    this->Compress();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
}
// }}}

// Gz() {{{
void Peek::Gz() {
    if(this->checkTool("gunzip"))
        this->command = "gunzip < "+this->fname;
    return;
}
// }}}

// Bz2() {{{
void Peek::Bz2() {
    if(this->checkTool("bunzip2"))
        this->command = "bunzip2 < "+this->fname;
    return;
}
// }}}

// TarGz() {{{
void Peek::TarGz() {
    this->Gz();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
    return;
}
// }}}

// TarBz2() {{{
void Peek::TarBz2() {
    this->Bz2();
    this->fname = this->fname.substr(0,this->fname.find_last_of("."));
    this->command = this->command+" | ";
    this->Tar();
    return;
}
// }}}

// Rar() {{{
void Peek::Rar() {
    if(this->checkTool("rar"))
        this->command = "rar l "+this->fname;
    return;
}
// }}}

// P7Zip() {{{
void Peek::P7Zip() {
    if(this->checkTool("7z"))
        this->command = "7z l "+this->fname;
    return;
}
// }}}

// Zip() {{{
void Peek::Zip() {
    if(this->checkTool("unzip"))
        this->command = "unzip -l "+this->fname;
    return;
}
// }}}

// Zoo() {{{
void Peek::Zoo() {
    if(this->checkTool("zoo"))
        this->command = "zoo -list "+this->fname;
    return;
}
// }}}

// Tar() {{{
void Peek::Tar() {
    if(this->checkTool("tar"))
        if(this->command != "")
            this->command = this->command+"tar -tvf -";
        else
            this->command = "tar -tvf "+this->fname;
    return;
}
// }}}

// checkTool() {{{
bool Peek::checkTool(string tool) {
	string test = tool;
    test += " >/dev/null 2>&1";
    short rs = system(test.c_str());
    if(WEXITSTATUS(rs) == 127) {
        cerr << "peek: '"
            << tool
            << "' is unavailable, please install and try again."
            << endl;
        exit(1);
    }
    return true;
}
// }}}

// Constructor {{{
Peek::Peek() {
    this->setPager(false);
}
// }}}

// File() {{{
void Peek::File(string file) {
    this->fname = file;
    this->flo = file.find_last_of(".");
    this->fext = file.substr(this->flo+1);
    this->command = "";
    this->Process();
}
// }}}

// setPager() {{{
void Peek::setPager(bool state) {
    this->usePager = state;
}
// }}}

// Show() {{{
void Peek::Show() {
    switch(this->type) {
        case TGZ:
            this->TarGz();
            break;
        case GZ:
            this->Gz();
            break;
        case TBZ2:
            this->TarBz2();
            break;
        case BZ2:
            this->Bz2();
            break;
        case RAR:
            this->Rar();
            break;
        case TAR:
            this->Tar();
            break;
        case P7ZIP:
            this->P7Zip();
            break;
        case ZIP:
            this->Zip();
            break;
        case ZOO:
            this->Zoo();
            break;
        case ARJ:
            this->Arj();
            break;
        case ACE:
            this->Ace();
            break;
        case TCOMP:
            this->TarCompress();
            break;
        case COMP:
            this->Compress();
            break;
        case UNK:
        default:
            cerr << "peek: Unknown file type: " << this->fname;
            return;
            break;
    }
    
    if(this->usePager)
        this->command += "| "+this->pager;
    system(this->command.c_str());
}
// }}}

// vim:set fdm=marker ft=cpp:
