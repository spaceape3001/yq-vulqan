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
    class SetMaxSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize¹DCommand, SizeCommand)
    public:
        SetMaxSize¹DCommand(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize¹DCommand(const Header&);
        SetMaxSize¹DCommand(const SetMaxSize¹DCommand&, const Header&);
        ~SetMaxSize¹DCommand();

    private:
        Size1D   m_size = ZERO;
        
        SetMaxSize¹DCommand(const SetMaxSize¹DCommand&) = delete;
        SetMaxSize¹DCommand(SetMaxSize¹DCommand&&) = delete;
        SetMaxSize¹DCommand& operator=(const SetMaxSize¹DCommand&) = delete;
        SetMaxSize¹DCommand& operator=(SetMaxSize¹DCommand&&) = delete;
    };
}
