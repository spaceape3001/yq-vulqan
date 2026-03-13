////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale¹DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale¹DCommand, ScaleCommand)
    public:
        AddScale¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddScale¹DCommand();
        AddScale¹DCommand(const AddScale¹DCommand&, const Header&);
        AddScale¹DCommand(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddScale¹DCommand(const AddScale¹DCommand&) = delete;
        AddScale¹DCommand(AddScale¹DCommand&&) = delete;
        AddScale¹DCommand& operator=(const AddScale¹DCommand&) = delete;
        AddScale¹DCommand& operator=(AddScale¹DCommand&&) = delete;
    };
}
