////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox2.hpp>
#include <yq/tachyon/api/Rendered2.hpp>
#include <yq/tachyon/api/Rendered2Data.hpp>
#include <yq/tachyon/api/RenderedMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered²Meta::Writer : public RenderedMeta::Writer<C> {
    public:
        Writer(Rendered²Meta* renderInfo) : RenderedMeta::Writer<C>(renderInfo)
        {
            RenderedMeta::Writer<C>::_2d();
        }
        
        Writer(Rendered²Meta& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
