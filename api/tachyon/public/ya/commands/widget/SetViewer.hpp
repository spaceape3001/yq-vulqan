////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WidgetCommand.hpp>
#include <yt/api/TypedID.hpp>

namespace yq::tachyon {
    class SetViewer : public WidgetCommand {
        YQ_OBJECT_DECLARE(SetViewer, WidgetCommand)
    public:
        SetViewer(const Header&, TypedID);
        
        TypedID  viewer() const { return m_viewer; }
        
        static void init_info();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetViewer(const SetViewer&, const Header&);
        ~SetViewer();
    private:
        TypedID     m_viewer;
        
        SetViewer(const SetViewer&) = delete;
        SetViewer(SetViewer&&) = delete;
        SetViewer& operator=(const SetViewer&) = delete;
        SetViewer& operator=(SetViewer&&) = delete;
    };
}
