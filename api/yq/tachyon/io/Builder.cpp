////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Builder.hpp"

namespace yq::tachyon {
    Builder::Builder(Builder* parent) : m_parent(parent)
    {
        if(m_parent)
            m_parent -> m_children.push_back(this);
    }
    
    Builder::~Builder()
    {
    }
}
