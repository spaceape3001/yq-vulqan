////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/AppCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class ViewerCreateCommand : public AppCommand {
        YQ_OBJECT_DECLARE(ViewerCreateCommand, AppCommand)
    public:
        ViewerCreateCommand(const Header&, const ViewerCreateInfo&, WidgetPtr);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const WidgetPtr&            widget() const { return m_widget; }
        const ViewerCreateInfo&     create_info() const { return m_createInfo; }

    protected:
        ViewerCreateCommand(const ViewerCreateCommand&, const Header&);
        virtual ~ViewerCreateCommand();
        
    private:
    
        ViewerCreateInfo        m_createInfo;
        WidgetPtr               m_widget;

        ViewerCreateCommand(const ViewerCreateCommand&) = delete;
        ViewerCreateCommand(ViewerCreateCommand&&) = delete;
        ViewerCreateCommand& operator=(const ViewerCreateCommand&) = delete;
        ViewerCreateCommand& operator=(ViewerCreateCommand&&) = delete;
    };
}
