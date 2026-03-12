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
    class AddSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize¹DCommand, SizeCommand)
    public:
        AddSize¹DCommand(const Header&, const Size1D&);
    
        const Size1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddSize¹DCommand();
        AddSize¹DCommand(const AddSize¹DCommand&, const Header&);
        AddSize¹DCommand(const Header&);

    private:
        Size1D  m_Δ = ZERO;
        
        AddSize¹DCommand(const AddSize¹DCommand&) = delete;
        AddSize¹DCommand(AddSize¹DCommand&&) = delete;
        AddSize¹DCommand& operator=(const AddSize¹DCommand&) = delete;
        AddSize¹DCommand& operator=(AddSize¹DCommand&&) = delete;
    };
}
