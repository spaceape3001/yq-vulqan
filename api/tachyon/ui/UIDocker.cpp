////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIDocker.hpp"
#include "UIDockerWriter.hpp"
#include <tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIDocker)

namespace yq::tachyon {
    UIDocker::UIDocker(std::string_view title, UIFlags flags) : UIWindow(title, flags | UIFlag::NoTitleBar)
    {
    }

    UIDocker::UIDocker(const UIDocker&cp) : UIWindow(cp)
    {
    }
    
    UIDocker* UIDocker::clone() const 
    {
        return new UIDocker(*this);
    }
    
    void UIDocker::init_info()
    {
        auto w = writer<UIDocker>();
        w.description("Dockering UI Element");
    }


    ////////////////////////////
    
    UIDockerWriter::UIDockerWriter() = default;
    UIDockerWriter::UIDockerWriter(const UIDockerWriter&) = default;
    UIDockerWriter::~UIDockerWriter() = default;
    
    UIDocker* UIDockerWriter::element()
    {
        return dynamic_cast<UIDocker*>(m_ui);
    }
    
    UIDockerWriter::UIDockerWriter(UIDocker* ui) : UIWindowWriter(ui)
    {
    }
}
