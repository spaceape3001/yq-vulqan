////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition² : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddPosition², SpatialCommand)
    public:
        AddPosition²(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition²(const AddPosition²&, const Header&);
        AddPosition²(const Header&);
        ~AddPosition²();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        AddPosition²(const AddPosition²&) = delete;
        AddPosition²(AddPosition²&&) = delete;
        AddPosition²& operator=(const AddPosition²&) = delete;
        AddPosition²& operator=(AddPosition²&&) = delete;
    };
}
