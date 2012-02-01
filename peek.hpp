/* peek.hpp, $Revision: 1.5 $, $Date: 2007/09/30 00:35:45 $
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
 * $Id: peek.hpp,v 1.5 2007/09/30 00:35:45 mark Exp $
 */

#ifndef _PEEK_HH
#define _PEEK_HH 1

#include <string>
using namespace std;

enum Type {
    TGZ,GZ,TBZ2,BZ2,RAR,TAR,P7ZIP,ZIP,ZOO,ARJ,ACE,
    TCOMP,COMP,
    UNK
};

class Peek {
private:
    string fname, fext;
    int len;
    size_t flo;
    Type type;
    string command;
    bool usePager;
    
    void Process(void);
    bool findTar(void);
    bool checkTool(string);
    
    void Arj(void);
    void Ace(void);
    void Compress(void);
    void TarCompress(void);
    void Gz(void);
    void Bz2(void);
    void TarGz(void);
    void TarBz2(void);
    void Rar(void);
    void P7Zip(void);
    void Zip(void);
    void Tar(void);
    void Zoo(void);
    
public:
    string pager;
    
    Peek(void);
    
    void File(string);
    void setPager(bool);
    void Show(void);
};

#endif /* peek.hpp */
// vim:set fdm=marker ft=cpp:
