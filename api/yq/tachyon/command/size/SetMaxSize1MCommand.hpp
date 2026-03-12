////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize¹MCommand, SizeCommand)
    public:
        SetMaxSize¹MCommand(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize¹MCommand(const Header&);
        SetMaxSize¹MCommand(const SetMaxSize¹MCommand&, const Header&);
        ~SetMaxSize¹MCommand();

    private:
        Size1M   m_size = ZERO;
        
        SetMaxSize¹MCommand(const SetMaxSize¹MCommand&) = delete;
        SetMaxSize¹MCommand(SetMaxSize¹MCommand&&) = delete;
        SetMaxSize¹MCommand& operator=(const SetMaxSize¹MCommand&) = delete;
        SetMaxSize¹MCommand& operator=(SetMaxSize¹MCommand&&) = delete;
    };
}
