////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize³MCommand, SizeCommand)
    public:
        SetMaxSize³MCommand(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize³MCommand(const Header&);
        SetMaxSize³MCommand(const SetMaxSize³MCommand&, const Header&);
        ~SetMaxSize³MCommand();

    private:
        Size3M   m_size = ZERO;
        
        SetMaxSize³MCommand(const SetMaxSize³MCommand&) = delete;
        SetMaxSize³MCommand(SetMaxSize³MCommand&&) = delete;
        SetMaxSize³MCommand& operator=(const SetMaxSize³MCommand&) = delete;
        SetMaxSize³MCommand& operator=(SetMaxSize³MCommand&&) = delete;
    };
}
