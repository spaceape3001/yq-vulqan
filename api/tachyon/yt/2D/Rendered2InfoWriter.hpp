////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox2.hpp>
#include <yt/2D/Rendered2.hpp>
#include <yt/2D/Rendered2Data.hpp>
#include <yt/scene/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered²Info::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Rendered²Info* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_2d();
        }
        
        Writer(Rendered²Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
