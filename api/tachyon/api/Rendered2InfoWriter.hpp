////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox2.hpp>
#include <tachyon/api/Rendered2.hpp>
#include <tachyon/api/Rendered2Data.hpp>
#include <tachyon/api/RenderedMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered²Info::Writer : public RenderedMeta::Writer<C> {
    public:
        Writer(Rendered²Info* renderInfo) : RenderedMeta::Writer<C>(renderInfo)
        {
            RenderedMeta::Writer<C>::_2d();
        }
        
        Writer(Rendered²Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
