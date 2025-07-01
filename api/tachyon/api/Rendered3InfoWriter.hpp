////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Rendered3Data.hpp>
#include <tachyon/api/RenderedMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered³Info::Writer : public RenderedMeta::Writer<C> {
    public:
        Writer(Rendered³Info* renderInfo) : RenderedMeta::Writer<C>(renderInfo)
        {
            RenderedMeta::Writer<C>::_3d();
        }
        
        Writer(Rendered³Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
