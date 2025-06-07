////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize¹Command, SizeCommand)
    public:
        MultiplyMinSize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMinSize¹Command();
        MultiplyMinSize¹Command(const MultiplyMinSize¹Command&, const Header&);
        MultiplyMinSize¹Command(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMinSize¹Command(const MultiplyMinSize¹Command&) = delete;
        MultiplyMinSize¹Command(MultiplyMinSize¹Command&&) = delete;
        MultiplyMinSize¹Command& operator=(const MultiplyMinSize¹Command&) = delete;
        MultiplyMinSize¹Command& operator=(MultiplyMinSize¹Command&&) = delete;
    };
}
