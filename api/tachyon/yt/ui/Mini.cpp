////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/ui/Mini.hpp>
#include <yt/ui/MiniInfoWriter.hpp>
#include <yt/api/Accessor.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mini)

namespace yq::tachyon {
    MiniInfo::MiniInfo(std::string_view zName, WidgetInfo& base, const std::source_location& sl) :
        WidgetInfo(zName, base, sl)
    {
    }

    Mini::Mini() : Widget()
    {
    }
    
    Mini::~Mini()
    {
    }
    
    Accessor*       Mini::accessor()
    {
        return m_accessor.get();
    }
    
    const Accessor* Mini::accessor() const
    {
        return m_accessor.get();
    }

    void Mini::accessor(set_k, AccessorUPtr&&mv)
    {
        m_accessor  = std::move(mv);
    }

    void Mini::init_info()
    {
        auto w = writer<Mini>();
        w.description("Mini widget base class");
    }
}
