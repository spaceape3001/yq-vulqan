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
    class SetMinSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize¹DCommand, SizeCommand)
    public:
        SetMinSize¹DCommand(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize¹DCommand(const Header&);
        SetMinSize¹DCommand(const SetMinSize¹DCommand&, const Header&);
        ~SetMinSize¹DCommand();

    private:
        Size1D   m_size = ZERO;
        
        SetMinSize¹DCommand(const SetMinSize¹DCommand&) = delete;
        SetMinSize¹DCommand(SetMinSize¹DCommand&&) = delete;
        SetMinSize¹DCommand& operator=(const SetMinSize¹DCommand&) = delete;
        SetMinSize¹DCommand& operator=(SetMinSize¹DCommand&&) = delete;
    };
}
