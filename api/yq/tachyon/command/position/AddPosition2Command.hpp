////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition²Command : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition²Command, PositionCommand)
    public:
        AddPosition²Command(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition²Command(const AddPosition²Command&, const Header&);
        AddPosition²Command(const Header&);
        ~AddPosition²Command();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        AddPosition²Command(const AddPosition²Command&) = delete;
        AddPosition²Command(AddPosition²Command&&) = delete;
        AddPosition²Command& operator=(const AddPosition²Command&) = delete;
        AddPosition²Command& operator=(AddPosition²Command&&) = delete;
    };
}
