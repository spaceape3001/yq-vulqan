////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition⁴DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition⁴DCommand, PositionCommand)
    public:
        AddPosition⁴DCommand(const Header&, const Vector4D&Δ);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition⁴DCommand(const AddPosition⁴DCommand&, const Header&);
        AddPosition⁴DCommand(const Header&);
        ~AddPosition⁴DCommand();
        
    private:
        Vector4D  m_Δ = ZERO;
        
        AddPosition⁴DCommand(const AddPosition⁴DCommand&) = delete;
        AddPosition⁴DCommand(AddPosition⁴DCommand&&) = delete;
        AddPosition⁴DCommand& operator=(const AddPosition⁴DCommand&) = delete;
        AddPosition⁴DCommand& operator=(AddPosition⁴DCommand&&) = delete;
    };
}
