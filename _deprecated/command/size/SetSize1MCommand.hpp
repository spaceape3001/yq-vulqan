////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize¹MCommand, SizeCommand)
    public:
        SetSize¹MCommand(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize¹MCommand(const Header&);
        SetSize¹MCommand(const SetSize¹MCommand&, const Header&);
        ~SetSize¹MCommand();

    private:
        Size1M   m_size = ZERO;
        
        SetSize¹MCommand(const SetSize¹MCommand&) = delete;
        SetSize¹MCommand(SetSize¹MCommand&&) = delete;
        SetSize¹MCommand& operator=(const SetSize¹MCommand&) = delete;
        SetSize¹MCommand& operator=(SetSize¹MCommand&&) = delete;
    };
}
