////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Render3D.hpp>
#include <tachyon/scene/RenderedWriter.hpp>

namespace yq {
    namespace tachyon {
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
}

