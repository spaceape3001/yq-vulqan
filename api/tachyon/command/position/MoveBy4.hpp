////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy⁴ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy⁴, PositionCommand)
    public:
        MoveBy⁴(const Header&, const Vector4D&Δ);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy⁴(const MoveBy⁴&, const Header&);
        MoveBy⁴(const Header&);
        ~MoveBy⁴();
        
    private:
        Vector4D  m_Δ = ZERO;
        
        MoveBy⁴(const MoveBy⁴&) = delete;
        MoveBy⁴(MoveBy⁴&&) = delete;
        MoveBy⁴& operator=(const MoveBy⁴&) = delete;
        MoveBy⁴& operator=(MoveBy⁴&&) = delete;
    };
}
