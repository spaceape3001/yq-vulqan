////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize²Command, SizeCommand)
    public:
        AddMinSize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMinSize²Command(const AddMinSize²Command&, const Header&);
        AddMinSize²Command(const Header&);
        ~AddMinSize²Command();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddMinSize²Command(const AddMinSize²Command&) = delete;
        AddMinSize²Command(AddMinSize²Command&&) = delete;
        AddMinSize²Command& operator=(const AddMinSize²Command&) = delete;
        AddMinSize²Command& operator=(AddMinSize²Command&&) = delete;
    };
}
