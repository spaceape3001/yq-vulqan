////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize¹, SpatialCommand)
    public:
        MultiplyMinSize¹(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMinSize¹();
        MultiplyMinSize¹(const MultiplyMinSize¹&, const Header&);
        MultiplyMinSize¹(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMinSize¹(const MultiplyMinSize¹&) = delete;
        MultiplyMinSize¹(MultiplyMinSize¹&&) = delete;
        MultiplyMinSize¹& operator=(const MultiplyMinSize¹&) = delete;
        MultiplyMinSize¹& operator=(MultiplyMinSize¹&&) = delete;
    };
}
