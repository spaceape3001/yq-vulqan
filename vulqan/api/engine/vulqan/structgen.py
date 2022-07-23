################################################################################
##
##  YOUR QUILL
##
################################################################################

#   Run this script to auto-import vulkan structures to the nicer auto-stype format

import os, sys

DONT    = ['KHR', 'NV', 'EXT', 'QCOM' ]


FILE_ENUM    = []
FILE_STRUCT  = []


with open('/usr/include/vulkan/vulkan_core.h') as f:
    for l in f.readlines():
        l = l.strip()
        if l.startswith('VK_STRUCTURE_TYPE'):
            b = l.split('=')
            FILE_ENUM.append(b[0].strip())
        if l.startswith('typedef struct '):
            b   = l.split(' ');
            FILE_STRUCT.append(b[2])
            
structs = []
            
for e in FILE_ENUM:
    c   = []
    for s in e.split('_'):
        if s not in DONT:
            c.append(s.capitalize())
        else:
            c.append(s)
    k   = ''.join(c[3:])
    vk  = 'Vk' + k
    vq  = 'Vq' + k
    if vk not in FILE_STRUCT:
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

namespace yq {
    namespace engine {""")


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
}
""")
