////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition¹Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition¹Command, PositionCommand)
    public:
        MultiplyPosition¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyPosition¹Command();
        MultiplyPosition¹Command(const MultiplyPosition¹Command&, const Header&);
        MultiplyPosition¹Command(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyPosition¹Command(const MultiplyPosition¹Command&) = delete;
        MultiplyPosition¹Command(MultiplyPosition¹Command&&) = delete;
        MultiplyPosition¹Command& operator=(const MultiplyPosition¹Command&) = delete;
        MultiplyPosition¹Command& operator=(MultiplyPosition¹Command&&) = delete;
    };
}
