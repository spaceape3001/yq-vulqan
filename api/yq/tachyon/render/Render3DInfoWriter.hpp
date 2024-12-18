////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/render/Render3D.hpp>
#include <yq/tachyon/render/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Render3DInfo::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Render3DInfo* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_3d();
        }
        
        Writer(Render3DInfo& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
