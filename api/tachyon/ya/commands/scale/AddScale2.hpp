////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale² : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale², ScaleCommand)
    public:
        AddScale²(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddScale²(const AddScale²&, const Header&);
        AddScale²(const Header&);
        ~AddScale²();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddScale²(const AddScale²&) = delete;
        AddScale²(AddScale²&&) = delete;
        AddScale²& operator=(const AddScale²&) = delete;
        AddScale²& operator=(AddScale²&&) = delete;
    };
}
