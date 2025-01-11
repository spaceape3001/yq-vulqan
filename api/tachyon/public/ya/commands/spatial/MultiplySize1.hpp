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
    class MultiplySize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplySize¹, SpatialCommand)
    public:
        MultiplySize¹(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplySize¹();
        MultiplySize¹(const MultiplySize¹&, const Header&);
        MultiplySize¹(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplySize¹(const MultiplySize¹&) = delete;
        MultiplySize¹(MultiplySize¹&&) = delete;
        MultiplySize¹& operator=(const MultiplySize¹&) = delete;
        MultiplySize¹& operator=(MultiplySize¹&&) = delete;
    };
}
