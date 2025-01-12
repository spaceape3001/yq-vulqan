////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize² : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize², SpatialCommand)
    public:
        MultiplyMinSize²(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyMinSize²(const MultiplyMinSize²&, const Header&);
        MultiplyMinSize²(const Header&);
        ~MultiplyMinSize²();

    private:
        Vector2D  m_δ;
        
        MultiplyMinSize²(const MultiplyMinSize²&) = delete;
        MultiplyMinSize²(MultiplyMinSize²&&) = delete;
        MultiplyMinSize²& operator=(const MultiplyMinSize²&) = delete;
        MultiplyMinSize²& operator=(MultiplyMinSize²&&) = delete;
    };
}
