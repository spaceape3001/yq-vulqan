#!/usr/bin/python

################################################################################
##
##  YOUR QUILL
##
################################################################################

#   Run this script to auto-import vulkan structures to the nicer auto-stype format

import os, sys

DONT    = ['KHR', 'NV', 'EXT', 'QCOM', 'MSFT', 'LUNARG', 'AMD', 'INTEL' ]

OPT_STRUCTS = None # 'VqStructs'
OPT_ENUMS   = None # 'VqEnumerations'

def underscoredToCapitalizedBits(this):
    c   = []
    for s in this.split('_'):
        if s not in DONT:
            c.append(s.capitalize())
        else:
            c.append(s)
    return c


def toCapitalizedBits(this):
    r   = []
    for c in this:
        if c.isupper():
            r.append('')
        if len(r) == 0:
            continue
        r[-1] += c.upper()
    return r
    
def toCapitalizedString(this):
    r   = []
    for s in this:
        if s not in DONT:
            r.append(s.capitalize())
        else:
            r.append(s)
    return ''.join(r)
    
def stripStrip(this):
    for s in DONT:
        if this.endswith(s):
            this = this[0:-len(s)]
    return this

class Enum:
    KEYS = []
    def __init__(self, name):
        self.name   = name.replace('KHR','').replace('QCOM','').replace('NV','')
        self.sname  = stripStrip(name)
        self.map    = dict()
        self.args   = []
        self.isflag = self.sname.endswith('FlagBits')
        
        caps = toCapitalizedBits(self.sname)
        if self.isflag:
            self.root    = toCapitalizedString(caps[1:-2])
            self.lead   = '_'.join(caps[0:-2]) + '_'
            self.cxx    = self.root + 'Bit'
            self.flag   = self.root + 'Flags'
            self.base   = 'uint8_t'
        else:
            self.lead   = '_'.join(caps) + '_'
            self.root   = toCapitalizedString(caps[1:])
            self.cxx    = self.root
            self.flag   = None
            self.base   = 'int32_t'
            
        self.map['cxx']     = self.cxx
        self.map['flag']    = self.flag
        self.map['lead']    = self.lead
        self.map['base']    = self.base
        self.keys           = []
        self.values         = []
        self.dupe           = self.cxx in Enum.KEYS
        Enum.KEYS.append(self.cxx)

    def filter(self, sv):
        if sv.startswith(self.lead):
            sv  = sv[len(self.lead):]
        #return sv
        bits = underscoredToCapitalizedBits(sv);
        ret = ''.join(bits).replace('KHR','').replace('QCOM','').replace('NV','').replace('EXT','').removeprefix('Vk')
        if self.isflag:
            ret = ret.removesuffix('Bit').removesuffix('FlagSet')
        return ret

    def add(self, line):
        b   = l.split('=')
        if len(b) != 2:
            return
        k   = b[0].strip()
        if 'MAX_ENUM' in k:
            return
        k   = self.filter(k)
        if k[0].isdigit():
            k   = '_' + k
        if k in self.keys:
            return
        if self.isflag and (k == 'None'):
            return
        
        ev  = dict()
        ev['key']   = k
        v   = b[1].strip()
        if v.endswith(','):
            v   = v[:-1]
        if self.isflag and v.startswith('0x'):
            v = str(int(v,16).bit_length())
        else:
            v = self.filter(v)
        ev['value'] = v

        ev['dupe']  = v in self.values

        self.keys.append(k)
        self.values.append(k)
        self.values.append(v)
        self.args.append(ev)
        
class Struct:
    def __init__(self, name):
        self.name   = name

class Vulkan:
    mNone   = 0
    mStruct = 1
    mEnum   = 2



snames  = []
stypes  = []
enums   = []

with open('/usr/include/vulkan/vulkan_core.h') as f:
    mode    = Vulkan.mNone
    for l in f.readlines():
        l   = l.strip()
        if l == '':
            continue
        if l.startswith('typedef struct '):
            b   = l.split(' ');
            snames.append(Struct(b[2]))
        if l.startswith('typedef enum '):
            b   = l.split(' ');
            if b[2] != 'VkStructureType':
                enums.append(Enum(b[2]))
                mode    = Vulkan.mEnum
                #print("enumeration %s detected (%s)" % (enums[-1].name, enums[-1].lead))
        if l[0] == '}':
            mode    = Vulkan.mNone
        if (mode == Vulkan.mEnum) and ('=' in l):
            enums[-1].add(l)

structs = []
            
for e in stypes:
    c   = underscoredToCapitalizedBits(e)
    k   = ''.join(c[3:])
    vk  = 'Vk' + k
    vq  = 'Vq' + k
    if vk not in snames:
        continue
    
    st  = dict()
    st['enum']  = e
    st['vk']    = vk
    st['vq']    = vq
    structs.append(st)
    
def skey(s):
    return s['vk']
def ekey(e):
    return e.sname

structs.sort(key=skey)
enums.sort(key=ekey)

written = []

if OPT_STRUCTS is not None:
    with open('%s.hpp' % OPT_STRUCTS, 'w') as f:
        f.write("""////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include <vulkan/vulkan_core.h>

namespace yq::tachyon {""")


        for s in structs:
            if s['vk'] in written:
                continue;
            written.append(s['vk'])
            f.write("""
    struct %(vq)s : public %(vk)s {
        %(vq)s() : %(vk)s{} 
        {
            sType   = %(enum)s;
        }
    };
""" % s)

        f.write("""
}
""")

if OPT_ENUMS is not None:
    with open('%s.hpp' % OPT_ENUMS, 'w') as f:
        written = []
        f.write("""////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include <string_view>
#include <yq-toolbox/basic/Flags.hpp>

namespace yq::tachyon {""")
        for e in enums:
        
            if e.dupe:
                continue
    
            f.write("""
    enum class Vq%(cxx)s : %(base)s {
""" % e.map)

            i   = 0

            for kv in e.args:
                if i != 0:
                    f.write(',\n')
                else:
                    i   = 1
                f.write("        %(key)s = %(value)s" % kv)
            
            f.write("""
    };
""" % e.map)

        f.write('\n')
        
        for e in enums:
            if e.isflag:
                f.write("""
    using Vq%(flag)s = Flags<Vq%(cxx)s>;""" % e.map)

        f.write('\n')

        for e in enums:
            if e.dupe:
                continue

            f.write("""
    std::string_view    to_string_view(Vq%(cxx)s);""" % e.map)
        f.write("""
}
""")

    with open('%s.cpp' % OPT_ENUMS, 'w') as f:
        f.write("""////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include "VqEnumerations.hpp"

namespace yq::tachyon {

    static const std::string_view szUnknown   = "(unknown)";
""");

        for e in enums:
            if e.dupe:
                continue
    
            f.write("""
    std::string_view    to_string_view(Vq%(cxx)s v)
    {
        switch(v){""" % e.map)

            for kv in e.args:
                if kv['dupe']:
                    continue
                f.write("""
        case Vq%(cxx)s::%(key)s:
            return "%(key)s";""" % (e.map | kv));
        
            f.write("""
        default:
            return szUnknown;
        }
    }
""")        


        f.write("""
}
""");
