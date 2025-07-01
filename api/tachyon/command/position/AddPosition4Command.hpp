////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition⁴Command : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition⁴Command, PositionCommand)
    public:
        AddPosition⁴Command(const Header&, const Vector4D&Δ);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition⁴Command(const AddPosition⁴Command&, const Header&);
        AddPosition⁴Command(const Header&);
        ~AddPosition⁴Command();
        
    private:
        Vector4D  m_Δ = ZERO;
        
        AddPosition⁴Command(const AddPosition⁴Command&) = delete;
        AddPosition⁴Command(AddPosition⁴Command&&) = delete;
        AddPosition⁴Command& operator=(const AddPosition⁴Command&) = delete;
        AddPosition⁴Command& operator=(AddPosition⁴Command&&) = delete;
    };
}
