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
    class SetSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize¹DCommand, SizeCommand)
    public:
        SetSize¹DCommand(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize¹DCommand(const Header&);
        SetSize¹DCommand(const SetSize¹DCommand&, const Header&);
        ~SetSize¹DCommand();

    private:
        Size1D   m_size = ZERO;
        
        SetSize¹DCommand(const SetSize¹DCommand&) = delete;
        SetSize¹DCommand(SetSize¹DCommand&&) = delete;
        SetSize¹DCommand& operator=(const SetSize¹DCommand&) = delete;
        SetSize¹DCommand& operator=(SetSize¹DCommand&&) = delete;
    };
}
