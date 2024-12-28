////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/interfaces/ISpatial³.hpp>
#include <yq/typedef/tachyon.hpp>
#include <yq/tensor/Tensor44D.hpp>

namespace yq::tachyon {
    
    class ASpatial³ : public ISpatial³ {
    public:
    
    protected:
        TachyonID       m_domain;
        Tensor44D       m_local2Domain   = IDENTITY;
        Tensor44D       m_domain2Local   = IDENTITY
    };

}
