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
    class SetMaxSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize²MCommand, SizeCommand)
    public:
        SetMaxSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize²MCommand(const Header&);
        SetMaxSize²MCommand(const SetMaxSize²MCommand&, const Header&);
        ~SetMaxSize²MCommand();

    private:
        Size2M   m_size = ZERO;
        
        SetMaxSize²MCommand(const SetMaxSize²MCommand&) = delete;
        SetMaxSize²MCommand(SetMaxSize²MCommand&&) = delete;
        SetMaxSize²MCommand& operator=(const SetMaxSize²MCommand&) = delete;
        SetMaxSize²MCommand& operator=(SetMaxSize²MCommand&&) = delete;
    };
}
