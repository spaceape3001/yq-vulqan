////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered3Info::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Rendered3Info* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_3d();
        }
        
        Writer(Rendered3Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
