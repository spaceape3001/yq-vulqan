////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy⁴Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy⁴Command, PositionCommand)
    public:
        MoveBy⁴Command(const Header&, const Vector4D&Δ);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy⁴Command(const MoveBy⁴Command&, const Header&);
        MoveBy⁴Command(const Header&);
        ~MoveBy⁴Command();
        
    private:
        Vector4D  m_Δ = ZERO;
        
        MoveBy⁴Command(const MoveBy⁴Command&) = delete;
        MoveBy⁴Command(MoveBy⁴Command&&) = delete;
        MoveBy⁴Command& operator=(const MoveBy⁴Command&) = delete;
        MoveBy⁴Command& operator=(MoveBy⁴Command&&) = delete;
    };
}
