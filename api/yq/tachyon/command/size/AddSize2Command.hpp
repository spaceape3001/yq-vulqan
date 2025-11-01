////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize²Command, SizeCommand)
    public:
        AddSize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddSize²Command(const AddSize²Command&, const Header&);
        AddSize²Command(const Header&);
        ~AddSize²Command();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddSize²Command(const AddSize²Command&) = delete;
        AddSize²Command(AddSize²Command&&) = delete;
        AddSize²Command& operator=(const AddSize²Command&) = delete;
        AddSize²Command& operator=(AddSize²Command&&) = delete;
    };
}
