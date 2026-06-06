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
    class SetMinSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize³MCommand, SizeCommand)
    public:
        SetMinSize³MCommand(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize³MCommand(const Header&);
        SetMinSize³MCommand(const SetMinSize³MCommand&, const Header&);
        ~SetMinSize³MCommand();

    private:
        Size3M   m_size = ZERO;
        
        SetMinSize³MCommand(const SetMinSize³MCommand&) = delete;
        SetMinSize³MCommand(SetMinSize³MCommand&&) = delete;
        SetMinSize³MCommand& operator=(const SetMinSize³MCommand&) = delete;
        SetMinSize³MCommand& operator=(SetMinSize³MCommand&&) = delete;
    };
}
