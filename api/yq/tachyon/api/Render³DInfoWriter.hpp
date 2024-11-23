////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Render³D.hpp>
#include <yq/tachyon/api/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Render³DInfo::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Render³DInfo* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_3d();
        }
        
        Writer(Render³DInfo& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
