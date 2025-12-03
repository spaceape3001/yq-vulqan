////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Builder.hpp"
#include <yq/errors.hpp>

namespace yq::tachyon {
    Builder::Builder(Save*s) : m_save(s)
    {
    }
    
    Builder::~Builder()
    {
    }

#if 0
    std::error_code Builder::load1_create(LoadAPI&) const
    {
        return {};
    }
    
    std::error_code Builder::load2_configure(LoadAPI&) const
    {
        return {};
    }
#endif
}
