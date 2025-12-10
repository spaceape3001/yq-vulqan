////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplySize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize¹Command, SizeCommand)
    public:
        MultiplySize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplySize¹Command();
        MultiplySize¹Command(const MultiplySize¹Command&, const Header&);
        MultiplySize¹Command(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplySize¹Command(const MultiplySize¹Command&) = delete;
        MultiplySize¹Command(MultiplySize¹Command&&) = delete;
        MultiplySize¹Command& operator=(const MultiplySize¹Command&) = delete;
        MultiplySize¹Command& operator=(MultiplySize¹Command&&) = delete;
    };
}
