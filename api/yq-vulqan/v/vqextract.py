#!/usr/bin/python

################################################################################
##
##  YOUR QUILL
##
################################################################################

#   Run this script to auto-import vulkan structures to the nicer auto-stype format

import os, sys

DONT    = ['KHR', 'NV', 'EXT', 'QCOM', 'MSFT', 'LUNARG', 'AMD', 'INTEL' ]


OPT_STRUCTS = False
OPT_ENUMS   = True

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
    def __init__(self, name):
        self.name   = name
        self.sname  = stripStrip(name)
        self.map    = dict()
        self.args   = []
        self.isflag = self.sname.endswith('FlagBits')
        caps = toCapitalizedBits(self.sname)
        if self.isflag:
            self.lead   = '_'.join(caps[0:-2]) + '_'
        else:
            self.lead   = '_'.join(caps) + '_'
        self.cxx    = toCapitalizedString(caps[1:])

    def filter(self, sv):
        if sv.startswith(self.lead):
            sv  = sv[len(self.lead):]
        #return sv
        bits = underscoredToCapitalizedBits(sv);
        return ''.join(bits)

    def add(self, line):
        b   = l.split('=')
        if len(b) != 2:
            return
        k   = b[0].strip()
        if 'MAX_ENUM' in k:
            return
        k   = self.filter(k)

        v   = b[1].strip()
        if v.endswith(','):
            v   = v[:-1]
        v   = self.filter(v)
        self.args.append([k,v])
        
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
                print("enumeration %s detected (%s)" % (enums[-1].name, enums[-1].lead))
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

structs.sort(key=skey)

written = []

if OPT_STRUCTS:
    with open('VqStructs.hpp', 'w') as f:
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


with open('VqEnumerations.hpp', 'w') as f:
    f.write("""/// ENUMERATIONS
//  WARNING.... file not yet trusted....
#pragma once

namespace yq::tachyon {""")
    for e in enums:
        args    = dict()
        args['cxx'] = e.cxx
    
        f.write("""
    YQ_ENUM(Vq%(cxx)s, ,
""" % args)

        i   = 0

        for kv in e.args:
            if i != 0:
                f.write(',\n')
            else:
                i   = 1
            f.write("        %s = %s" % (kv[0],kv[1]))
            
        f.write("""
    )
""" % args)

    f.write("""
}
""")
