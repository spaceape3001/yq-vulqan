////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition⁴ : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition⁴, PositionCommand)
    public:
        AddPosition⁴(const Header&, const Vector4D&Δ);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition⁴(const AddPosition⁴&, const Header&);
        AddPosition⁴(const Header&);
        ~AddPosition⁴();
        
    private:
        Vector4D  m_Δ = ZERO;
        
        AddPosition⁴(const AddPosition⁴&) = delete;
        AddPosition⁴(AddPosition⁴&&) = delete;
        AddPosition⁴& operator=(const AddPosition⁴&) = delete;
        AddPosition⁴& operator=(AddPosition⁴&&) = delete;
    };
}
