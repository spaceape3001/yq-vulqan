////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize¹MCommand, SizeCommand)
    public:
        SetMinSize¹MCommand(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize¹MCommand(const Header&);
        SetMinSize¹MCommand(const SetMinSize¹MCommand&, const Header&);
        ~SetMinSize¹MCommand();

    private:
        Size1M   m_size = ZERO;
        
        SetMinSize¹MCommand(const SetMinSize¹MCommand&) = delete;
        SetMinSize¹MCommand(SetMinSize¹MCommand&&) = delete;
        SetMinSize¹MCommand& operator=(const SetMinSize¹MCommand&) = delete;
        SetMinSize¹MCommand& operator=(SetMinSize¹MCommand&&) = delete;
    };
}
