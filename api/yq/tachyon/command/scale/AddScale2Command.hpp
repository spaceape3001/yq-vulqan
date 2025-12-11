////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale²Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale²Command, ScaleCommand)
    public:
        AddScale²Command(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddScale²Command(const AddScale²Command&, const Header&);
        AddScale²Command(const Header&);
        ~AddScale²Command();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddScale²Command(const AddScale²Command&) = delete;
        AddScale²Command(AddScale²Command&&) = delete;
        AddScale²Command& operator=(const AddScale²Command&) = delete;
        AddScale²Command& operator=(AddScale²Command&&) = delete;
    };
}
