////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/api/Rendered³.hpp>
#include <yq/tachyon/api/Rendered³Data.hpp>
#include <yq/tachyon/api/RenderedInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Rendered³Info::Writer : public RenderedInfo::Writer<C> {
    public:
        Writer(Rendered³Info* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
        {
            RenderedInfo::Writer<C>::_3d();
        }
        
        Writer(Rendered³Info& renderInfo) : Writer(&renderInfo)
        {
        }
    };
}
