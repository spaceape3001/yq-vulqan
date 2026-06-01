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
    class SetSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize²MCommand, SizeCommand)
    public:
        SetSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize²MCommand(const Header&);
        SetSize²MCommand(const SetSize²MCommand&, const Header&);
        ~SetSize²MCommand();

    private:
        Size2M   m_size = ZERO;
        
        SetSize²MCommand(const SetSize²MCommand&) = delete;
        SetSize²MCommand(SetSize²MCommand&&) = delete;
        SetSize²MCommand& operator=(const SetSize²MCommand&) = delete;
        SetSize²MCommand& operator=(SetSize²MCommand&&) = delete;
    };
}
