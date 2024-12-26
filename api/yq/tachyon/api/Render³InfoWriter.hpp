////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Render³.hpp>
#include <yq/tachyon/api/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Render³Info::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Render³Info* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_3d();
        }
        
        Writer(Render³Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
