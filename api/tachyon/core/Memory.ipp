////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/core/Memory.hpp>

namespace yq::tachyon {

    Memory::Memory() = default;

    Memory::Memory(Memory&& mv) : 
        m_data(mv.m_data), m_size(mv.m_size), m_free(std::move(mv.m_free))
    {
        mv.m_data       = nullptr;
        mv.m_size       = 0;
        mv.m_free       = {};
    }

    Memory::Memory(const void* d, size_t n, Free free) : m_data(d), m_size(n), m_free(free) {}
    
    Memory::~Memory()
    {
        clear();
    }
    
    void Memory::clear()
    {
        if(m_data){
            if(m_free)
                m_free(m_data, m_size);
            m_data      = nullptr;
            m_size      = 0ULL;
            m_free      = {};
        }
    }

    void    Memory::set(const void* p, size_t n, Free f)
    {
        clear();
        if(p && n){
            m_data  = p;
            m_size  = n;
            m_free  = f;
        }
    }
}
        
