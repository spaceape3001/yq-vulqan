////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>

namespace yq::tachyon {
    /*! Vertices interface (general base, won't have the actual interface declaration)
    */
    class IVertices {
    public:
        virtual uint8_t     vertices(dimension_k) const = 0;
        virtual size_t      vertices(count_k) const = 0;
        virtual size_t      vertices(maximum_k) const { return SIZE_MAX; }
        virtual size_t      vertices(minimum_k) const { return 0; }
        virtual bool        vertices(appendable_k) const { return false; }
        virtual bool        vertices(disabled_k) const { return false; }
        virtual bool        vertices(insertable_k) const { return false; }
        virtual bool        vertices(settable_k) const { return false; }
        virtual ~IVertices(){}
    };


}
