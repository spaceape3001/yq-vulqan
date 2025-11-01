////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIDock.hpp"
#include "UIDockWriter.hpp"
#include <tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIDock)

namespace yq::tachyon {
    UIDock::UIDock(std::string_view title, UIFlags flags) : UIWindow(title, flags)
    {
    }

    UIDock::UIDock(const UIDock&cp) : UIWindow(cp)
    {
    }
    
    UIDock* UIDock::clone() const 
    {
        return new UIDock(*this);
    }
    
    void UIDock::init_meta()
    {
        auto w = writer<UIDock>();
        w.description("Docking UI Element");
    }


    ////////////////////////////
    
    UIDockWriter::UIDockWriter() = default;
    UIDockWriter::UIDockWriter(const UIDockWriter&) = default;
    UIDockWriter::~UIDockWriter() = default;
    
    UIDock* UIDockWriter::element()
    {
        return dynamic_cast<UIDock*>(m_ui);
    }
    
    UIDockWriter::UIDockWriter(UIDock* ui) : UIWindowWriter(ui)
    {
    }
}
