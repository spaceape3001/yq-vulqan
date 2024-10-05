////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pixmap2.hpp"
#include <yq-vulqan/pixmap/PixmapInfoWriter.hpp>

namespace yq::tachyon {
    Pixmap2Info::Pixmap2Info(std::string_view szName, const AssetInfo& base, const std::source_location& sl) :
        PixmapInfo(szName, base, sl)
    {
        set(Flags::D2);
        m_dimensionCount    = 2;
    }
}

