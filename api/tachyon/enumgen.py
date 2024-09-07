#!/usr/bin/python

################################################################################
##
##  YOUR QUILL
##
################################################################################

#   Run this script to auto-import vulkan enumerations to our types

import os, sys

with open('/usr/include/vulkan/vulkan_core.h') as f:
    for l in f.readlines():
        l = l.strip()
        


