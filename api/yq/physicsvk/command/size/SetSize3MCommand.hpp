////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize³MCommand, SizeCommand)
    public:
        SetSize³MCommand(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize³MCommand(const Header&);
        SetSize³MCommand(const SetSize³MCommand&, const Header&);
        ~SetSize³MCommand();

    private:
        Size3M   m_size = ZERO;
        
        SetSize³MCommand(const SetSize³MCommand&) = delete;
        SetSize³MCommand(SetSize³MCommand&&) = delete;
        SetSize³MCommand& operator=(const SetSize³MCommand&) = delete;
        SetSize³MCommand& operator=(SetSize³MCommand&&) = delete;
    };
}
