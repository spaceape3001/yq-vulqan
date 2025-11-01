////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Mini.hpp>
#include <yq/tachyon/api/MiniMetaWriter.hpp>
#include <yq/tachyon/api/Accessor.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mini)

namespace yq::tachyon {
    MiniMeta::MiniMeta(std::string_view zName, WidgetMeta& base, const std::source_location& sl) :
        WidgetMeta(zName, base, sl)
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

    void Mini::init_meta()
    {
        auto w = writer<Mini>();
        w.description("Mini widget base class");
    }
}
