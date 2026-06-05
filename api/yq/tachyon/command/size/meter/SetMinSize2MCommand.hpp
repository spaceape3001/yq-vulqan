////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize²MCommand, SizeCommand)
    public:
        SetMinSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize²MCommand(const Header&);
        SetMinSize²MCommand(const SetMinSize²MCommand&, const Header&);
        ~SetMinSize²MCommand();

    private:
        Size2M   m_size = ZERO;
        
        SetMinSize²MCommand(const SetMinSize²MCommand&) = delete;
        SetMinSize²MCommand(SetMinSize²MCommand&&) = delete;
        SetMinSize²MCommand& operator=(const SetMinSize²MCommand&) = delete;
        SetMinSize²MCommand& operator=(SetMinSize²MCommand&&) = delete;
    };
}
