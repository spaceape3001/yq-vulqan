////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/rendered/AbstractShape3.hpp>

namespace yq::tachyon {
    template <size_t N>
    class FixedShape3 : public AbstractShape3 {
    public:
    
        FixedShape3(std::initializer_list<Vertex3>, const Param&p={});
        
    
    private:
        std::array<Vertex3>     m_vertices;
    };
    
};
