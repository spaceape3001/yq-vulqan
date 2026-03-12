////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize¹DCommand, SizeCommand)
    public:
        AddMinSize¹DCommand(const Header&, const Size1D&);
    
        const Size1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMinSize¹DCommand();
        AddMinSize¹DCommand(const AddMinSize¹DCommand&, const Header&);
        AddMinSize¹DCommand(const Header&);

    private:
        Size1D  m_Δ = ZERO;
        
        AddMinSize¹DCommand(const AddMinSize¹DCommand&) = delete;
        AddMinSize¹DCommand(AddMinSize¹DCommand&&) = delete;
        AddMinSize¹DCommand& operator=(const AddMinSize¹DCommand&) = delete;
        AddMinSize¹DCommand& operator=(AddMinSize¹DCommand&&) = delete;
    };
}
